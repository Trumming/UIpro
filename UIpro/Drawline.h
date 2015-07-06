#pragma once

#define YOFFSET 142
#define XOFFSET 48

class CDrawline :
	public CStatic
{
public:
	CDrawline(void);
	~CDrawline(void);
	void draw();
	void Init();
	void prodata(int *pdata,int x,int y);
	void calculateline();

protected:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	CDC *pDC;
	CPen *pen1;
	CPen *pen2;
	CPoint *data;
	CPoint m_pointLow;
	CPoint m_pointHigh;
	int pos1[200];
	int pos2[200];
	int pos3[200];
	int pos4[200];
	int pos5[200];
	int pos6[200];
	int pos7[200];
	int posh[200];
	int posl[200];
	int pos[200];
	int *changepos;
	CDC MemDC;
	CPoint m_Cslider[9];
};
