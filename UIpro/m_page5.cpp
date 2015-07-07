// m_page5.cpp : implementation file
//

#include "stdafx.h"
#include "UIpro.h"
#include "m_page5.h"


// m_page5 dialog

IMPLEMENT_DYNAMIC(m_page5, CDialog)

m_page5::m_page5(CWnd* pParent /*=NULL*/)
	: CDialog(m_page5::IDD, pParent)
{
	m_curSlider = NULL;
	m_bIsUp = true;
	m_bIsReady = true;
}

m_page5::~m_page5()
{
	KillTimer(TIMER1);
}


void m_page5::OnPaint() 
{
	CDialog::OnPaint();
	ProMoveMsg();
	SetTimer(TIMER2,10,0);
	SetTimer(TIMER3,20,0);
	SetTimer(TIMER4,30,0);
	SetTimer(TIMER5,60,0);
	SetTimer(TIMER6,100,0);
}
void m_page5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_EQ1, m_slider1);
	DDX_Control(pDX, IDC_SLIDER_EQ2, m_slider2);
	DDX_Control(pDX, IDC_SLIDER_EQ3, m_slider3);
	DDX_Control(pDX, IDC_SLIDER_EQ4, m_slider4);
	DDX_Control(pDX, IDC_SLIDER_EQ5, m_slider5);
	DDX_Control(pDX, IDC_SLIDER_EQ6, m_slider6);
	DDX_Control(pDX, IDC_SLIDER_EQ7, m_slider7);
	DDX_Control(pDX, IDC_SLIDER_EQL, m_sliderl);
	DDX_Control(pDX, IDC_SLIDER_EQH, m_sliderh);
	DDX_Control(pDX, IDC_STATIC51, m_drawline);

	DDX_Control(pDX, IDC_SLIDER1, m_SliderTester);
}


