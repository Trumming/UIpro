#include "stdafx.h"
#include "Drawline.h"
#include "UIpro.h"


#define  PI 3.1415

CDrawline::CDrawline(void)
{
	changepos = NULL;
}

CDrawline::~CDrawline(void)
{
	pen1->DeleteObject();//释放笔资源
	pen2->DeleteObject();//释放笔资源
	ReleaseDC(pDC);
}
BEGIN_MESSAGE_MAP(CDrawline, CStatic)
	//ON_WM_PAINT()
END_MESSAGE_MAP()
void CDrawline::Init()
{
	pDC = GetDC();
	pen1 = new CPen(BS_SOLID,2,RGB(255,255,0));
	pen2 = new CPen(PS_SOLID,1,RGB(0,255,124));
}


void CDrawline::OnPaint()
{
	draw();
	//return CStatic::OnPaint();
}

BOOL CDrawline::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}
void CDrawline::draw()
{
	//创建一个内存中的显示设备
    MemDC.CreateCompatibleDC(pDC); 
    CBitmap MemBitmap;
    MemBitmap.CreateCompatibleBitmap(pDC, 870, 420);
    MemDC.SelectObject(&MemBitmap);
	MemDC.FillSolidRect(0, 0, 870, 420, RGB(0,0,0));
	

	//画背景
	MemDC.SetTextColor(RGB(255,255,0));
    MemDC.TextOut(5, 7, _T("+12dB"));
    MemDC.TextOut(5, 71, _T(" +6dB"));
    MemDC.TextOut(5, 135, _T("       0"));
	MemDC.TextOut(5, 200, _T(" -6dB"));
	MemDC.TextOut(5, 260, _T("-12dB"));
	MemDC.TextOut(5, 325, _T("-18dB"));
	MemDC.TextOut(5, 384, _T("-24dB"));

	MemDC.TextOut(97, 400, _T("20Hz"));
	MemDC.TextOut(207, 400, _T("50Hz"));
	MemDC.TextOut(260, 400, _T("100Hz"));
	MemDC.TextOut(324, 400, _T("200Hz"));
	MemDC.TextOut(434, 400, _T("500Hz"));
	MemDC.TextOut(493, 400, _T("1KHz"));
	MemDC.TextOut(555, 400, _T("2KHz"));
	MemDC.TextOut(662, 400, _T("5KHz"));
	MemDC.TextOut(713, 400, _T("10KHz"));
	MemDC.TextOut(782, 400, _T("20KHz"));

	for(int i=0; i<200; i++)
	{
		MemDC.FillSolidRect(XOFFSET+i*4, YOFFSET,4,changepos[i]-YOFFSET,RGB(60,60,60));
	}

	MemDC.SelectObject(*pen2);
	MemDC.MoveTo(48, 14);
	MemDC.LineTo(48, 398);
	MemDC.MoveTo(118, 14);
	MemDC.LineTo(118, 398);
	MemDC.MoveTo(165, 14);
	MemDC.LineTo(165, 398);
	MemDC.MoveTo(198, 14);
	MemDC.LineTo(198, 398);
	MemDC.MoveTo(225, 14);
	MemDC.LineTo(225, 398);
	MemDC.MoveTo(242, 14);
	MemDC.LineTo(242, 398);
	MemDC.MoveTo(253, 14);
	MemDC.LineTo(253, 398);
	MemDC.MoveTo(262, 14);
	MemDC.LineTo(262, 398);
	MemDC.MoveTo(270, 14);
	MemDC.LineTo(270, 398);
	MemDC.MoveTo(277, 14);
	MemDC.LineTo(277, 398);
	MemDC.MoveTo(345, 14);
	MemDC.LineTo(345, 398);
	MemDC.MoveTo(392, 14);
	MemDC.LineTo(392, 398);
	MemDC.MoveTo(426, 14);
	MemDC.LineTo(426, 398);
	MemDC.MoveTo(452, 14);
	MemDC.LineTo(452, 398);
	MemDC.MoveTo(469, 14);
	MemDC.LineTo(469, 398);
	MemDC.MoveTo(480, 14);
	MemDC.LineTo(480, 398);
	MemDC.MoveTo(489, 14);
	MemDC.LineTo(489, 398);
	MemDC.MoveTo(497, 14);
	MemDC.LineTo(497, 398);
	MemDC.MoveTo(505, 14);
	MemDC.LineTo(505, 398);
	MemDC.MoveTo(570, 14);
	MemDC.LineTo(570, 398);
	MemDC.MoveTo(616, 14);
	MemDC.LineTo(616, 398);
	MemDC.MoveTo(650, 14);
	MemDC.LineTo(650, 398);
	MemDC.MoveTo(677, 14);
	MemDC.LineTo(677, 398);
	MemDC.MoveTo(693, 14);
	MemDC.LineTo(693, 398);
	MemDC.MoveTo(704, 14);
	MemDC.LineTo(704, 398);
	MemDC.MoveTo(713, 14);
	MemDC.LineTo(713, 398);
	MemDC.MoveTo(721, 14);
	MemDC.LineTo(721, 398);
	MemDC.MoveTo(730, 14);
	MemDC.LineTo(730, 398);
	MemDC.MoveTo(713, 14);
	MemDC.LineTo(713, 398);
	MemDC.MoveTo(802, 14);
	MemDC.LineTo(802, 398);
	MemDC.MoveTo(849, 14);
	MemDC.LineTo(849, 398);

	MemDC.MoveTo(48, 14);
	MemDC.LineTo(849, 14);
	MemDC.MoveTo(48, 46);
	MemDC.LineTo(849, 46);
	MemDC.MoveTo(48, 78);
	MemDC.LineTo(849, 78);
	MemDC.MoveTo(48, 110);
	MemDC.LineTo(849, 110);
	MemDC.MoveTo(48, 142);
	MemDC.LineTo(849, 142);
	MemDC.MoveTo(48, 174);
	MemDC.LineTo(849, 174);
	MemDC.MoveTo(48, 206);
	MemDC.LineTo(849, 206);
	MemDC.MoveTo(48, 238);
	MemDC.LineTo(849, 238);
	MemDC.MoveTo(48, 270);
	MemDC.LineTo(849, 270);
	MemDC.MoveTo(48, 302);
	MemDC.LineTo(849, 302);
	MemDC.MoveTo(48, 334);
	MemDC.LineTo(849, 334);
	MemDC.MoveTo(48, 366);
	MemDC.LineTo(849, 366);
	MemDC.MoveTo(48, 398);
	MemDC.LineTo(849, 398);


	//以下设置DC
	//以下移动直线
	MemDC.SelectObject(*pen1);
	MemDC.MoveTo(40, pos[0]);
	for(int i=0; i<200; i++)
	{
		MemDC.LineTo(XOFFSET+i*4, pos[i]);
	}

	MemDC.FillSolidRect(0, 0,1,1,RGB(0,0,255));
	MemDC.SetTextColor(RGB(255,255,0));
	MemDC.TextOut(m_Cslider[0].x, m_Cslider[0].y, _T(" H "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(0,46,255));
	MemDC.SetTextColor(RGB(255,255,0));
	MemDC.TextOut(m_Cslider[1].x, m_Cslider[1].y, _T(" 1 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(99,0,255));
	MemDC.SetTextColor(RGB(255,120,80));
	MemDC.TextOut(m_Cslider[2].x, m_Cslider[2].y, _T(" 2 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(255,0,255));
	MemDC.SetTextColor(RGB(0,120,80));
	MemDC.TextOut(m_Cslider[3].x, m_Cslider[3].y, _T(" 3 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(0,255,0));
	MemDC.SetTextColor(RGB(255,120,80));
	MemDC.TextOut(m_Cslider[4].x, m_Cslider[4].y, _T(" 4 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(255,0,0));
	MemDC.SetTextColor(RGB(255,120,80));
	MemDC.TextOut(m_Cslider[5].x, m_Cslider[5].y, _T(" 5 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(0,0,255));
	MemDC.SetTextColor(RGB(255,120,80));
	MemDC.TextOut(m_Cslider[6].x, m_Cslider[6].y, _T(" 6 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(26,49,67));
	MemDC.SetTextColor(RGB(255,120,80));
	MemDC.TextOut(m_Cslider[7].x, m_Cslider[7].y, _T(" 7 "));
	MemDC.FillSolidRect(0, 0,1,1,RGB(0,31,67));
	MemDC.SetTextColor(RGB(255,120,80));
	MemDC.TextOut(m_Cslider[8].x, m_Cslider[8].y, _T(" L "));
	pDC->BitBlt(0, 0, 870, 420, &MemDC, 0, 0, SRCCOPY); 
	MemDC.DeleteDC();
}

void CDrawline::prodata(int *pdata,int x,int y)
{
	//ui_trace("CDrawline::prodata \n");
	changepos = pdata;
	if(pdata == posl)
	{
		for(int i=0; i<200; i++)
		{
			int posx;
			posx = XOFFSET + i*4;
			if(posx > (x-160))
				pdata[i] = YOFFSET +(posx - x + 160)*(posx - x + 160)/110;
			else
				pdata[i] = YOFFSET;
		}
	}
	else if(pdata == posh)
	{
		for(int i=0; i<200; i++)
		{
			int posx;
			posx = XOFFSET + i*4;
			if(posx < (x+50))
				pdata[i] = YOFFSET +(posx -x-50)*(posx -x-50)/140;
			else
				pdata[i] = YOFFSET;
		}
	}
	else
	{
		int posx;
		double a = 0.135,u,px,py,C;
		if(y < YOFFSET)
		{
			py = (double)(YOFFSET - y);
			C = (double)((sqrt(2*PI))*py*a);
			u = (double)x/400;
			for(int i=0; i<200; i++)
			{
				posx = XOFFSET + i*4;				
				px = (double)posx/400;
				pdata[i] =YOFFSET - int(C*exp(0-(double)((px - u)*(px - u)/(2*a*a)))/(sqrt(2*PI)*a)) ;
			}
		}
		else if (y > YOFFSET)
		{
			py = (double)(y - YOFFSET);
			C = (double)((sqrt(2*PI))*py*a);
			for(int i=0; i<200; i++)
			{
				posx = XOFFSET + i*4;
				u = (double)x/400;
				px = (double)posx/400;
				pdata[i] =YOFFSET + int(C*exp(0-(double)((px - u)*(px - u)/(2*a*a)))/(sqrt(2*PI)*a));
			}
		}
		else
		{
			for(int i=0; i<200; i++)
			{
				pdata[i] =YOFFSET;
			}
		}
	}

}

void CDrawline::calculateline()
{
	for(int i=0;i<200;i++)
	{
		pos[i] = pos1[i] + pos2[i] + pos3[i] + pos4[i] + pos5[i] + pos6[i] + pos7[i]+ posl[i] + posh[i]- 8*YOFFSET;
	}
}