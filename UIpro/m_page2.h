#pragma once
#include "knob.h"

// m_page2 dialog

class m_page2 : public CDialog
{
	DECLARE_DYNAMIC(m_page2)

public:
	m_page2(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page2();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()

public:
	knob m_knob11;
	knob m_knob12;
	knob m_knob13;
	knob m_knob14;
	knob m_knob15;
	knob m_knob16;
	knob m_knob17;
	knob m_knob18;
	knob m_knob21;
	knob m_knob22;
	knob m_knob23;
	knob m_knob24;
	knob m_knob25;
	knob m_knob26;
	knob m_knob27;
	knob m_knob28;
	knob m_knob31;
	knob m_knob32;
	knob m_knob33;
	knob m_knob34;
	knob m_knob35;
	knob m_knob36;
	knob m_knob37;
	knob m_knob38;
	knob m_knob41;
	knob m_knob42;
	knob m_knob43;
	knob m_knob44;
	knob m_knob45;
	knob m_knob46;
	knob m_knob47;
	knob m_knob48;
	knob m_knob51;
	knob m_knob52;
	knob m_knob53;
	knob m_knob54;
	knob m_knob55;
	knob m_knob56;
	knob m_knob57;
	knob m_knob58;
	knob m_knob61;
	knob m_knob62;
	knob m_knob63;
	knob m_knob64;
	knob m_knob65;
	knob m_knob66;
	knob m_knob67;
	knob m_knob68;
};
