// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UIpro.h"
#include "Login.h"
#include "UIproDlg.h"

// Login �Ի���

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


// Login ��Ϣ�������

void Login::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sPw("abc");
	UpdateData(TRUE);
	if(!sPw.Compare(m_sPassword))
	{
		m_sPassword = "";
		m_bAuthored = TRUE;
		MessageBox(_T("ȡ����Ȩ!"),_T("Warning"),MB_OK);
		ReleaseDC(GetDC());
		EndDialog(TRUE);
	}
	else
	{
		m_bAuthored = FALSE;
		MessageBox(_T("wrong password!"),_T("Warning"),MB_OK);
	}
}
