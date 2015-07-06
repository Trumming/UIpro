#pragma once

class knob :public CStatic
{
public:
	knob(void);
public:
	~knob(void);

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT uParam,CPoint point);
	bool isActive(void);

	DECLARE_MESSAGE_MAP()

public:
	int m_val;
	bool m_bActive;
	bool m_bFreshScale;
};
