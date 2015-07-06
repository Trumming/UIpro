#pragma once
#include "memdc.h" // "Flicker Free Drawing In MFC" by Keith Rule
class CSlider :
	public CStatic
{
public:
	CSlider(void);
public:
	~CSlider(void);
	void SetBitmapIndex(UINT m_nBitmapIndex);

public:
	bool IsActive(){return m_bIsActive;}
	afx_msg void OnPaint();

protected:
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()

private:
	UINT m_nBitmapIndex; // Bitmap index of resource

public:
	bool m_bIsActive;
	int x;
	int y;
};
