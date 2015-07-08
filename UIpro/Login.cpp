// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "UIpro.h"
#include "Login.h"
#include "UIproDlg.h"

// Login 对话框

IMPLEMENT_DYNAMIC(Login, CDialog)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialog(Login::IDD, pParent)
	, m_sPassword(_T(""))
{
	m_sPassword = "";
	m_bAuthored = FALSE;
}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sPassword);
}


BEGIN_MESSAGE_MAP(Login, CDialog)
	ON_BN_CLICKED(ID_LOGIN, &Login::OnBnClickedLogin)
END_MESSAGE_MAP()


// Login 消息处理程序

void Login::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sPw("abc");
	UpdateData(TRUE);
	if(!sPw.Compare(m_sPassword))
	{
		m_sPassword = "";
		m_bAuthored = TRUE;
		MessageBox(_T("取得授权!"),_T("Warning"),MB_OK);
		ReleaseDC(GetDC());
		EndDialog(TRUE);
	}
	else
	{
		m_bAuthored = FALSE;
		MessageBox(_T("wrong password!"),_T("Warning"),MB_OK);
	}
}
