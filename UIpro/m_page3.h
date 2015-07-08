#pragma once
#include "afxcmn.h"
#include "afxwin.h"

// IPicEditor add event 
class CPicEditor :public CStatic
{
public:
	CPicEditor(void);
public:
	~CPicEditor(void);

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

protected:
	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bActive;
};

// m_page3 dialog

class m_page3 : public CDialog
{
	DECLARE_DYNAMIC(m_page3)

public:
	m_page3(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page3();
	virtual BOOL OnInitDialog(); 
// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

public:
	CString m_sHPFType;
	CString m_sHPFOct;
	CString m_sLPFType;
	CString m_sLPFOct;
	CSliderCtrl m_SliderFreq;

	int m_Freq;

public:
	CPicEditor CPicCH1;
};
