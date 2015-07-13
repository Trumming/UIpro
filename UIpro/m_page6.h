#include "m_page3.h"
#pragma once


// m_page6 dialog

class m_page6 : public CDialog
{
	DECLARE_DYNAMIC(m_page6)

public:
	m_page6(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page6();

// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	float m_MasterVolume;
	float m_OutputTrimCH1;
	float m_OutputTrimCH2;
	float m_OutputTrimCH3;
	float m_OutputTrimCH4;
	float m_OutputTrimCH5;
	float m_OutputTrimCH6;
	float m_OutputTrimCH7;
	float m_OutputTrimCH8;

	CSliderCtrl m_SliderCH1;
	CSliderCtrl m_SliderCH2;
	CSliderCtrl m_SliderCH3;
	CSliderCtrl m_SliderCH4;
	CSliderCtrl m_SliderCH5;
	CSliderCtrl m_SliderCH6;
	CSliderCtrl m_SliderCH7;
	CSliderCtrl m_SliderCH8;
	CSliderCtrl m_SliderVol;
public:
	BOOL m_Tandem;
	CPicEditor m_USBState;

};
