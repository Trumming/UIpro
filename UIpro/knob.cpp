#include "stdafx.h"
#include "knob.h"
#include "resource.h"
#include "math.h"
#include "CMImage.h"

knob::knob(void)
{
	m_val = 0;
	m_bActive = false;
	m_bFreshScale = true;
}

knob::~knob(void)
{
	m_bFreshScale = false;
}

BEGIN_MESSAGE_MAP(knob, CStatic)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void knob::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect   rect;   
	GetClientRect(&rect);   
	CDC   dcMem;   
	dcMem.CreateCompatibleDC(&dc);  

	CBitmap   bmpBackground;   
	if(m_bFreshScale)
	{
#if 0
		switch (m_val)
		{
		case 0: bmpBackground.LoadBitmap(IDB_KNOB0); break;
		case 1: bmpBackground.LoadBitmap(IDB_KNOB1); break;
		case 2: bmpBackground.LoadBitmap(IDB_KNOB2); break;
		case 3: bmpBackground.LoadBitmap(IDB_KNOB3); break;
		case 4: bmpBackground.LoadBitmap(IDB_KNOB4); break;
		case 5: bmpBackground.LoadBitmap(IDB_KNOB5); break;
		case 6: bmpBackground.LoadBitmap(IDB_KNOB6); break;
		case 7: bmpBackground.LoadBitmap(IDB_KNOB7); break;
		case 8: bmpBackground.LoadBitmap(IDB_KNOB8); break;
		case 9: bmpBackground.LoadBitmap(IDB_KNOB9); break;
		case 10: bmpBackground.LoadBitmap(IDB_KNOB10); break;
		default: bmpBackground.LoadBitmap(IDB_KNOB0); break;
		}
#else
		bmpBackground.LoadBitmap(IDB_SCALE);
#endif
		//IDB_BITMAP是你自己的图对应的ID 
		BITMAP   bitmap;   
		bmpBackground.GetBitmap(&bitmap);   
		CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
		// Do not call CDialog::OnPaint() for painting messages  
	}

	CDC *pDC(GetDC());
	CMImage scale,rotateImage;

	//GetClientRect(&rect);
	//CBrush br(RGB(224,228,229));            
	//pDC->FillRect(rect,&br);									// 填充红色背景色

	if(scale.LoadImageFromResource(IDB_KNOBER,_T("PNG")))
	{
		scale.TransparentPNG();
		//scale.Draw(dcMem.m_hDC,0,0,scale.GetWidth(),scale.GetHeight(),0,0,scale.GetWidth(),scale.GetHeight());
		scale.RotateImage(&rotateImage,(50-m_val)*2.2f);
		//scale.Draw(pDC->m_hDC,rect);

		rotateImage.Draw(pDC->m_hDC, 15, 15);					// 将旋转后的图像rotateImage，贴在SCALE背景上		
	}
	else
		MessageBox(_T(" knob::OnPaint() , Image Error"));							// 图片加载失败

	rotateImage.ReleaseDC();
	rotateImage.Destroy();  
}
/* @brief 目前效率最高的求 1/sqrt(x) 函数
*/
static float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating VALUE 
	i = 0x5f375a86- (i>>1); // gives initial guess y0
	x = *(float*)&i; // convert bits BACK to float
	x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
	return x;
}  

void knob::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int m_r;
	int x,y;//旋钮圆心
	x = 60;
	y = 60;

#if 0
	//m_r = (int)sqrt((long double)(((x-point.x)*(x-point.x)+(y-point.y)*(y-point.y))));
#else
	x -= point.x;
	y -= point.y;
	float fR_r = InvSqrt((float)(x*x +y*y)); // 半径倒数 1/R
	m_r = (int)(1.0f/fR_r);
#endif	
	
	if ((m_r > 48)||(m_r <10)) return;

	this->m_bActive = true;

