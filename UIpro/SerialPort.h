/*
**	FILENAME			CSerialPort.h
**
**	PURPOSE				This class can read, write and watch one serial port.
**						It sends messages to its owner when something happends on the port
**						The class creates a thread for reading and writing so the main
**						program is not blocked.
**
**	CREATION DATE		15-09-1997
**	LAST MODIFICATION	12-11-1997
**
**	AUTHOR				Remon Spekreijse
**
**
************************************************************************************
**  author: mrlong date:2007-12-25
**
**  �Ľ�
**	1) ���� ClosePort
**	2) ���� WriteToPort ��������
**	3) ���� SendData �� RecvData ����
**************************************************************************************
***************************************************************************************
**  author��liquanhai date:2011-11-06
**
**  �Ľ�
**	1) ���� ClosePort �н�������Ȩ����ֹ��������
**	2) ���� ReceiveChar �з�ֹ�߳�����
**************************************************************************************
***************************************************************************************
**  author��viruscamp date:2013-12-04
**
**  �Ľ�
**	1) ���� IsOpen �ж��Ƿ��
**	2) ���� InitPort �� parity Odd Even ����ȡֵ����
**	3) �޸� InitPort �� portnr ȡֵ��Χ��portnr>9 ʱ���⴦��
**	4) ȡ���� MFC ��������ʹ�� HWND ��� CWnd��ʹ�� win32 thread ���������� MFC ��
**	5) �����û���Ϣ����Զ��壬�������� CnComm
*/

#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#ifndef WM_COMM_MSG_BASE 
	#define WM_COMM_MSG_BASE		WM_USER + 617		//!< ��Ϣ��ŵĻ���  
#endif

#define WM_COMM_BREAK_DETECTED		WM_COMM_MSG_BASE + 1	// A break was detected on input.
#define WM_COMM_CTS_DETECTED		WM_COMM_MSG_BASE + 2	// The CTS (clear-to-send) signal changed state. 
#define WM_COMM_DSR_DETECTED		WM_COMM_MSG_BASE + 3	// The DSR (data-set-ready) signal changed state. 
#define WM_COMM_ERR_DETECTED		WM_COMM_MSG_BASE + 4	// A line-status error occurred. Line-status errors are CE_FRAME, CE_OVERRUN, and CE_RXPARITY. 
#define WM_COMM_RING_DETECTED		WM_COMM_MSG_BASE + 5	// A ring indicator was detected. 
#define WM_COMM_RLSD_DETECTED		WM_COMM_MSG_BASE + 6	// The RLSD (receive-line-signal-detect) signal changed state. 
#define WM_COMM_RXCHAR				WM_COMM_MSG_BASE + 7	// A character was received and placed in the input buffer. 
#define WM_COMM_RXFLAG_DETECTED		WM_COMM_MSG_BASE + 8	// The event character was received and placed in the input buffer.  
#define WM_COMM_TXEMPTY_DETECTED	WM_COMM_MSG_BASE + 9	// The last character in the output buffer was sent.  

class CSerialPort
{														 
public:
	// contruction and destruction
	CSerialPort();
	virtual		~CSerialPort();

	// port initialisation											
	BOOL		InitPort(HWND pPortOwner, UINT portnr = 1, UINT baud = 19200, char parity = 'N', UINT databits = 8, UINT stopbits = 1, DWORD dwCommEvents = EV_RXCHAR, UINT writebuffersize = 1024);

	// start/stop comm watching
	BOOL		StartMonitoring();
	BOOL		RestartMonitoring();
	BOOL		StopMonitoring();

	DWORD		GetWriteBufferSize();
	DWORD		GetCommEvents();
	DCB			GetDCB();

	void		WriteToPort(char* string);
	void		WriteToPort(char* string,int n); // add by mrlong 2007-12-25
//	void		WriteToPort(LPCTSTR string);	 // add by mrlong 2007-12-25
	void		WriteToPort(BYTE* Buffer, int n);// add by mrlong
	void		ClosePort();					 // add by mrlong 2007-12-2  
	BOOL		IsOpen();

	//void SendData(LPCTSTR lpszData, const int nLength);   //���ڷ��ͺ��� by mrlong 2008-2-15
	//BOOL RecvData(LPTSTR lpszData, const int nSize);	  //���ڽ��պ��� by mrlong 2008-2-15

protected:
	// protected memberfunctions
	void		ProcessErrorMessage(TCHAR* ErrorText);
	static DWORD WINAPI CommThread(LPVOID pParam);
	static void	ReceiveChar(CSerialPort* port);
	static void	WriteChar(CSerialPort* port);

	// thread
	//CWinThread*			m_Thread;
	HANDLE			  m_Thread;

	// synchronisation objects
	CRITICAL_SECTION	m_csCommunicationSync;
	BOOL				m_bThreadAlive;

	// handles
	HANDLE				m_hShutdownEvent;  //stop�������¼�
	HANDLE				m_hComm;		   // read  
	HANDLE				m_hWriteEvent;	 // write

	// Event array. 
	// One element is used for each event. There are two event handles for each port.
	// A Write event and a receive character event which is located in the overlapped structure (m_ov.hEvent).
	// There is a general shutdown when the port is closed. 
	HANDLE				m_hEventArray[3];

	// structures
	OVERLAPPED			m_ov;
	COMMTIMEOUTS		m_CommTimeouts;
	DCB					m_dcb;

	// owner window
	//CWnd*				m_pOwner;
	HWND				m_pOwner;


	// misc
	UINT				m_nPortNr;		//?????
	char*				m_szWriteBuffer;
	DWORD				m_dwCommEvents;
	DWORD				m_nWriteBufferSize;

	UINT				 m_nWriteSize; //add by mrlong 2007-12-25
};

#endif __SERIALPORT_H__