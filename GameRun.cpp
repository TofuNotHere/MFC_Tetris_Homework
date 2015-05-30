// GameRun.cpp : 实现文件
//

#include "stdafx.h"
#include "GameRun.h"
#include "afxdialogex.h"
#include <atlconv.h>
using namespace std;


// GameRun 对话框

IMPLEMENT_DYNAMIC(GameRun, CDialogEx)

GameRun::GameRun(CWnd* pParent /*=NULL*/)
	: CDialogEx(GameRun::IDD, pParent)
	, m_score(_T(""))
	, m_rank(_T(""))
{

}

GameRun::~GameRun()
{
}

void GameRun::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOW_SCORE, m_score);
	DDX_Text(pDX, IDC_RANK_SHOW, m_rank);
}

BOOL GameRun::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	game = new Game();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


BEGIN_MESSAGE_MAP(GameRun, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BACKMAIN, &GameRun::OnBnClickedButtonBackmain)
	ON_BN_CLICKED(ID_START_STOP, &GameRun::OnBnClickedStartStop)
	ON_BN_CLICKED(ID_PAUSE_CONTINUE, &GameRun::OnBnClickedPauseContinue)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_STN_DBLCLK(IDC_STATIC_SCORE, &GameRun::OnStnDblclickStaticScore)
//	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// GameRun 消息处理程序

void GameRun::OnBnClickedButtonBackmain()
{
	// TODO:  在此添加控件通知处理程序代码
	if (AfxMessageBox(_T("do you realy want exit?"), MB_OKCANCEL) == IDOK)
		this->SendMessage(WM_CLOSE);
}


void GameRun::OnBnClickedStartStop()
{
	game->StartAndStop();
	// TODO:  在此添加控件通知处理程序代码
	if (game->GetGameState() == RUN)
		SetTimer(1, game->GetGamerank_Timer(), NULL);
	if (game->GetGameState() == STOP)
		KillTimer(1);
}


void GameRun::OnBnClickedPauseContinue()
{
	game->PauseAndContinue();
	// TODO:  在此添加控件通知处理程序代码
	if (game->GetGameState() == PAUSE)
		KillTimer(1);
	else if (game->GetGameState() == RUN)
		SetTimer(1, game->GetGamerank_Timer(), NULL);
}


BOOL GameRun::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && game->GetGameState() == RUN)
		OnKeyDown((UINT)pMsg->wParam);

	return CDialogEx::PreTranslateMessage(pMsg);
}

void GameRun::OnKeyDown(UINT nChar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	game->OnInput(nChar);
	Invalidate(true);
}

void GameRun::DrawNextBlock()
{
	CRect rect;
	CWnd *wnd = GetDlgItem(IDC_NEXT_BLOCK);
	wnd->GetClientRect(&rect);
	CPaintDC dc(wnd);

	CBrush brush_org(RGB(255, 159, 0));
	CBrush brush_gre(RGB(0, 216, 86));
	CBrush brush_rad(RGB(193, 29, 29));
	CBrush brush_blu(RGB(61, 205, 229));
	CBrush brush_pup(RGB(199, 9, 203));
	CBrush brush_aro(RGB(49, 192, 197));
	CBrush brush_yel(RGB(230, 235, 106));
	CBrush brush_wit(RGB(0, 0, 0));
	CBrush *brush = &brush_wit;
	if (game->GetNextBlock())
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (game->GetNextBlock()[i * 4 + j].hasBlock == 1)
				{
					switch (game->GetNextBlock()[i * 4 + j].color){
					case 1:brush = &brush_pup; break;
					case 2:brush = &brush_blu; break;
					case 3:brush = &brush_org; break;
					case 4:brush = &brush_rad; break;
					case 5:brush = &brush_gre; break;
					case 6:brush = &brush_aro; break;
					case 7:brush = &brush_yel; break;
					}
					dc.FillRect(CRect(
						j*rect.Width() / 4,
						i*rect.Height() / 4,
						(j + 1)*rect.Width() / 4,
						(i + 1)*rect.Height() / 4),
						brush);
				}
	wnd->RedrawWindow();
}

