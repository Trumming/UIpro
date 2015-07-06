#pragma once


// m_page4 dialog

class m_page4 : public CDialog
{
	DECLARE_DYNAMIC(m_page4)

public:
	m_page4(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page4();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
