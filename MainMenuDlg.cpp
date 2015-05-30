
// MainMenuDlg.cpp : ʵ���ļ�
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


// CMainMenu �Ի���



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


// CMainMenu ��Ϣ�������

BOOL CMainMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMainMenu::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMainMenu::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMainMenu::OnBnClickedButtonStartGame()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GameRun game;
	this->ShowWindow(SW_HIDE);
	game.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CMainMenu::OnBnClickedButtonRanklist()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CRankList ranklist;
	//this->ShowWindow(SW_HIDE);
	ranklist.DoModal();
	//this->ShowWindow(SW_SHOW);
}


void CMainMenu::OnBnClickedButtonAboutUs()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	about_us about;
	//this->ShowWindow(SW_HIDE);
	about.DoModal();
	//this->ShowWindow(SW_SHOW);
}


void CMainMenu::OnBnClickedButtonExit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (AfxMessageBox(_T("��ȡ���뿪"),MB_OKCANCEL) == IDCANCEL)
		this->SendMessage(WM_CLOSE);
}