void GameRun::DrawBackground()
{
	CRect rect;
	CWnd *wnd = GetDlgItem(IDC_GAME_BACKGROUND);
	CPaintDC dc(wnd);
	CBrush brush_org(RGB(255, 159, 0));
	CBrush brush_gre(RGB(0, 216, 86));
	CBrush brush_rad(RGB(193, 29, 29));
	CBrush brush_blu(RGB(61, 205, 229));
	CBrush brush_pup(RGB(199, 9, 203));
	CBrush brush_aro(RGB(49, 192, 197));
	CBrush brush_yel(RGB(230, 235, 106));
	CBrush brush_wit(RGB(0,0,0));
	CBrush *brush = &brush_wit;
	wnd->GetClientRect(&rect);
	if (game->GetBackground()){
		Block_Show *temp = game->GetBackground();
		for (int i = 0; i < game->GetHeight(); i++)
			for (int j = 0; j < game->GetWidth(); j++)
				if (temp[i*(game->GetWidth()) + j].hasBlock == 1)
				{
					switch (temp[i*(game->GetWidth()) + j].color){
					case 1:brush = &brush_pup; break;
					case 2:brush = &brush_blu; break;
					case 3:brush = &brush_org; break;
					case 4:brush = &brush_rad; break;
					case 5:brush = &brush_gre; break;
					case 6:brush = &brush_aro; break;
					case 7:brush = &brush_yel; break;
					}
					dc.FillRect(CRect
						(j*rect.Width() / game->GetWidth(),
						i*rect.Height() / game->GetHeight(),
						(j + 1)*rect.Width() / game->GetWidth(),
						(i + 1)*rect.Height() / game->GetHeight()),
						brush);
				}
	}
	wnd->RedrawWindow();
}

//void GameRun::DrawMoveingBlock()
//{
//	CRect rect;
//	CWnd *wnd = GetDlgItem(IDC_GAME_BACKGROUND);
//	CPaintDC dc(wnd);
//
//	wnd->GetClientRect(&rect);
//	if (game->GetBlocks()){
//		int *temp = game->GetBlocks();
//		for (int i = game->GetLoc_Y(); i < game->GetLoc_Y() + 4; i++)
//			for (int j = game->GetLoc_X(); j < game->GetLoc_X() + 4; j++)
//				if (temp[(i - game->GetLoc_Y()) * 4 + j - game->GetLoc_X()] == 1)
//				{
//					dc.Rectangle(
//						j*rect.Width() / game->GetWidth(),
//						i*rect.Height() / game->GetHeight(),
//						(j + 1)*rect.Width() / game->GetWidth(),
//						(i + 1)*rect.Height() / game->GetHeight());
//					dc.Rectangle(0, 0, 100, 100);
//				}
//	}
//	wnd->RedrawWindow();
//}

void GameRun::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	if (!game->Run()){
		KillTimer(1);
		if (AfxMessageBox(_T("Game Over!"), MB_OK)){
			CNameInput nameinput;
			if (nameinput.DoModal() == IDOK){
				 fstream f;
				 f.open("RankList.dat", ios::app|ios::binary);
				 if (f.fail())
					 AfxMessageBox(_T("抱歉，保存排行榜出错"));
				 else{
					 USES_CONVERSION;
					 ScoreSave datasave(T2A(nameinput.m_name), game->GetGameScore().c_str());
					 f.write((char*)&datasave, sizeof(ScoreSave));
					// f << datasave.name << " " << datasave.score << endl;
				 }
			}
		}
	}
	Invalidate(true);
	m_score = game->GetGameScore().c_str();
	m_rank = game->GetGameRank().c_str();
	if (game->isLevelUp()){
		KillTimer(1);
		SetTimer(1, game->GetGamerank_Timer(), NULL);
	}

	UpdateData(false);
}

void GameRun::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint();
	DrawBackground();
	DrawNextBlock();
	//DrawMoveingBlock();
}

void GameRun::OnStnDblclickStaticScore()
{
	// TODO:  在此添加控件通知处理程序代码
	CRankList rank;
	rank.DoModal();
}

