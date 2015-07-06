#pragma once


// m_page1 dialog

class m_page1 : public CDialog
{
	DECLARE_DYNAMIC(m_page1)

public:
	m_page1(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_page1();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
