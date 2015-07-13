// m_page3.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page3.h"
#include"atlimage.h"

// CPicEditor
CPicEditor::CPicEditor()
{
	m_bActive = false;
}

CPicEditor::~CPicEditor()
{

}


BEGIN_MESSAGE_MAP(CPicEditor, CStatic)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

void CPicEditor::OnLButtonDown(UINT nFlags, CPoint point)
{
	CImage img;
	CRect   rect;   
	GetClientRect(&rect);   

	if(m_bActive)
	{
		m_bActive = false;
		img.LoadFromResource(AfxGetInstanceHandle(),IDB_OFF);
	}
	else
	{
		m_bActive = true;
		img.LoadFromResource(AfxGetInstanceHandle(),IDB_ON);
	}
	img.Draw(GetDC()->m_hDC,rect);
}

// m_page3 dialog

IMPLEMENT_DYNAMIC(m_page3, CDialog)

m_page3::m_page3(CWnd* pParent /*=NULL*/)
	: CDialog(m_page3::IDD, pParent)
	, m_sHPFType(_T(""))
	, m_sHPFOct(_T(""))
	, m_sLPFType(_T(""))
	, m_sLPFOct(_T(""))
	, m_Freq(0)
{
	m_sHPFType = "Bessel";
	m_sHPFOct = "48db/Oct";

	m_sLPFType = "Bessel";
	m_sLPFOct = "48db/Oct";

	m_Freq = 200;
}

m_page3::~m_page3()
{
}

void m_page3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_sHPFType);
	DDX_CBString(pDX, IDC_COMBO2, m_sHPFOct);
	DDX_CBString(pDX, IDC_COMBO3, m_sLPFType);
	DDX_CBString(pDX, IDC_COMBO4, m_sLPFOct);
	DDX_Control(pDX, IDC_SLIDER1, m_SliderFreq);

	DDX_Control(pDX, IDC_STATIC1, CPicCH1);
	DDX_Control(pDX, IDC_STATIC2, CPicCH2);
	DDX_Control(pDX, IDC_STATIC3, CPicCH3);
	DDX_Control(pDX, IDC_STATIC4, CPicCH4);
	DDX_Control(pDX, IDC_STATIC5, CPicCH5);
	DDX_Control(pDX, IDC_STATIC6, CPicCH6);
	DDX_Control(pDX, IDC_STATIC7, CPicCH7);
	DDX_Control(pDX, IDC_STATIC8, CPicCH8);
	DDX_Text(pDX, IDC_EDIT1, m_Freq);
}


BEGIN_MESSAGE_MAP(m_page3, CDialog)
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// m_page3 message handlers
BOOL m_page3::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_SliderFreq.SetRange(20,20000);
	m_SliderFreq.SetTicFreq(100);
	m_SliderFreq.SetPos(200);
	
	return true;
}


void m_page3::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CDialog::OnHScroll( nSBCode,  nPos,  pScrollBar);
	if((pScrollBar != NULL)&((CSliderCtrl*)pScrollBar == &m_SliderFreq))
	{
		m_Freq = m_SliderFreq.GetPos();
		UpdateData(FALSE);
	}
}

void m_page3::OnLButtonDown(UINT nFlags, CPoint point)
{

}