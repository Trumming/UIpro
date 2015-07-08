// m_page4.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page4.h"


// m_page4 dialog

IMPLEMENT_DYNAMIC(m_page4, CDialog)

m_page4::m_page4(CWnd* pParent /*=NULL*/)
	: CDialog(m_page4::IDD, pParent)
	, m_DelayCH1(0)
	, m_CheckAll(FALSE)
{
	m_DelayCH1=m_DelayCH2=m_DelayCH3=m_DelayCH4=m_DelayCH5=m_DelayCH6=m_DelayCH7=m_DelayCH8 = 0;
}

m_page4::~m_page4()
{
}

void m_page4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DelayCH1);
	DDX_Text(pDX, IDC_EDIT2, m_DelayCH2);
	DDX_Text(pDX, IDC_EDIT3, m_DelayCH3);
	DDX_Text(pDX, IDC_EDIT4, m_DelayCH4);
	DDX_Text(pDX, IDC_EDIT5, m_DelayCH5);
	DDX_Text(pDX, IDC_EDIT6, m_DelayCH6);
	DDX_Text(pDX, IDC_EDIT7, m_DelayCH7);
	DDX_Text(pDX, IDC_EDIT8, m_DelayCH8);

	DDX_Control(pDX, IDC_SLIDER1, m_SliderCH1);
	DDX_Control(pDX, IDC_SLIDER11, m_SliderCH2);
	DDX_Control(pDX, IDC_SLIDER17, m_SliderCH3);
	DDX_Control(pDX, IDC_SLIDER12, m_SliderCH4);
	DDX_Control(pDX, IDC_SLIDER13, m_SliderCH5);
	DDX_Control(pDX, IDC_SLIDER14, m_SliderCH6);
	DDX_Control(pDX, IDC_SLIDER16, m_SliderCH7);
	DDX_Control(pDX, IDC_SLIDER15, m_SliderCH8);
	DDX_Check(pDX, IDC_CHECK17, m_CheckAll);
}


BEGIN_MESSAGE_MAP(m_page4, CDialog)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// m_page4 message handlers
BOOL m_page4::OnInitDialog()
{
	CDialog::OnInitDialog();
	int _max = 12000,_min =0,step = 120;

	m_SliderCH1.SetRange(_min,_max);
	m_SliderCH1.SetTicFreq(step);
	m_SliderCH1.SetPos(0);

	m_SliderCH2.SetRange(_min,_max);
	m_SliderCH2.SetTicFreq(step);
	m_SliderCH2.SetPos(0);

	m_SliderCH3.SetRange(_min,_max);
	m_SliderCH3.SetTicFreq(step);
	m_SliderCH3.SetPos(0);

	m_SliderCH4.SetRange(_min,_max);
	m_SliderCH4.SetTicFreq(step);
	m_SliderCH4.SetPos(0);

	m_SliderCH5.SetRange(_min,_max);
	m_SliderCH5.SetTicFreq(step);
	m_SliderCH5.SetPos(0);

	m_SliderCH6.SetRange(_min,_max);
	m_SliderCH6.SetTicFreq(step);
	m_SliderCH6.SetPos(0);

	m_SliderCH7.SetRange(_min,_max);
	m_SliderCH7.SetTicFreq(step);
	m_SliderCH7.SetPos(0);

	m_SliderCH8.SetRange(_min,_max);
	m_SliderCH8.SetTicFreq(step);
	m_SliderCH8.SetPos(0);

	return TRUE;
}

void m_page4::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	float tmp = 0;
	CDialog::OnVScroll(nSBCode,  nPos,  pScrollBar);
	UpdateData(TRUE);
	if(pScrollBar != NULL)
	{
		if((CSliderCtrl*)pScrollBar == &m_SliderCH1)			tmp = m_DelayCH1 = m_SliderCH1.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH2)		tmp = m_DelayCH2 = m_SliderCH2.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH3)		tmp = m_DelayCH3 = m_SliderCH3.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH4)		tmp = m_DelayCH4 = m_SliderCH4.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH5)		tmp = m_DelayCH5 = m_SliderCH5.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH6)		tmp = m_DelayCH6 = m_SliderCH6.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH7)		tmp = m_DelayCH7 = m_SliderCH7.GetPos()*0.001f;
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH8)		tmp = m_DelayCH8 = m_SliderCH8.GetPos()*0.001f;

		if(TRUE == m_CheckAll)
		{		
			m_DelayCH1=m_DelayCH2=m_DelayCH3=m_DelayCH4=m_DelayCH5=m_DelayCH6=m_DelayCH7=m_DelayCH8 = tmp;
			m_SliderCH1.SetPos(m_DelayCH1*1000);
			m_SliderCH2.SetPos(m_DelayCH2*1000);
			m_SliderCH3.SetPos(m_DelayCH3*1000);
			m_SliderCH4.SetPos(m_DelayCH4*1000);
			m_SliderCH5.SetPos(m_DelayCH5*1000);
			m_SliderCH6.SetPos(m_DelayCH6*1000);
			m_SliderCH7.SetPos(m_DelayCH7*1000);
			m_SliderCH8.SetPos(m_DelayCH8*1000);
		}
		UpdateData(FALSE);
	}
}