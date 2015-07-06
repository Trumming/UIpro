#pragma once


// m_page3 dialog

class m_page3 : public CDialog
{
	DECLARE_DYNAMIC(m_page3)

public:
	m_page3(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page3();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
