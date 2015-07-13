#pragma once
#include <afxmt.h>
class Cdata
{
public:
	Cdata(void);
	~Cdata(void);
	typedef enum
	{
		DATA_NULL = 0,
		//page1 - input
		DATA_PAGE1_SYS_SEL,
		DATA_PAGE1_PRESET,
		DATA_PAGE1_INPUT,
		DATA_PAGE1_DIGITAL,
		DATA_PAGE1_ANALOG,
		DATA_PAGE1_AUTODELAY,
		DATA_PAGE1_SLIDER_CH1,
		DATA_PAGE1_SLIDER_CH2,
		DATA_PAGE1_SLIDER_CH3,
		DATA_PAGE1_SLIDER_CH4,
		DATA_PAGE1_SLIDER_CH5,
		DATA_PAGE1_SLIDER_CH6,
		DATA_PAGE1_SLIDER_CH7,
		DATA_PAGE1_SLIDER_CH8,
		DATA_PAGE1_TANDEM,
		DATA_PAGE1_ITEM_MAX,
		//page2
		//page5
		DATA_PAGE5_SILDER_HX,
		DATA_PAGE5_SILDER_HY,
		DATA_PAGE5_SILDER_1X,
		DATA_PAGE5_SILDER_1Y,
		DATA_PAGE5_SILDER_2X,
		DATA_PAGE5_SILDER_2Y,
		DATA_PAGE5_SILDER_3X,
		DATA_PAGE5_SILDER_3Y,
		DATA_PAGE5_SILDER_4X,
		DATA_PAGE5_SILDER_4Y,
		DATA_PAGE5_SILDER_5X,
		DATA_PAGE5_SILDER_5Y,
		DATA_PAGE5_SILDER_6X,
		DATA_PAGE5_SILDER_6Y,
		DATA_PAGE5_SILDER_7X,
		DATA_PAGE5_SILDER_7Y,
		DATA_PAGE5_SILDER_LX,
		DATA_PAGE5_SILDER_LY,
	}DATA_TYPE_ENUM;

	typedef enum
	{
		DATA_OPTION_NULL = 0,
		//page1 - input
		//		- SYSTEM SELECT
		DATA_OPTION_SYS_SEL_51CH,
		DATA_OPTION_SYS_SEL_61CH,
		DATA_OPTION_SYS_SEL_8CH,
		//      - PRESET
		DATA_OPTION_PRESET_1,
		DATA_OPTION_PRESET_2,
		DATA_OPTION_PRESET_3,
		//		- INPUT 
		DATA_OPTION_INPUT_ANALOG,
		DATA_OPTION_INPUT_DIGITAL,
		DATA_OPTION_INPUT_AUTO,
		//		- DIGITAL
		DATA_OPTION_DIGITAL_OPTICAL,
		DATA_OPTION_DIGITAL_COAX,
		DATA_OPTION_DIGITAL_BLUETOOTH,
		//		- ANALOG
		DATA_OPTION_ANALOG_RCA,
		DATA_OPTION_ANALOG_AUX,
		//		- AUTO DELAY
	}DATA_OPTION_ENUM;

	static class Cdata * getInstance();
	BOOL get_bool_data(DATA_TYPE_ENUM data_type);
	void set_bool_data(BOOL flag, DATA_TYPE_ENUM data_type);

	int get_int_data(DATA_TYPE_ENUM data_type);
	void set_int_data(int val, DATA_TYPE_ENUM data_type);

	char get_char_data(DATA_TYPE_ENUM data_type);
	void set_char_data(char val, DATA_TYPE_ENUM data_type);

	CString get_Cstring_data(DATA_TYPE_ENUM data_type);
	void set_Cstring_data(CString ver, DATA_TYPE_ENUM data_type);

private:
	static CCriticalSection m_cs;
	static class Cdata * m_instance;
//page1
private:
	char m_SystemSel;
	char m_Preset;

	char m_Input;
	char m_Digital;
	char m_Analog;

	int m_AutoDelay;

	int  m_CH1;
	int  m_CH2;
	int  m_CH3;
	int  m_CH4;
	int  m_CH5;
	int  m_CH6;
	int  m_CH7;
	int  m_CH8;
	BOOL m_Tandem;
//page2

//page3

//page4

//page5
private:
	int m_pg5_silder[18];
//page6

};
