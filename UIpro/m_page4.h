#pragma once
#include "afxcmn.h"


// m_page4 dialog

class m_page4 : public CDialog
{
	DECLARE_DYNAMIC(m_page4)

public:
	m_page4(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page4();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
	float m_DelayCH1;
	float m_DelayCH2;
	float m_DelayCH3;
	float m_DelayCH4;
	float m_DelayCH5;
	float m_DelayCH6;
	float m_DelayCH7;
	float m_DelayCH8;
private:
	CSliderCtrl m_SliderCH1;
	CSliderCtrl m_SliderCH2;
	CSliderCtrl m_SliderCH3;
	CSliderCtrl m_SliderCH4;
	CSliderCtrl m_SliderCH5;
	CSliderCtrl m_SliderCH6;
	CSliderCtrl m_SliderCH7;
	CSliderCtrl m_SliderCH8;
public:
	BOOL m_CheckAll;
};
