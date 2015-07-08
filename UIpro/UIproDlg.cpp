// UIproDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UIpro.h"
#include "UIproDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUIproDlg �Ի���




CUIproDlg::CUIproDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUIproDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUIproDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CUIproDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CUIproDlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_SETUP_PASSWORD, &CUIproDlg::OnSetupPassword)
END_MESSAGE_MAP()


// CUIproDlg ��Ϣ�������

BOOL CUIproDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	dlgLogin.DoModal();
	if(FALSE == dlgLogin.m_bAuthored)
		EndDialog(TRUE);

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//���ѡ�����
	m_tabCtrl.InsertItem(0,L"Input");
	m_tabCtrl.InsertItem(1,L"Mixer");
	m_tabCtrl.InsertItem(2,L"Crossovers");
	m_tabCtrl.InsertItem(3,L"Signal Delay");
	m_tabCtrl.InsertItem(4,L"EQ");
	m_tabCtrl.InsertItem(5,L"Output");
	    
	//����IDC_TAB1Ϊ������
	m_page1.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB1));
	m_page2.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1));
	m_page3.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1));
	m_page4.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1));
	m_page5.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB1));
	m_page6.Create(IDD_DIALOG6,GetDlgItem(IDC_TAB1));
	    
	//���IDC_TABTEST�ͻ�����С
	CRect rc;
	m_tabCtrl.GetClientRect(&rc);
	    
	//�����ӶԻ����ڸ������е�λ��
	rc.top += 30;
	rc.bottom -= 8;
	rc.left += 8;
	rc.right -= 8;

	//�����ӶԻ���ߴ粢�ƶ���ָ��λ��
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc);
	m_page3.MoveWindow(&rc);
	m_page4.MoveWindow(&rc);
	m_page5.MoveWindow(&rc);
	m_page6.MoveWindow(&rc);

	//�ֱ��������غ���ʾ
	m_page1.ShowWindow(true);
	m_page2.ShowWindow(false);
	m_page3.ShowWindow(false);
	m_page4.ShowWindow(false);
	m_page5.ShowWindow(false);
	m_page6.ShowWindow(false);

	//����Ĭ�ϵ�ѡ�
	m_tabCtrl.SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CUIproDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CUIproDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUIproDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ��������
    int CurSel = m_tabCtrl.GetCurSel();
	m_page1.ShowWindow(false);
	m_page2.ShowWindow(false);
	m_page3.ShowWindow(false);
	m_page4.ShowWindow(false);
	m_page5.ShowWindow(false);
	m_page6.ShowWindow(false);

    switch(CurSel)
    {
    case 0:
        m_page1.ShowWindow(true);
        break;
    case 1:
        m_page2.ShowWindow(true);
        break;
	case 2:
        m_page3.ShowWindow(true);
        break;
	case 3:
        m_page4.ShowWindow(true);
        break;
	case 4:
        m_page5.ShowWindow(true);
        break;
	case 5:
        m_page6.ShowWindow(true);
        break;
    }
	*pResult = 0;
}

void CUIproDlg::OnLButtonUp( UINT nFlags, CPoint point )
{
	m_page2.SendMessage(WM_LBUTTONUP,0,0);
}

//BOOL CUIproDlg::PreTranslateMessage( MSG* pMsg )
//{
//	if(pMsg->message == WM_LBUTTONUP)
//	{
//		m_page2.SendMessage(WM_LBUTTONUP,0,0);
//	}
//	return CDialog::PreTranslateMessage(pMsg);
//}



void CUIproDlg::OnSetupPassword()
{
	// TODO: �ڴ���������������
	dlgLogin.DoModal();
}
