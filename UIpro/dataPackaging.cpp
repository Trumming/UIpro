#include "stdafx.h"

/*
void CPS8Dlg::OnBnClickedbtnopencom()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_bPortOpened)
	{
		m_port.ClosePort();
		m_bPortOpened = false;
	}

	if(m_port.InitPort(this->m_hWnd,3,9600,'N',8,1,EV_RXCHAR|EV_RXFLAG,1024))
	{
		m_port.StartMonitoring();
		m_bPortOpened = true;
	}
	else
	{
		AfxMessageBox(_T("COM Port is unaviliable!"));
		m_bPortOpened = false;
	}
}

void CPS8Dlg::OnBnClickedbtnclosecom()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_port.ClosePort();
	m_bPortOpened = false;
}

void CPS8Dlg::OnBnClickedbtnsendmsg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char msg[]="you shutup!";
	if(m_bPortOpened)
	{
		UpdateData(TRUE);
		//m_port.WriteToPort(m_strEditTransmitMsg);
		m_port.WriteToPort(msg);
	}
	else
	{
		AfxMessageBox(_T("The Serial Port is Closed!"));
	}
}
*/