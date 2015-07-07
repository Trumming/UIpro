#pragma once
#include "afxcmn.h"


// m_page1 dialog

class m_page1 : public CDialog
{
	DECLARE_DYNAMIC(m_page1)

public:
	m_page1(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page1();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_SliderAutoDelay;
	CSliderCtrl m_SliderCH1;
	CSliderCtrl m_SliderCH2;
	CSliderCtrl m_SliderCH3;
	CSliderCtrl m_SliderCH4;
	CSliderCtrl m_SliderCH5;
	CSliderCtrl m_SliderCH6;
	CSliderCtrl m_SliderCH7;
	CSliderCtrl m_SliderCH8;
	int m_GainCH1;
	int m_GainCH2;
	int m_GainCH3;
	int m_GainCH4;
	int m_GainCH5;
	int m_GainCH6;
	int m_GainCH7;
	int m_GainCH8;
	float m_AutoDelay;
};
