#include "stdafx.h"
//#include "common.h"
//#include "commanddefine.h"
//#include "PSerialPort.h"
//#include "rmtBusReceiver.h"
//#include "rmtBussender.h"
//#include "commondata.h"
#include "Cdata.h"
#include "MainManager.h"
#include "RdWrtIni.h"

extern Cdata Storage;

CMainManager::CMainManager()
{
// 	PortID = "COM1:";
// 	BaudRate=19200;
// 	DataBits=8;
// 	StopBits=ONESTOPBIT;
// 	Parity=NOPARITY;
	is_init = false;
}

CMainManager::~CMainManager()
{
// 	if(m_pBus_receive_thread != NULL)
// 	{
// 		m_pBus_receive_thread->PostThreadMessage(WM_QUIT,0,0);
// 		::WaitForSingleObject(m_pBus_receive_thread->m_hThread,INFINITE);
// 		delete m_pBus_receive_thread;
// 		m_pBus_receive_thread = NULL;
// 	}
// 
// 	if(m_pBus_send_thread != NULL)
// 	{
// 		m_pBus_send_thread->PostThreadMessage(WM_QUIT,0,0);
// 		::WaitForSingleObject(m_pBus_send_thread->m_hThread,INFINITE);
// 		delete m_pBus_send_thread;
// 		m_pBus_send_thread = NULL;
// 	}
// 
// 	delete m_pSerial;
// 	m_pSerial = NULL;
}
BOOL CMainManager::init()
{
	TCHAR *path = new TCHAR[MAX_PATH];
	GetCurrentDirectory(MAX_PATH-50, path); 
	CString lpFileName(path); 
	lpFileName.Append(_T("\\UIpro.ini"));
	
	CString page1_ItemName[Cdata::DATA_PAGE1_ITEM_MAX - 0];
	//CString page5_ItemName[18];
	//CString Page5Name;

	page1_ItemName[0].Format(_T("Page1-Input"));
	page1_ItemName[Cdata::DATA_PAGE1_SYS_SEL].Format(_T("System Select"));
	page1_ItemName[Cdata::DATA_PAGE1_PRESET].Format(_T("Preset"));
	page1_ItemName[Cdata::DATA_PAGE1_INPUT].Format(_T("Input"));
	page1_ItemName[Cdata::DATA_PAGE1_DIGITAL].Format(_T("Digital"));
	page1_ItemName[Cdata::DATA_PAGE1_ANALOG].Format(_T("Analog"));
	page1_ItemName[Cdata::DATA_PAGE1_AUTODELAY].Format(_T("Auto Select Delay"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH1].Format(_T("CH1"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH2].Format(_T("CH2"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH3].Format(_T("CH3"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH4].Format(_T("CH4"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH5].Format(_T("CH5"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH6].Format(_T("CH6"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH7].Format(_T("CH7"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH8].Format(_T("CH8"));
	page1_ItemName[Cdata::DATA_PAGE1_TANDEM].Format(_T("Tandem"));

	int index = (int)Cdata::DATA_PAGE1_SYS_SEL;
	for(; index <= (int)Cdata::DATA_PAGE1_ANALOG; index++)
	{
		Storage.set_char_data(LSQ_GetPrivateProfileInt(page1_ItemName[0],page1_ItemName[index],0,lpFileName ), (Cdata::DATA_TYPE_ENUM)index);
	}
	for(; index <= (int)Cdata::DATA_PAGE1_SLIDER_CH8; index++)
	{
		Storage.set_int_data(LSQ_GetPrivateProfileInt(page1_ItemName[0],page1_ItemName[index],0,lpFileName ), (Cdata::DATA_TYPE_ENUM)index);
	}
	for(; index < (int)Cdata::DATA_PAGE1_ITEM_MAX; index++)
	{
		Storage.set_bool_data(LSQ_GetPrivateProfileInt(page1_ItemName[0],page1_ItemName[index],0,lpFileName ), (Cdata::DATA_TYPE_ENUM)index);
	}

	//Page5Name.Format(_T("page5"));
	////lpFileName.Format(_T("\\My Documents\\MMC.ini"));
	//page5_ItemName[0].Format(_T("page5_silderHx"));
	//page5_ItemName[1].Format(_T("page5_silderHy"));
	//page5_ItemName[2].Format(_T("page5_silder1x"));
	//page5_ItemName[3].Format(_T("page5_silder1y"));
	//page5_ItemName[4].Format(_T("page5_silder2x"));
	//page5_ItemName[5].Format(_T("page5_silder2y"));
	//page5_ItemName[6].Format(_T("page5_silder3x"));
	//page5_ItemName[7].Format(_T("page5_silder3y"));
	//page5_ItemName[8].Format(_T("page5_silder4x"));
	//page5_ItemName[9].Format(_T("page5_silder4y"));
	//page5_ItemName[10].Format(_T("page5_silder5x"));
	//page5_ItemName[11].Format(_T("page5_silder5y"));
	//page5_ItemName[12].Format(_T("page5_silder6x"));
	//page5_ItemName[13].Format(_T("page5_silder6y"));
	//page5_ItemName[14].Format(_T("page5_silder7x"));
	//page5_ItemName[15].Format(_T("page5_silder7y"));
	//page5_ItemName[16].Format(_T("page5_silderLx"));
	//page5_ItemName[17].Format(_T("page5_silderLy"));

	//for(int i=0; i<18; i++)
	//	Cdata::getInstance()->set_int_data(GetPrivateProfileInt(Page5Name,page5_ItemName[i],0,lpFileName ), (Cdata::DATA_TYPE_ENUM)(Cdata::DATA_PAGE5_SILDER_HX + i));



// 	if(is_init == false)
// 	{
// 		is_init = true;
// 
// 		m_pSerial = new CPSerialPort;
// 		m_pSerial->OpenPort(PortID,BaudRate,DataBits,StopBits,Parity);
// 	    
// 		//thread for common proccess 
// 		//m_pComm_proc_thread = AfxBeginThread(comm_process_thread, this);
// 
// 
// 		//thread for sending bus data
// 		m_pBus_send_thread = 
// 		(rmtBusSender*)AfxBeginThread(RUNTIME_CLASS(rmtBusSender), 
// 		THREAD_PRIORITY_HIGHEST, 0, CREATE_SUSPENDED);
// 		m_pBus_send_thread->setOwner(this);
// 		m_pBus_send_thread->m_bAutoDelete = false;
// 		m_pBus_send_thread->ResumeThread();
// 		//CeSetThreadPriority(98);
// 		CCommonData::getInstance()->set_bus_sender(m_pBus_send_thread);
// 
// 		//thread for receiving bus data
// 		m_pBus_receive_thread = 
// 		(rmtBusReceiver*)AfxBeginThread(RUNTIME_CLASS(rmtBusReceiver), 
// 		THREAD_PRIORITY_HIGHEST, 0, CREATE_SUSPENDED);
// 		m_pBus_receive_thread->setOwner(this);
// 		m_pBus_receive_thread->ResumeThread();
// 		//CeSetThreadPriority(97);
// 		return TRUE;
// 	}
// 	else
// 	{
// 		CCommonData::getInstance()->get_bus_sender()->send_key(PAGE_COMMON, 0x21);
// 		return FALSE;
// 	}
	return TRUE;

}

BOOL CMainManager::uninit()
{
	TCHAR *path = new TCHAR[MAX_PATH];
	GetCurrentDirectory(MAX_PATH-50, path); 
	CString lpFileName(path),pszIniFileTemp(path); 
	lpFileName.Append(_T("\\UIpro.ini"));
	pszIniFileTemp.Append(_T("\\UIpro.ini.tmp"));

	HANDLE hOutputFile = CreateFile(pszIniFileTemp,GENERIC_WRITE,0,(LPSECURITY_ATTRIBUTES)0, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);

	if(INVALID_HANDLE_VALUE == hOutputFile)
	{
		return FALSE;
	}

	///*CString Page5Name;
	//Page5Name.Format(_T("page5"));
	//CString page5_ItemName[18];
	//CString keyval[18];
	//int val[18];
	//page5_ItemName[0].Format(_T("page5_silderHx"));
	//page5_ItemName[1].Format(_T("page5_silderHy"));
	//page5_ItemName[2].Format(_T("page5_silder1x"));
	//page5_ItemName[3].Format(_T("page5_silder1y"));
	//page5_ItemName[4].Format(_T("page5_silder2x"));
	//page5_ItemName[5].Format(_T("page5_silder2y"));
	//page5_ItemName[6].Format(_T("page5_silder3x"));
	//page5_ItemName[7].Format(_T("page5_silder3y"));
	//page5_ItemName[8].Format(_T("page5_silder4x"));
	//page5_ItemName[9].Format(_T("page5_silder4y"));
	//page5_ItemName[10].Format(_T("page5_silder5x"));
	//page5_ItemName[11].Format(_T("page5_silder5y"));
	//page5_ItemName[12].Format(_T("page5_silder6x"));
	//page5_ItemName[13].Format(_T("page5_silder6y"));
	//page5_ItemName[14].Format(_T("page5_silder7x"));
	//page5_ItemName[15].Format(_T("page5_silder7y"));
	//page5_ItemName[16].Format(_T("page5_silderLx"));
	//page5_ItemName[17].Format(_T("page5_silderLy"));*/
	//for (int i=0; i<18; i++)
	//{
	//	val[i] = Cdata::getInstance()->get_int_data((Cdata::DATA_TYPE_ENUM)(Cdata::DATA_PAGE5_SILDER_HX + i));
	//	keyval[i].Format(_T("%d"),val[i]);
	//	WriteValue(hOutputFile,0,page5_ItemName[i],keyval[i]);
	//}


	CString page1_ItemName[Cdata::DATA_PAGE1_ITEM_MAX - 0];
	CString Tmpval[Cdata::DATA_PAGE1_ITEM_MAX];
	page1_ItemName[0].Format(_T("Page1-Input"));
	page1_ItemName[Cdata::DATA_PAGE1_SYS_SEL].Format(_T("System Select"));
	page1_ItemName[Cdata::DATA_PAGE1_PRESET].Format(_T("Preset"));
	page1_ItemName[Cdata::DATA_PAGE1_INPUT].Format(_T("Input"));
	page1_ItemName[Cdata::DATA_PAGE1_DIGITAL].Format(_T("Digital"));
	page1_ItemName[Cdata::DATA_PAGE1_ANALOG].Format(_T("Analog"));
	page1_ItemName[Cdata::DATA_PAGE1_AUTODELAY].Format(_T("Auto Select Delay"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH1].Format(_T("CH1"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH2].Format(_T("CH2"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH3].Format(_T("CH3"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH4].Format(_T("CH4"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH5].Format(_T("CH5"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH6].Format(_T("CH6"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH7].Format(_T("CH7"));
	page1_ItemName[Cdata::DATA_PAGE1_SLIDER_CH8].Format(_T("CH8"));
	page1_ItemName[Cdata::DATA_PAGE1_TANDEM].Format(_T("Tandem"));
	
	int index = Cdata::DATA_PAGE1_SYS_SEL;
	Tmpval[index].Format(_T("%d"),Storage.get_char_data((Cdata::DATA_TYPE_ENUM)index));
	WriteValue(hOutputFile,page1_ItemName[0],page1_ItemName[index],Tmpval[index]);
	index++;

	for(; index <= Cdata::DATA_PAGE1_TANDEM; index++)
	{
		if(index <= Cdata::DATA_PAGE1_ANALOG)
			Tmpval[index].Format(_T("%d"),Storage.get_char_data((Cdata::DATA_TYPE_ENUM)index));
		else if(index <= Cdata::DATA_PAGE1_SLIDER_CH8)
			Tmpval[index].Format(_T("%d"),Storage.get_int_data((Cdata::DATA_TYPE_ENUM)index));
		else
			Tmpval[index].Format(_T("%d"),Storage.get_bool_data((Cdata::DATA_TYPE_ENUM)index));

		WriteValue(hOutputFile,0,page1_ItemName[index],Tmpval[index]);
	}

	SetEndOfFile(hOutputFile );
	CloseHandle(hOutputFile);
	DeleteFile(lpFileName);
	CFile::Rename(pszIniFileTemp,lpFileName);

// 	if(is_init == true)
// 	{
// 		is_init = false;
// 		if(m_pBus_receive_thread != NULL)
// 		{
// 			m_pBus_receive_thread->PostThreadMessage(WM_QUIT,0,0);
// 			::WaitForSingleObject(m_pBus_receive_thread->m_hThread,INFINITE);
// 			delete m_pBus_receive_thread;
// 			m_pBus_receive_thread = NULL;
// 		}
// 		//TRACE(L"receive_thread exited\n");
// 
// 		if(m_pBus_send_thread != NULL)
// 		{
// 			m_pBus_send_thread->PostThreadMessage(WM_QUIT,0,0);
// 			::WaitForSingleObject(m_pBus_send_thread->m_hThread,INFINITE);
// 			delete m_pBus_send_thread;
// 			m_pBus_send_thread = NULL;
// 		}
// 		//TRACE(L"send_thread exited\n");
// 
// 		delete m_pSerial;
// 		m_pSerial = NULL;
// 		return TRUE;
// 	}
// 	else
// 	{
// 		return FALSE;
// 	}
		return TRUE;
}

/*
UINT CMainManager::comm_process_thread(LPVOID pParam)
{
	//CCommonData::SYS_STATUS_ENUM sys_status;
	//CMainManager * p_main_manager;

	//p_main_manager = (CMainManager *)pParam;

	while(1)
	{
#if 0
		sys_status = CCommonData::getInstance()->get_sys_status();
		//TRACE(L"the value is %d\n", sys_status);
		

		if( sys_status== CCommonData::SYS_WAIT_HAND)
		{
			if(CCommonData::getInstance()->get_bool_data(CCommonData::DATA_HAND_FLAG))
			{
				CCommonData::getInstance()->set_bool_data(false, CCommonData::DATA_HAND_FLAG);
				CCommonData::getInstance()->set_sys_status(CCommonData::SYS_HAND_OK);
			}
		}
		else if(sys_status == CCommonData::SYS_WAIT_PAGE)
		{
			if(CCommonData::getInstance()->get_bool_data(CCommonData::DATA_DISPLAY_END_FLAG))
			{
				CCommonData::getInstance()->set_bool_data(false, CCommonData::DATA_DISPLAY_END_FLAG);
				CCommonData::getInstance()->set_sys_status(CCommonData::SYS_PAGE_CHANGE);
			}
		}

		if(CCommonData::getInstance()->get_bool_data(CCommonData::DATA_POWER_DN_REQUEST))
		{
			CCommonData::getInstance()->set_bool_data(false, CCommonData::DATA_POWER_DN_REQUEST);
			p_main_manager->send_sleep_ready();
			//CCommonData::getInstance()->set_bool_data(true, CCommonData::DATA_SUB_PAGE_OUT);
			//CCommonData::getInstance()->set_bool_data(true, CCommonData::DATA_PAGE_OUT);
			CCommonData::getInstance()->set_sys_status(CCommonData::SYS_POWER_DOWN);
		}
#endif

		
		//TRACE(L"the value is %d\n", 1);
		Sleep(2000);
	}
	
	return 0;
}
*/

	
