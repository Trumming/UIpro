#pragma once

#include <string.h>

// class rmtBusReceiver;
//class CPSerialPort;
//class CMainWnd;

class CMainManager  
{
public:

	CMainManager();
	virtual ~CMainManager();

	BOOL init();
	BOOL uninit();
	
	//class CPSerialPort* m_pSerial;
	//class CMainWnd * m_pMain_win;
	
	
private:
	//static UINT comm_process_thread(LPVOID pParam);
	
	//CWinThread * m_pComm_proc_thread;
	//class rmtBusReceiver * m_pBus_receive_thread;
	//class rmtBusSender * m_pBus_send_thread;
;
	
	
	//use port parameter
	//CString PortID;
	//int BaudRate,DataBits,StopBits,Parity;
	bool is_init;

	
};