#if 0
	double  d;//h弧度
	double  m;//化成角度了
	if((point.x < x)&&(point.y <= y))
	{
		d=acos(((double)(x-point.x))/((double)m_r));//h弧度
		m=(d*360)/(2*3.14) + 23;//化成角度了
	}	
	else if((point.x < x)&&(point.y > y))
	{
		d=acos(((double)(x-point.x))/((double)m_r));//h弧度
		m= 23 - (d*360)/(2*3.14);//化成角度了
	}
	else if((point.x > x)&&(point.y <= y))
	{
		d=acos(((double)(point.x-x))/((double)m_r));//h弧度
		m=23 + 180 - (d*360)/(2*3.14);//化成角度了
	}
	else
	{
		d=acos(((double)(point.x-x))/((double)m_r));//h弧度
		m=23 + 180 + (d*360)/(2*3.14);//化成角度了
	}

	if((m> -10)&&(m < 12))
		m_val = 0;
	else if((m> 13)&&(m < 35))
		m_val = 1;
	else if((m> 36)&&(m < 58))
		m_val = 2;
	else if((m> 59)&&(m < 81))
		m_val = 3;
	else if((m> 82)&&(m < 104))
		m_val = 4;
	else if((m> 105)&&(m < 127))
		m_val = 5;
	else if((m> 128)&&(m < 150))
		m_val = 6;
	else if((m> 151)&&(m < 173))
		m_val = 7;
	else if((m> 174)&&(m < 196))
		m_val = 8;
	else if((m> 197)&&(m < 219))
		m_val = 9;
	else if((m> 220)&&(m < 242))
		m_val = 10;

	OnPaint();
	Invalidate(TRUE); 
#endif
	//CString a;
	//a.Format(_T("x %d y %d rx1 %d ry1  %d  r  %d  m %f"),point.x,point.y,x,y,m_r,m);
	//AfxMessageBox(a,1,0);
}

void knob::OnLButtonUp(UINT nFlags, CPoint point) 
{
	this->m_bActive = false;
	m_bFreshScale = true;
}

void knob::OnMouseMove(UINT uParam,CPoint point)
{		
	int m_r;
	int x,y;//旋钮圆心
	x = 60;
	y = 60;
	
#if 0
	//m_r = (int)sqrt((long double)(((x-point.x)*(x-point.x)+(y-point.y)*(y-point.y))));
#else
	float fR_r = InvSqrt((float)((x-point.x)*(x-point.x)+(y-point.y)*(y-point.y))); // 半径倒数 1/R
	m_r = (int)(1.0f/fR_r);
#endif

	if ((m_r > 48)||(m_r <10)) return;

	if(isActive())
	{
		m_bFreshScale = false;
		double  d;//h弧度
		double  m;//化成角度了
		if((point.x < x)&&(point.y <= y))
		{
			d=acos(((double)(x-point.x))*((double)fR_r));//h弧度
			m=(d*360)/(2*3.1415926) + 30;//化成角度了
		}	
		else if((point.x < x)&&(point.y > y))
		{
			d=acos(((double)(x-point.x))*((double)fR_r));//h弧度
			m= 30 - (d*360)/(2*3.1415926);//化成角度了
		}
		else if((point.x >= x)&&(point.y <= y))
		{
			d=acos(((double)(point.x-x))*((double)fR_r));//h弧度
			m=30 + 180 - (d*360)/(2*3.1415926);//化成角度了
		}
		else
		{
			d=acos(((double)(point.x-x))*((double)fR_r));//h弧度
			m=30 + 180 + (d*360)/(2*3.1415926);//化成角度了
		}
#if 0
		if((m> -10)&&(m < 12))
			m_val = 0;
		else if((m> 13)&&(m < 35))
			m_val = 1;
		else if((m> 36)&&(m < 58))
			m_val = 2;
		else if((m> 59)&&(m < 81))
			m_val = 3;
		else if((m> 82)&&(m < 104))
			m_val = 4;
		else if((m> 105)&&(m < 127))
			m_val = 5;
		else if((m> 128)&&(m < 150))
			m_val = 6;
		else if((m> 151)&&(m < 173))
			m_val = 7;
		else if((m> 174)&&(m < 196))
			m_val = 8;
		else if((m> 197)&&(m < 219))
			m_val = 9;
		else if((m> 220)&&(m < 242))
			m_val = 10;
#else
		if(m >=220)	m = 220;
		if(m < 0)	m = 0;
			
		m_val = (int)(m*10)/22;
#endif
		OnPaint();
		Invalidate(TRUE); 
	}
}

bool knob::isActive( void )
{
	return this->m_bActive;
}
