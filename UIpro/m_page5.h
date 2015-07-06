#pragma once
#include "afxcmn.h"
#include "MySliderCtrl.h"
#include "BitmapSlider.h"
#include "Slider.h"
#include "Drawline.h"



// m_page5 dialog

class m_page5 : public CDialog
{
	DECLARE_DYNAMIC(m_page5)

public:
	m_page5(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page5();
	void GetCurrentCStatic();
	enum { IDD = IDD_DIALOG5 };
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void OnTimer(UINT nIDEvent);

	DECLARE_MESSAGE_MAP()
public:
	CDrawline m_drawline;
	CSlider *m_curSlider;
	CSlider m_slider1;
	CSlider m_slider2;
	CSlider m_slider3;
	CSlider m_slider4;
	CSlider m_slider5;
	CSlider m_slider6;
	CSlider m_slider7;
	CSlider m_sliderh;
	CSlider m_sliderl;
	bool m_bInit;
	bool m_bIsReady;


private:
	bool m_bIsUp;
public:
	void ProMoveMsg();
};
