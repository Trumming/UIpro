// m_page2.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page2.h"
#include "CMImage.h"

// m_page2 dialog

IMPLEMENT_DYNAMIC(m_page2, CDialog)

m_page2::m_page2(CWnd* pParent /*=NULL*/)
	: CDialog(m_page2::IDD, pParent)
{

}

m_page2::~m_page2()
{
}

void m_page2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KNOB11, m_knob11);
	DDX_Control(pDX, IDC_KNOB12, m_knob12);
	DDX_Control(pDX, IDC_KNOB13, m_knob13);
	DDX_Control(pDX, IDC_KNOB14, m_knob14);
	DDX_Control(pDX, IDC_KNOB15, m_knob15);
	DDX_Control(pDX, IDC_KNOB16, m_knob16);
	DDX_Control(pDX, IDC_KNOB17, m_knob17);
	DDX_Control(pDX, IDC_KNOB18, m_knob18);
	DDX_Control(pDX, IDC_KNOB21, m_knob21);
	DDX_Control(pDX, IDC_KNOB22, m_knob22);
	DDX_Control(pDX, IDC_KNOB23, m_knob23);
	DDX_Control(pDX, IDC_KNOB24, m_knob24);
	DDX_Control(pDX, IDC_KNOB25, m_knob25);
	DDX_Control(pDX, IDC_KNOB26, m_knob26);
	DDX_Control(pDX, IDC_KNOB27, m_knob27);
	DDX_Control(pDX, IDC_KNOB28, m_knob28);
	DDX_Control(pDX, IDC_KNOB31, m_knob31);
	DDX_Control(pDX, IDC_KNOB32, m_knob32);
	DDX_Control(pDX, IDC_KNOB33, m_knob33);
	DDX_Control(pDX, IDC_KNOB34, m_knob34);
	DDX_Control(pDX, IDC_KNOB35, m_knob35);
	DDX_Control(pDX, IDC_KNOB36, m_knob36);
	DDX_Control(pDX, IDC_KNOB37, m_knob37);
	DDX_Control(pDX, IDC_KNOB38, m_knob38);
	DDX_Control(pDX, IDC_KNOB41, m_knob41);
	DDX_Control(pDX, IDC_KNOB42, m_knob42);
	DDX_Control(pDX, IDC_KNOB43, m_knob43);
	DDX_Control(pDX, IDC_KNOB44, m_knob44);
	DDX_Control(pDX, IDC_KNOB45, m_knob45);
	DDX_Control(pDX, IDC_KNOB46, m_knob46);
	DDX_Control(pDX, IDC_KNOB47, m_knob47);
	DDX_Control(pDX, IDC_KNOB48, m_knob48);
	DDX_Control(pDX, IDC_KNOB51, m_knob51);
	DDX_Control(pDX, IDC_KNOB52, m_knob52);
	DDX_Control(pDX, IDC_KNOB53, m_knob53);
	DDX_Control(pDX, IDC_KNOB54, m_knob54);
	DDX_Control(pDX, IDC_KNOB55, m_knob55);
	DDX_Control(pDX, IDC_KNOB56, m_knob56);
	DDX_Control(pDX, IDC_KNOB57, m_knob57);
	DDX_Control(pDX, IDC_KNOB58, m_knob58);
	DDX_Control(pDX, IDC_KNOB61, m_knob61);
	DDX_Control(pDX, IDC_KNOB62, m_knob62);
	DDX_Control(pDX, IDC_KNOB63, m_knob63);
	DDX_Control(pDX, IDC_KNOB64, m_knob64);
	DDX_Control(pDX, IDC_KNOB65, m_knob65);
	DDX_Control(pDX, IDC_KNOB66, m_knob66);
	DDX_Control(pDX, IDC_KNOB67, m_knob67);
	DDX_Control(pDX, IDC_KNOB68, m_knob68);
}

