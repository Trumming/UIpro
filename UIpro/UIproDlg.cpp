// UIproDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UIpro.h"
#include "UIproDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUIproDlg 对话框




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


// CUIproDlg 消息处理程序

BOOL CUIproDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	dlgLogin.DoModal();
	if(FALSE == dlgLogin.m_bAuthored)
		EndDialog(TRUE);

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//添加选项卡名称
	m_tabCtrl.InsertItem(0,L"Input");
	m_tabCtrl.InsertItem(1,L"Mixer");
	m_tabCtrl.InsertItem(2,L"Crossovers");
	m_tabCtrl.InsertItem(3,L"Signal Delay");
	m_tabCtrl.InsertItem(4,L"EQ");
	m_tabCtrl.InsertItem(5,L"Output");
	    
	//设置IDC_TAB1为父窗口
	m_page1.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB1));
	m_page2.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1));
	m_page3.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1));
	m_page4.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1));
	m_page5.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB1));
	m_page6.Create(IDD_DIALOG6,GetDlgItem(IDC_TAB1));
	    
	//获得IDC_TABTEST客户区大小
	CRect rc;
	m_tabCtrl.GetClientRect(&rc);
	    
	//调整子对话框在父窗口中的位置
	rc.top += 30;
	rc.bottom -= 8;
	rc.left += 8;
	rc.right -= 8;

	//设置子对话框尺寸并移动到指定位置
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc);
	m_page3.MoveWindow(&rc);
	m_page4.MoveWindow(&rc);
	m_page5.MoveWindow(&rc);
	m_page6.MoveWindow(&rc);

	//分别设置隐藏和显示
	m_page1.ShowWindow(true);
	m_page2.ShowWindow(false);
	m_page3.ShowWindow(false);
	m_page4.ShowWindow(false);
	m_page5.ShowWindow(false);
	m_page6.ShowWindow(false);

	//设置默认的选项卡
	m_tabCtrl.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUIproDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CUIproDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUIproDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代
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
	// TODO: 在此添加命令处理程序代码
	dlgLogin.DoModal();
}
