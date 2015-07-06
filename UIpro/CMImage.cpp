#include "stdafx.h"
#include "CMImage.h"

CMImage::CMImage()
{

}

CMImage::~CMImage()
{
	this->ReleaseDC();
	this->Destroy();
}

bool CMImage::LoadImageFromResource(/*IN CImage* pImage, */IN UINT nResID, IN LPCWSTR lpTyp)
{
	//if (pImage == NULL) return false;
	//pImage->Destroy();

	// 查找资源
	HRSRC hRsrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL) 
		return false;

	// 加载资源
	HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}
	
	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);
	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);
	
	// 解除内存中的指定资源
	::GlobalUnlock(hNew);

	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
	if (ht != S_OK)
	{
		GlobalFree(hNew);
	}
	else
	{
		// 加载图片
		/*pImage->Load(pStream);*/
		this->Load(pStream);
		GlobalFree(hNew);
	}
	// 释放资源
	::FreeResource(hImgData);
	return true;
}

//@brief 处理透明通道信息
void CMImage::TransparentPNG(/*CImage *png*/void)
{
	int width = this->GetWidth();
	int height = this->GetHeight();
	if (this->GetBPP() == 32) //确认该图像包含Alpha通道
	{
		for (int i = 0; i < width; i++){
			for (int j = 0; j < height; j++){
				unsigned char* pucColor = reinterpret_cast<unsigned char*>(this->GetPixelAddress(i, j));
				//pucColor[0] = (pucColor[0] * pucColor[3]) / 255;
				//pucColor[1] = (pucColor[1] * pucColor[3]) / 255;
				//pucColor[2] = (pucColor[2] * pucColor[3]) / 255;
				pucColor[0] = (pucColor[0] * pucColor[3]) >> 8;		//和上面结果差别不大，为了运算速度，用移位操作
				pucColor[1] = (pucColor[1] * pucColor[3]) >> 8;
				pucColor[2] = (pucColor[2] * pucColor[3]) >> 8;
			}
		}
	}
}

//@brief 旋转图像
void CMImage::RotateImage(CImage *dest,float fAngle )
{
	int srcWidth = this->GetWidth();
	int srcHeight = this->GetHeight();

	long srcx=0;
	long srcy=0;
	int rx0 = srcWidth>>1;
	int ry0 = srcHeight>>1;

	//CImage dest;
	dest->Create(srcWidth,srcHeight,32,CImage::createAlphaChannel);   // 长宽为256px，透明通道为32bpp

	fAngle = fAngle*3.1415926f/180.0f;
	for (int i = 0; i < srcWidth; i++){
		for (int j = 0; j < srcHeight; j++){
			srcx = (long)(rx0 + (i - rx0) * cos(fAngle) - (j - ry0) * sin(fAngle));
			srcy = (long)(ry0 + (j - ry0) * cos(fAngle) + (i - rx0) * sin(fAngle));

			if(srcx < 0 || srcy < 0 || srcx >= srcWidth || srcy >= srcHeight)
				continue;
			else
			{
				unsigned char* srcPucColor = reinterpret_cast<unsigned char*>(this->GetPixelAddress(srcx,srcy));
				unsigned char* destPucColor = reinterpret_cast<unsigned char*>(dest->GetPixelAddress(i,j));
				for(BYTE index = 0;index < 4;index++)
					destPucColor[index] = srcPucColor[index];
			}
		}
	}
}