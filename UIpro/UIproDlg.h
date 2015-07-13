// UIproDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "m_page1.h"
#include "m_page2.h"
#include "m_page3.h"
#include "m_page4.h"
#include "m_page5.h"
#include "m_page6.h"
#include "Login.h"

// CUIproDlg 对话框
class CUIproDlg : public CDialog
{
// 构造
public:
	CUIproDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_UIPRO_DIALOG };
	/*virtual BOOL PreTranslateMessage(MSG* pMsg);	*/

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabCtrl;
	m_page1 m_page1;
	m_page2 m_page2;
	m_page3 m_page3;
	m_page4 m_page4;
	m_page5 m_page5;
	m_page6 m_page6;
	Login dlgLogin;
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSetupPassword();
};
