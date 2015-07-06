#pragma once


// m_page6 dialog

class m_page6 : public CDialog
{
	DECLARE_DYNAMIC(m_page6)

public:
	m_page6(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page6();

// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
