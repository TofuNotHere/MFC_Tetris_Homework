#pragma once
#include "Game.h"
#include "MainMenu.h"
#include "NameInput.h"
#include "RankList.h"
#include <fstream>
#define D_CRT_SECURE_NO_WARNINGS


// GameRun 对话框

class GameRun : public CDialogEx
{
	DECLARE_DYNAMIC(GameRun)

public:
	GameRun(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GameRun();

// 对话框数据
	enum { IDD = IDD_GAME_RUN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBackmain();
	afx_msg void OnBnClickedStartStop();
	afx_msg void OnBnClickedPauseContinue();
	afx_msg void OnKeyDown(UINT nChar);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void DrawNextBlock();
	afx_msg void DrawBackground();
	//afx_msg void DrawMoveingBlock();
	virtual BOOL OnInitDialog();

private:
	Game *game;
	CString m_score;
	CString m_rank;
	struct ScoreSave{
		char name[20];
		char score[5];
		ScoreSave(){};
		ScoreSave(char * _name, const char* _score){
			strcpy(name, _name);
			strcpy(score, _score);
		}
		bool operator < (const ScoreSave & right) const {
			return atoi(score) > atoi(right.score);
		}
	};
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnStnDblclickStaticScore();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
