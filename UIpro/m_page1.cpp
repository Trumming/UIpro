// m_page1.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page1.h"


// m_page1 dialog

IMPLEMENT_DYNAMIC(m_page1, CDialog)

m_page1::m_page1(CWnd* pParent /*=NULL*/)
	: CDialog(m_page1::IDD, pParent)
	, m_AutoDelay(0)
	, m_BTandem(FALSE)
{

}

m_page1::~m_page1()
{
}

void m_page1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AUTOSELECTSLIDER, m_SliderAutoDelay);
	DDX_Control(pDX, IDC_SLIDER8, m_SliderCH1);
	DDX_Control(pDX, IDC_SLIDER9, m_SliderCH2);
	DDX_Control(pDX, IDC_SLIDER3, m_SliderCH3);
	DDX_Control(pDX, IDC_SLIDER4, m_SliderCH4);
	DDX_Control(pDX, IDC_SLIDER2, m_SliderCH5);
	DDX_Control(pDX, IDC_SLIDER5, m_SliderCH6);
	DDX_Control(pDX, IDC_SLIDER6, m_SliderCH7);
	DDX_Control(pDX, IDC_SLIDER7, m_SliderCH8);
	DDX_Text(pDX, IDC_EDIT1, m_GainCH1);
	DDX_Text(pDX, IDC_EDIT2, m_GainCH2);
	DDX_Text(pDX, IDC_EDIT3, m_GainCH3);
	DDX_Text(pDX, IDC_EDIT4, m_GainCH4);
	DDX_Text(pDX, IDC_EDIT5, m_GainCH5);
	DDX_Text(pDX, IDC_EDIT7, m_GainCH6);
	DDX_Text(pDX, IDC_EDIT6, m_GainCH7);
	DDX_Text(pDX, IDC_EDIT8, m_GainCH8);
	DDX_Text(pDX, IDC_EDIT_AUTOSELECTDELAY, m_AutoDelay);
	DDX_Check(pDX, IDC_CHECK1, m_BTandem);
}


BEGIN_MESSAGE_MAP(m_page1, CDialog)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// m_page1 message handlers
BOOL m_page1::OnInitDialog()
{
	CDialog::OnInitDialog();
	int min = -64,max = 24;
	m_SliderAutoDelay.SetRange(1,50);
	m_SliderAutoDelay.SetTicFreq(1);
	m_SliderAutoDelay.SetPos(0);
	m_AutoDelay = (float)(m_SliderAutoDelay.GetPos()*0.1f);

	m_SliderCH1.SetRange(min,max);
	m_SliderCH1.SetTicFreq(1);
	m_SliderCH1.SetPos(0);

	m_SliderCH2.SetRange(min,max);
	m_SliderCH2.SetTicFreq(1);
	m_SliderCH2.SetPos(0);

	m_SliderCH3.SetRange(min,max);
	m_SliderCH3.SetTicFreq(1);
	m_SliderCH3.SetPos(0);

	m_SliderCH4.SetRange(min,max);
	m_SliderCH4.SetTicFreq(1);
	m_SliderCH4.SetPos(0);

	m_SliderCH5.SetRange(min,max);
	m_SliderCH5.SetTicFreq(1);
	m_SliderCH5.SetPos(0);

	m_SliderCH6.SetRange(min,max);
	m_SliderCH6.SetTicFreq(1);
	m_SliderCH6.SetPos(0);

	m_SliderCH7.SetRange(min,max);
	m_SliderCH7.SetTicFreq(1);
	m_SliderCH7.SetPos(0);

	m_SliderCH8.SetRange(min,max);
	m_SliderCH8.SetTicFreq(1);
	m_SliderCH8.SetPos(0);

	m_GainCH1 = m_SliderCH1.GetPos();
	m_GainCH2 = m_SliderCH2.GetPos();
	m_GainCH3 = m_SliderCH3.GetPos();
	m_GainCH4 = m_SliderCH4.GetPos();
	m_GainCH5 = m_SliderCH5.GetPos();
	m_GainCH6 = m_SliderCH6.GetPos();
	m_GainCH7 = m_SliderCH7.GetPos();
	m_GainCH8 = m_SliderCH8.GetPos();

	//m_SliderCH8.SetBuddy(GetDlgItem(IDC_EDIT8),TRUE); //控件关联，貌似并没什么卵用

	return TRUE;
}

void m_page1::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int tmp = 0;
	CDialog::OnVScroll(nSBCode,  nPos,  pScrollBar);
	UpdateData(TRUE);
	if(pScrollBar != NULL)
	{
		if((CSliderCtrl*)pScrollBar == &m_SliderCH1)			tmp = m_GainCH1 = m_SliderCH1.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH2)		tmp = m_GainCH2 = m_SliderCH2.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH3)		tmp = m_GainCH3 = m_SliderCH3.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH4)		tmp = m_GainCH4 = m_SliderCH4.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH5)		tmp = m_GainCH5 = m_SliderCH5.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH6)		tmp = m_GainCH6 = m_SliderCH6.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH7)		tmp = m_GainCH7 = m_SliderCH7.GetPos();
		else if((CSliderCtrl*)pScrollBar == &m_SliderCH8)		tmp = m_GainCH8 = m_SliderCH8.GetPos();
		
		if(TRUE == m_BTandem)
		{		
			m_GainCH1=m_GainCH2=m_GainCH3=m_GainCH4=m_GainCH5=m_GainCH6=m_GainCH7=m_GainCH8 = tmp;
			m_SliderCH1.SetPos(m_GainCH1);
			m_SliderCH2.SetPos(m_GainCH2);
			m_SliderCH3.SetPos(m_GainCH3);
			m_SliderCH4.SetPos(m_GainCH4);
			m_SliderCH5.SetPos(m_GainCH5);
			m_SliderCH6.SetPos(m_GainCH6);
			m_SliderCH7.SetPos(m_GainCH7);
			m_SliderCH8.SetPos(m_GainCH8);
		}
		UpdateData(FALSE);
	}
}

void m_page1::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CDialog::OnHScroll( nSBCode,  nPos,  pScrollBar);
	if((pScrollBar != NULL)&((CSliderCtrl*)pScrollBar == &m_SliderAutoDelay))
	{
		m_AutoDelay = (float)(m_SliderAutoDelay.GetPos()*0.1f);
		UpdateData(FALSE);
	}
}

