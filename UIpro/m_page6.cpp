// m_page6.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page6.h"


// m_page6 dialog

IMPLEMENT_DYNAMIC(m_page6, CDialog)

m_page6::m_page6(CWnd* pParent /*=NULL*/)
	: CDialog(m_page6::IDD, pParent)
	, m_Tandem(FALSE)
{
	m_MasterVolume = m_OutputTrimCH1 = m_OutputTrimCH2= m_OutputTrimCH3= m_OutputTrimCH4= m_OutputTrimCH5= m_OutputTrimCH6= m_OutputTrimCH7= m_OutputTrimCH8 = 0;
}

m_page6::~m_page6()
{
}

void m_page6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_MasterVolume);
	DDX_Text(pDX, IDC_EDIT2, m_OutputTrimCH1);
	DDX_Text(pDX, IDC_EDIT3, m_OutputTrimCH2);
	DDX_Text(pDX, IDC_EDIT4, m_OutputTrimCH3);
	DDX_Text(pDX, IDC_EDIT5, m_OutputTrimCH4);
	DDX_Text(pDX, IDC_EDIT6, m_OutputTrimCH5);
	DDX_Text(pDX, IDC_EDIT7, m_OutputTrimCH6);
	DDX_Text(pDX, IDC_EDIT8, m_OutputTrimCH7);
	DDX_Text(pDX, IDC_EDIT9, m_OutputTrimCH8);

	DDX_Control(pDX, IDC_SLIDER1, m_SliderVol);
	DDX_Control(pDX, IDC_SLIDER11, m_SliderCH1);
	DDX_Control(pDX, IDC_SLIDER12, m_SliderCH2);
	DDX_Control(pDX, IDC_SLIDER13, m_SliderCH3);
	DDX_Control(pDX, IDC_SLIDER14, m_SliderCH4);
	DDX_Control(pDX, IDC_SLIDER15, m_SliderCH5);
	DDX_Control(pDX, IDC_SLIDER16, m_SliderCH6);
	DDX_Control(pDX, IDC_SLIDER17, m_SliderCH7);
	DDX_Control(pDX, IDC_SLIDER18, m_SliderCH8);

	DDX_Check(pDX, IDC_CHECK2, m_Tandem);

	DDX_Control(pDX, IDC_STATIC9, m_USBState);
}


BEGIN_MESSAGE_MAP(m_page6, CDialog)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// m_page6 message handlers
BOOL m_page6::OnInitDialog()
{
	CDialog::OnInitDialog();
	int _min= 0,_max = 400,step = 10;
	
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

	m_SliderVol.SetRange(-24,100);
	m_SliderVol.SetTicFreq(10);
	m_SliderVol.SetPos(0);

	return TRUE;
}

void m_page6::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	float tmp = 0;
	CDialog::OnVScroll(nSBCode,  nPos,  pScrollBar);
	UpdateData(TRUE);
	if(pScrollBar != NULL)
	{
		if((CSliderCtrl*)pScrollBar == &m_SliderCH1)			tmp = m_OutputTrimCH1 = m_SliderCH1.GetPos() == 0 ? 0:m_SliderCH1.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH2)		tmp = m_OutputTrimCH2 = m_SliderCH2.GetPos() == 0 ? 0:m_SliderCH2.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH3)		tmp = m_OutputTrimCH3 = m_SliderCH3.GetPos() == 0 ? 0:m_SliderCH3.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH4)		tmp = m_OutputTrimCH4 = m_SliderCH4.GetPos() == 0 ? 0:m_SliderCH4.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH5)		tmp = m_OutputTrimCH5 = m_SliderCH5.GetPos() == 0 ? 0:m_SliderCH5.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH6)		tmp = m_OutputTrimCH6 = m_SliderCH6.GetPos() == 0 ? 0:m_SliderCH6.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH7)		tmp = m_OutputTrimCH7 = m_SliderCH7.GetPos() == 0 ? 0:m_SliderCH7.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH8)		tmp = m_OutputTrimCH8 = m_SliderCH8.GetPos() == 0 ? 0:m_SliderCH8.GetPos()*(-0.1f);
		else if((CSliderCtrl*)pScrollBar == &m_SliderVol)		m_MasterVolume = m_SliderVol.GetPos() == 0 ? 0:m_SliderVol.GetPos()*(-0.1f);

		if(TRUE == m_Tandem)
		{		
			m_OutputTrimCH1=m_OutputTrimCH2=m_OutputTrimCH3=m_OutputTrimCH4=m_OutputTrimCH5=m_OutputTrimCH6=m_OutputTrimCH7=m_OutputTrimCH8 = tmp;
			m_SliderCH1.SetPos(m_OutputTrimCH1*(-10));
			m_SliderCH2.SetPos(m_OutputTrimCH2*(-10));
			m_SliderCH3.SetPos(m_OutputTrimCH3*(-10));
			m_SliderCH4.SetPos(m_OutputTrimCH4*(-10));
			m_SliderCH5.SetPos(m_OutputTrimCH5*(-10));
			m_SliderCH6.SetPos(m_OutputTrimCH6*(-10));
			m_SliderCH7.SetPos(m_OutputTrimCH7*(-10));
			m_SliderCH8.SetPos(m_OutputTrimCH8*(-10));
		}
		UpdateData(FALSE);
	}
}

