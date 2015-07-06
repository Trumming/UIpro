#include "stdafx.h"
#include "Slider.h"
#include "UIpro.h"

CSlider::CSlider(void)
{
	m_bIsActive = false;
}

CSlider::~CSlider(void)
{
}


BEGIN_MESSAGE_MAP(CSlider, CStatic)
	//{{AFX_MSG_MAP(CBitmapSlider)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


void CSlider::SetBitmapIndex(UINT nBitmapIndex)
{
	ModifyStyle(SS_BITMAP, 0);  // Remove bitmap style, use owner paint
	bool bForceRedraw = (m_nBitmapIndex != nBitmapIndex);
	m_nBitmapIndex = nBitmapIndex;
	// Force owner paint
	if (::IsWindow(m_hWnd) && bForceRedraw)
	{
		Invalidate();
	}
}
// CTransparentPic message handlers
BOOL CSlider::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CSlider::OnPaint() 
{
	ui_trace("CSlider::OnPaint() \n");
	CWnd::Default(); // Calls the default window procedure
	CClientDC dc(this);
	CBitmap bmp;
	// Try to load bitmap
	if (bmp.LoadBitmap(m_nBitmapIndex))
	{
		CDC memDC;
		memDC.CreateCompatibleDC(NULL);
		CBitmap* pOldBmp = memDC.SelectObject(&bmp);
		BITMAP bitmap;
		bmp.GetBitmap(&bitmap);
		TransparentBlt(dc.m_hDC, 0, 0, 0, 0, 
		memDC.m_hDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(255, 125, 0));
		memDC.SelectObject(pOldBmp);
		memDC.DeleteDC();
	}

	return CStatic::OnPaint();
}



void CSlider::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//CString a;
	//a.Format(_T("OnLButtonDown"));
	//AfxMessageBox(a,1,1);
	m_bIsActive = true;
}

void CSlider::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bIsActive = false;
}

