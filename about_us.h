#pragma once
#include "MainMenu.h"
#include "MainMenuDlg.h"

// about_us 对话框

class about_us : public CDialogEx
{
	DECLARE_DYNAMIC(about_us)

public:
	about_us(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~about_us();

// 对话框数据
	enum { IDD = IDD_ABOUT_US };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBackmainAbout();
	virtual BOOL OnInitDialog();
};
