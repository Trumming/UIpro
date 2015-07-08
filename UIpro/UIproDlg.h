// UIproDlg.h : ͷ�ļ�
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

// CUIproDlg �Ի���
class CUIproDlg : public CDialog
{
// ����
public:
	CUIproDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_UIPRO_DIALOG };
	/*virtual BOOL PreTranslateMessage(MSG* pMsg);	*/

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
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
