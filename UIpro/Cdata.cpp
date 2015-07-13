#include "stdafx.h"
#include "Cdata.h"


class Cdata *Cdata::m_instance = NULL;
CCriticalSection Cdata::m_cs;
Cdata::Cdata(void)
{
}

Cdata::~Cdata(void)
{
}
class Cdata * Cdata::getInstance()
{
	m_cs.Lock();
	if (m_instance==NULL)
	{
		m_instance = new Cdata();
	}
	m_cs.Unlock();

	return m_instance;
}

BOOL Cdata::get_bool_data(Cdata::DATA_TYPE_ENUM data_type)
{
	BOOL temp;

	m_cs.Lock();
	switch(data_type)
	{
	case DATA_PAGE1_TANDEM:
		temp = m_Tandem;
		break;
	case DATA_NULL:
		break;

	default:
		break;
	}
	m_cs.Unlock();

	return temp;
}

void Cdata::set_bool_data(BOOL flag, Cdata::DATA_TYPE_ENUM data_type)
{
	m_cs.Lock();
	switch(data_type)
	{

	case DATA_PAGE1_TANDEM:
		m_Tandem = flag;
		break;

	case DATA_NULL:
		break;
	default:
		break;
	}
	m_cs.Unlock();
}

//unint
int Cdata::get_int_data(Cdata::DATA_TYPE_ENUM data_type)
{
	int temp;

	m_cs.Lock();
	if ((data_type >=DATA_PAGE5_SILDER_HX)&&(data_type <= DATA_PAGE5_SILDER_LY))
	{
		temp = m_pg5_silder[data_type - DATA_PAGE5_SILDER_HX];
	}

	switch(data_type)
	{
		case DATA_PAGE1_AUTODELAY:
			temp = m_AutoDelay;
			break;
		case DATA_PAGE1_SLIDER_CH1:
			temp = m_CH1;
			break;
		case DATA_PAGE1_SLIDER_CH2:
			temp = m_CH2;
			break;
		case DATA_PAGE1_SLIDER_CH3:
			temp = m_CH3;
			break;
		case DATA_PAGE1_SLIDER_CH4:
			temp = m_CH4;
			break;
		case DATA_PAGE1_SLIDER_CH5:
			temp = m_CH5;
			break;
		case DATA_PAGE1_SLIDER_CH6:
			temp = m_CH6;
			break;
		case DATA_PAGE1_SLIDER_CH7:
			temp = m_CH7;
			break;
		case DATA_PAGE1_SLIDER_CH8:
			temp = m_CH8;
			break;
		default:
			temp = 0;
			break;
	}
	m_cs.Unlock();

	return temp;
}

void Cdata::set_int_data(int val, Cdata::DATA_TYPE_ENUM data_type)
{
	m_cs.Lock();
	if ((data_type >=DATA_PAGE5_SILDER_HX)&&(data_type <= DATA_PAGE5_SILDER_LY))
	{
		m_pg5_silder[data_type - DATA_PAGE5_SILDER_HX] = val;;
	}
	switch(data_type)
	{
		case DATA_PAGE1_AUTODELAY:
			m_AutoDelay = val;
			break;
		case DATA_PAGE1_SLIDER_CH1:
			m_CH1 = val;
			break;
		case DATA_PAGE1_SLIDER_CH2:
			m_CH2 = val;
			break;
		case DATA_PAGE1_SLIDER_CH3:
			m_CH3 = val;
			break;
		case DATA_PAGE1_SLIDER_CH4:
			m_CH4 = val;
			break;
		case DATA_PAGE1_SLIDER_CH5:
			m_CH5 = val;
			break;
		case DATA_PAGE1_SLIDER_CH6:
			m_CH6 = val;
			break;
		case DATA_PAGE1_SLIDER_CH7:
			m_CH7 = val;
			break;
		case DATA_PAGE1_SLIDER_CH8:
			m_CH8 = val;
			break;
		default:
			break;
	}
	m_cs.Unlock();
}

// unchar
char Cdata::get_char_data(Cdata::DATA_TYPE_ENUM data_type)
{
	char temp;

	m_cs.Lock();
	switch(data_type)
	{
		case DATA_PAGE1_SYS_SEL:
			temp = m_SystemSel;
			break;
		case DATA_PAGE1_PRESET:
			temp = m_Preset;
			break;
		case DATA_PAGE1_INPUT:
			temp = m_Input;
			break;
		case DATA_PAGE1_DIGITAL:
			temp = m_Digital;
			break;
		case DATA_PAGE1_ANALOG:
			temp = m_Analog;
			break;
		case DATA_NULL:
		default:
			break;
	}
	m_cs.Unlock();

	return temp;
}

void Cdata::set_char_data(char val, Cdata::DATA_TYPE_ENUM data_type)
{
	m_cs.Lock();
	switch(data_type)
	{
		case DATA_PAGE1_SYS_SEL:
			m_SystemSel = val;
			break;
		case DATA_PAGE1_PRESET:
			m_Preset = val;
			break;
		case DATA_PAGE1_INPUT:
			m_Input = val;
			break;
		case DATA_PAGE1_DIGITAL:
			m_Digital = val;
			break;
		case DATA_PAGE1_ANALOG:
			m_Analog = val;
			break;
		case DATA_NULL:
		default:
			break;
	}
	m_cs.Unlock();
}

//Cstring
CString Cdata::get_Cstring_data(Cdata::DATA_TYPE_ENUM data_type)
{
	CString temp_string;

	m_cs.Lock();
	switch(data_type)
	{
	case DATA_NULL:
		break;
	default:
		break;
	}
	m_cs.Unlock();

	return temp_string;
}

void Cdata::set_Cstring_data(CString ver, Cdata::DATA_TYPE_ENUM data_type)
{
	m_cs.Lock();
	switch(data_type)
	{
	case DATA_NULL:
		break;
	default:
		break;
	}
	m_cs.Unlock();
}


