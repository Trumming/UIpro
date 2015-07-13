// m_page1.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page1.h"

#include "Cdata.h"

extern Cdata Storage;
//extern CMainManager main_manager;
// m_page1 dialog

IMPLEMENT_DYNAMIC(m_page1, CDialog)

m_page1::m_page1(CWnd* pParent /*=NULL*/)
	: CDialog(m_page1::IDD, pParent)
	, m_AutoDelay(0)
	, m_BTandem(FALSE)
	, m_SysSelNbr(0)
	, m_InputNbr(0)
	, m_DigitalNbr(0)
	, m_AnalogNbr(0)
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
	DDX_Radio(pDX, IDC_RADIO1, m_SysSelNbr);
	DDX_Radio(pDX, IDC_RADIO7, m_InputNbr);
	DDX_Radio(pDX, IDC_RADIO12, m_DigitalNbr);
	DDX_Radio(pDX, IDC_RADIO10, m_AnalogNbr);
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
	m_SliderAutoDelay.SetPos(Storage.get_int_data(Storage.DATA_PAGE1_AUTODELAY));
	m_AutoDelay = (float)(m_SliderAutoDelay.GetPos()*0.1f);

	m_GainCH1 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH1);
	m_SliderCH1.SetRange(min,max);
	m_SliderCH1.SetTicFreq(1);
	m_SliderCH1.SetPos(m_GainCH1);

	m_GainCH2 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH2);
	m_SliderCH2.SetRange(min,max);
	m_SliderCH2.SetTicFreq(1);
	m_SliderCH2.SetPos(m_GainCH2);

	m_GainCH3 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH3);
	m_SliderCH3.SetRange(min,max);
	m_SliderCH3.SetTicFreq(1);
	m_SliderCH3.SetPos(m_GainCH3);

	m_GainCH4 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH4);
	m_SliderCH4.SetRange(min,max);
	m_SliderCH4.SetTicFreq(1);
	m_SliderCH4.SetPos(m_GainCH4);

	m_GainCH5 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH5);
	m_SliderCH5.SetRange(min,max);
	m_SliderCH5.SetTicFreq(1);
	m_SliderCH5.SetPos(m_GainCH5);

	m_GainCH6 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH6);
	m_SliderCH6.SetRange(min,max);
	m_SliderCH6.SetTicFreq(1);
	m_SliderCH6.SetPos(m_GainCH6);

	m_GainCH7 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH7);
	m_SliderCH7.SetRange(min,max);
	m_SliderCH7.SetTicFreq(1);
	m_SliderCH7.SetPos(m_GainCH7);

	m_GainCH8 = Storage.get_int_data(Storage.DATA_PAGE1_SLIDER_CH8);
	m_SliderCH8.SetRange(min,max);
	m_SliderCH8.SetTicFreq(1);
	m_SliderCH8.SetPos(m_GainCH8);

	//System Select
	m_SysSelNbr = Storage.get_char_data(Storage.DATA_PAGE1_SYS_SEL);
	//Preset
	//Input
	m_InputNbr = Storage.get_char_data(Storage.DATA_PAGE1_INPUT);
	//Input - Digital
	m_DigitalNbr = Storage.get_char_data(Storage.DATA_PAGE1_DIGITAL);
	//Input Analog
	m_AnalogNbr = Storage.get_char_data(Storage.DATA_PAGE1_ANALOG);

	m_BTandem = Storage.get_bool_data(Storage.DATA_PAGE1_TANDEM);
	UpdateData(FALSE);
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

void m_page1::SaveData(void)
{
	UpdateData(TRUE);
	Storage.set_char_data((char)m_SysSelNbr,Storage.DATA_PAGE1_SYS_SEL);
	Storage.set_char_data((char)m_InputNbr,Storage.DATA_PAGE1_INPUT);
	Storage.set_char_data((char)m_DigitalNbr,Storage.DATA_PAGE1_DIGITAL);
	Storage.set_char_data((char)m_AnalogNbr,Storage.DATA_PAGE1_ANALOG);
	Storage.set_int_data(m_SliderAutoDelay.GetPos(), Storage.DATA_PAGE1_AUTODELAY);
	Storage.set_int_data(m_SliderCH1.GetPos(), Storage.DATA_PAGE1_SLIDER_CH1);
	Storage.set_int_data(m_SliderCH2.GetPos(), Storage.DATA_PAGE1_SLIDER_CH2);
	Storage.set_int_data(m_SliderCH3.GetPos(), Storage.DATA_PAGE1_SLIDER_CH3);
	Storage.set_int_data(m_SliderCH4.GetPos(), Storage.DATA_PAGE1_SLIDER_CH4);
	Storage.set_int_data(m_SliderCH5.GetPos(), Storage.DATA_PAGE1_SLIDER_CH5);
	Storage.set_int_data(m_SliderCH6.GetPos(), Storage.DATA_PAGE1_SLIDER_CH6);
	Storage.set_int_data(m_SliderCH7.GetPos(), Storage.DATA_PAGE1_SLIDER_CH7);
	Storage.set_int_data(m_SliderCH8.GetPos(), Storage.DATA_PAGE1_SLIDER_CH8);
	Storage.set_bool_data(m_BTandem,Storage.DATA_PAGE1_TANDEM);
}
