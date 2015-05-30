
// MainMenuDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "MainMenu.h"
#include "MainMenuDlg.h"
#include "GameRun.h"
#include "RankList.h"
#include "about_us.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainMenu 对话框



CMainMenu::CMainMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainMenu::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMainMenu, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START_GAME, &CMainMenu::OnBnClickedButtonStartGame)
	ON_BN_CLICKED(IDC_BUTTON_RANKLIST, &CMainMenu::OnBnClickedButtonRanklist)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT_US, &CMainMenu::OnBnClickedButtonAboutUs)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMainMenu::OnBnClickedButtonExit)
END_MESSAGE_MAP()


// CMainMenu 消息处理程序

BOOL CMainMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMainMenu::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMainMenu::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMainMenu::OnBnClickedButtonStartGame()
{
	// TODO:  在此添加控件通知处理程序代码
	GameRun game;
	this->ShowWindow(SW_HIDE);
	game.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CMainMenu::OnBnClickedButtonRanklist()
{
	// TODO:  在此添加控件通知处理程序代码
	CRankList ranklist;
	//this->ShowWindow(SW_HIDE);
	ranklist.DoModal();
	//this->ShowWindow(SW_SHOW);
}


void CMainMenu::OnBnClickedButtonAboutUs()
{
	// TODO:  在此添加控件通知处理程序代码
	about_us about;
	//this->ShowWindow(SW_HIDE);
	about.DoModal();
	//this->ShowWindow(SW_SHOW);
}


void CMainMenu::OnBnClickedButtonExit()
{
	// TODO:  在此添加控件通知处理程序代码
	if (AfxMessageBox(_T("点取消离开"),MB_OKCANCEL) == IDCANCEL)
		this->SendMessage(WM_CLOSE);
}