BEGIN_MESSAGE_MAP(m_page5, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

BOOL m_page5::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_SliderTester.SetRange(0,100);
	m_SliderTester.SetTicFreq(5);
	m_SliderTester.SetPos(50);

	SetTimer(TIMER1,50,0);
	m_slider1.SetBitmapIndex(IDB_EQ1);
	m_slider2.SetBitmapIndex(IDB_EQ2);
	m_slider3.SetBitmapIndex(IDB_EQ3);
	m_slider4.SetBitmapIndex(IDB_EQ4);
	m_slider5.SetBitmapIndex(IDB_EQ5);
	m_slider6.SetBitmapIndex(IDB_EQ6);
	m_slider7.SetBitmapIndex(IDB_EQ7);
	m_sliderl.SetBitmapIndex(IDB_EQL);
	m_sliderh.SetBitmapIndex(IDB_EQH);
	
	m_slider1.x = 113;//118
	m_slider1.y = 143;
	
	m_sliderh.x = 162;
	m_sliderh.y = 143;

	m_slider2.x = 220;
	m_slider2.y = 143;
	m_slider3.x = 325;
	m_slider3.y = 143;
	m_slider4.x = 421;
	m_slider4.y = 143;
	m_slider5.x = 535;
	m_slider5.y = 143;
	m_slider6.x = 615;
	m_slider6.y = 143;
	m_slider7.x = 730;
	m_slider7.y = 143;

	m_sliderl.x = 805;
	m_sliderl.y = 143;

	//AllocConsole();
	m_drawline.Init();
	m_bInit = true;
	ProMoveMsg();
	UpdateData( FALSE );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void m_page5::OnMouseMove(UINT nFlags, CPoint point) 
{
	//获取点击的EQ按钮
	GetCurrentCStatic();

	if((!m_curSlider)||(m_bIsUp)) return;

	//背景坐标偏移处理
	CRect bkrect;
	m_drawline.GetClientRect(&bkrect);
	/*bkrect.left += 350;
	bkrect.right += 280;
	bkrect.top += 60;
	bkrect.bottom += 0;*/

	bkrect.left += 415;
	bkrect.right += 235;
	bkrect.top += 60;
	bkrect.bottom += 0;

	//按钮移动范围限制
	if(point.x < bkrect.left)
		point.x = bkrect.left;
	if(point.x > bkrect.right)
		point.x = bkrect.right;
	if(point.y < bkrect.top)
		point.y = bkrect.top;
	if(point.y > bkrect.bottom)
		point.y = bkrect.bottom;

	//移动
	CRect r,rect;
	GetClientRect(&r);
	if(PtInRect(&r,point))
	{
		 m_curSlider->GetClientRect(&rect);
         int Width = rect.right - rect.left ;
		 int Hejght = rect.bottom - rect.top ;
		 CPoint  pt;
		 if((m_curSlider == &m_sliderl)||(m_curSlider == &m_sliderh))
		 {
			pt.x = point.x;
			pt.y = 189;
		 }
		 else
		 {
			 pt.x = point.x;
			 pt.y = point.y;
		 }
		 CSize sz(Width,Hejght); 
		 CRect  rect2(pt,sz);
		 m_curSlider->MoveWindow(&rect2);
		 m_curSlider->x = point.x - 300;
		 if((m_curSlider == &m_sliderl)||(m_curSlider == &m_sliderh))
		 {
			 m_curSlider->y = 189;
		 }
		 else
		 {
			 m_curSlider->y = point.y - 40;
		 }
		 
		 ProMoveMsg();
	
	}
	//CDialog::OnMouseMove(nFlags, point);
}

void m_page5::GetCurrentCStatic()
{
	m_curSlider = NULL;
	if(m_slider1.IsActive())
		m_curSlider = &m_slider1;
	if(m_slider2.IsActive())
		m_curSlider = &m_slider2;
	if(m_slider3.IsActive())
		m_curSlider = &m_slider3;
	if(m_slider4.IsActive())
		m_curSlider = &m_slider4;
	if(m_slider5.IsActive())
		m_curSlider = &m_slider5;
	if(m_slider6.IsActive())
		m_curSlider = &m_slider6;
	if(m_slider7.IsActive())
		m_curSlider = &m_slider7;
	if(m_sliderl.IsActive())
		m_curSlider = &m_sliderl;
	if(m_sliderh.IsActive())
		m_curSlider = &m_sliderh;
}

void m_page5::OnTimer(UINT nIDEvent)
{
	switch(nIDEvent)
	{
		case TIMER1: 
			m_bIsReady = true; 
			break;
		case TIMER2: 
			ProMoveMsg(); 
			KillTimer(TIMER2);
			break;
		case TIMER3: 
			ProMoveMsg(); 
			KillTimer(TIMER3);
			break;
		case TIMER4: 
			ProMoveMsg(); 
			KillTimer(TIMER4);
			break;
		case TIMER5: 
			ProMoveMsg(); 
			KillTimer(TIMER5);
			break;
		case TIMER6: 
			ProMoveMsg(); 
			KillTimer(TIMER6);
			break;

	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

BOOL m_page5::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_MOUSEMOVE)
    {
		if (m_bIsReady)
		{
			m_bIsReady = false;
			ScreenToClient(&(pMsg->pt));
			OnMouseMove(1,pMsg->pt);
		}
	}
	else if(pMsg->message == WM_LBUTTONUP)
	{
		if(m_curSlider)
			m_curSlider->m_bIsActive = false;
		m_bIsUp = true;
	}
	else if(pMsg->message == WM_LBUTTONDOWN)
	{
		m_bIsUp = false;
	}
    return CDialog::PreTranslateMessage(pMsg);
}


void m_page5::ProMoveMsg()
{	
	if((m_slider1.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos1, m_slider1.x, m_slider1.y);
		m_drawline.m_Cslider[1].x = m_slider1.x - 5;
		m_drawline.m_Cslider[1].y =  m_slider1.y- 15;
	}
	if((m_slider2.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos2, m_slider2.x, m_slider2.y);
		m_drawline.m_Cslider[2].x = m_slider2.x - 5;
		m_drawline.m_Cslider[2].y =  m_slider2.y - 15;
	}
	if((m_slider3.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos3, m_slider3.x, m_slider3.y);
		m_drawline.m_Cslider[3].x = m_slider3.x - 5;
		m_drawline.m_Cslider[3].y =  m_slider3.y - 15;
	}
	if((m_slider4.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos4, m_slider4.x, m_slider4.y);
		m_drawline.m_Cslider[4].x = m_slider4.x - 5;
		m_drawline.m_Cslider[4].y =  m_slider4.y - 15;
	}
	if((m_slider5.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos5, m_slider5.x, m_slider5.y);
		m_drawline.m_Cslider[5].x = m_slider5.x - 5;
		m_drawline.m_Cslider[5].y =  m_slider5.y - 15;
	}
	if((m_slider6.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos6, m_slider6.x, m_slider6.y);
		m_drawline.m_Cslider[6].x = m_slider6.x - 5;
		m_drawline.m_Cslider[6].y =  m_slider6.y - 15;
	}
	if((m_slider7.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.pos7, m_slider7.x, m_slider7.y);
		m_drawline.m_Cslider[7].x = m_slider7.x - 5;
		m_drawline.m_Cslider[7].y =  m_slider7.y - 15;
	}
	if((m_sliderl.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.posl, m_sliderl.x, m_sliderl.y);
		m_drawline.m_Cslider[8].x = m_sliderl.x - 5;
		m_drawline.m_Cslider[8].y = YOFFSET - 15;
	}
	if((m_sliderh.IsActive())||(m_bInit))
	{
		m_drawline.prodata(m_drawline.posh, m_sliderh.x, m_sliderh.y);
		m_drawline.m_Cslider[0].x = m_sliderh.x - 5;
		m_drawline.m_Cslider[0].y = YOFFSET - 15;
	}

	m_bInit = false;
	m_drawline.calculateline();
	m_drawline.draw();

}