void m_page2::OnPaint() 
{
#if 1
	CPaintDC dc(this); // device context for painting
	CRect   rect;   
	GetClientRect(&rect);   
	CDC   dcMem;   
	dcMem.CreateCompatibleDC(&dc);   
	CBitmap   bmpBackground;   
	bmpBackground.LoadBitmap(IDB_KNOBBK); 

	//IDB_BITMAP是你自己的图对应的ID 
	BITMAP   bitmap;   
	bmpBackground.GetBitmap(&bitmap);   
	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	//Do not call CDialog::OnPaint() for painting messages  
#else
	CPaintDC dc(this); // device context for painting
	CRect   rect;   
	GetClientRect(&rect);   
	CDC   dcMem;   
	dcMem.CreateCompatibleDC(&dc); 

	CDC *pDC(GetDC());
	CMImage scale;

	GetClientRect(&rect); 
	if(scale.LoadImageFromResource(IDB_PNG1,_T("PNG")))
	{
		scale.TransparentPNG();
		//scale.Draw(dcMem.m_hDC,0,0,scale.GetWidth(),scale.GetHeight(),0,0,scale.GetWidth(),scale.GetHeight());
		scale.Draw(pDC->m_hDC,rect);
	}
	//else
	//	MessageBox(_T("Image Error"));							// 图片加载失败
	scale.Destroy();
#endif
}
BEGIN_MESSAGE_MAP(m_page2, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

void m_page2::OnLButtonUp( UINT nFlags, CPoint point )
{
	m_knob11.m_bActive = false;
	m_knob12.m_bActive = false;
	m_knob13.m_bActive = false;
	m_knob14.m_bActive = false;
	m_knob15.m_bActive = false;
	m_knob16.m_bActive = false;
	m_knob17.m_bActive = false;
	m_knob18.m_bActive = false;
	m_knob21.m_bActive = false;
	m_knob22.m_bActive = false;
	m_knob23.m_bActive = false;
	m_knob24.m_bActive = false;
	m_knob25.m_bActive = false;
	m_knob26.m_bActive = false;
	m_knob27.m_bActive = false;
	m_knob28.m_bActive = false;
	m_knob31.m_bActive = false;
	m_knob32.m_bActive = false;
	m_knob33.m_bActive = false;
	m_knob34.m_bActive = false;
	m_knob35.m_bActive = false;
	m_knob36.m_bActive = false;
	m_knob37.m_bActive = false;
	m_knob38.m_bActive = false;
	m_knob41.m_bActive = false;
	m_knob42.m_bActive = false;
	m_knob43.m_bActive = false;
	m_knob44.m_bActive = false;
	m_knob45.m_bActive = false;
	m_knob46.m_bActive = false;
	m_knob47.m_bActive = false;
	m_knob48.m_bActive = false;
	m_knob51.m_bActive = false;
	m_knob52.m_bActive = false;
	m_knob53.m_bActive = false;
	m_knob54.m_bActive = false;
	m_knob55.m_bActive = false;
	m_knob56.m_bActive = false;
	m_knob57.m_bActive = false;
	m_knob58.m_bActive = false;
	m_knob61.m_bActive = false;
	m_knob62.m_bActive = false;
	m_knob63.m_bActive = false;
	m_knob64.m_bActive = false;
	m_knob65.m_bActive = false;
	m_knob66.m_bActive = false;
	m_knob67.m_bActive = false;
	m_knob68.m_bActive = false;

	m_knob11.m_bFreshScale = true;
	m_knob12.m_bFreshScale = true;
	m_knob13.m_bFreshScale = true;
	m_knob14.m_bFreshScale = true;
	m_knob15.m_bFreshScale = true;
	m_knob16.m_bFreshScale = true;
	m_knob17.m_bFreshScale = true;
	m_knob18.m_bFreshScale = true;
	m_knob21.m_bFreshScale = true;
	m_knob22.m_bFreshScale = true;
	m_knob23.m_bFreshScale = true;
	m_knob24.m_bFreshScale = true;
	m_knob25.m_bFreshScale = true;
	m_knob26.m_bFreshScale = true;
	m_knob27.m_bFreshScale = true;
	m_knob28.m_bFreshScale = true;
	m_knob31.m_bFreshScale = true;
	m_knob32.m_bFreshScale = true;
	m_knob33.m_bFreshScale = true;
	m_knob34.m_bFreshScale = true;
	m_knob35.m_bFreshScale = true;
	m_knob36.m_bFreshScale = true;
	m_knob37.m_bFreshScale = true;
	m_knob38.m_bFreshScale = true;
	m_knob41.m_bFreshScale = true;
	m_knob42.m_bFreshScale = true;
	m_knob43.m_bFreshScale = true;
	m_knob44.m_bFreshScale = true;
	m_knob45.m_bFreshScale = true;
	m_knob46.m_bFreshScale = true;
	m_knob47.m_bFreshScale = true;
	m_knob48.m_bFreshScale = true;
	m_knob51.m_bFreshScale = true;
	m_knob52.m_bFreshScale = true;
	m_knob53.m_bFreshScale = true;
	m_knob54.m_bFreshScale = true;
	m_knob55.m_bFreshScale = true;
	m_knob56.m_bFreshScale = true;
	m_knob57.m_bFreshScale = true;
	m_knob58.m_bFreshScale = true;
	m_knob61.m_bFreshScale = true;
	m_knob62.m_bFreshScale = true;
	m_knob63.m_bFreshScale = true;
	m_knob64.m_bFreshScale = true;
	m_knob65.m_bFreshScale = true;
	m_knob66.m_bFreshScale = true;
	m_knob67.m_bFreshScale = true;
	m_knob68.m_bFreshScale = true;
}


// m_page2 message handlers




