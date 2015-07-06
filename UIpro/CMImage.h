#include"atlimage.h"

#pragma once

class CMImage: public CImage
{
public:
	CMImage();
public:
	~CMImage();

public:
	bool LoadImageFromResource(/*IN CImage* pImage, */IN UINT nResID, IN LPCWSTR lpTyp);
	void TransparentPNG(/*CImage *png*/void);
	void RotateImage(CImage *dest,float fAngle );
};