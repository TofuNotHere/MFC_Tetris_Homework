#pragma once
#include "MainMenu.h"
#include "MainMenuDlg.h"

// about_us �Ի���

class about_us : public CDialogEx
{
	DECLARE_DYNAMIC(about_us)

public:
	about_us(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~about_us();

// �Ի�������
	enum { IDD = IDD_ABOUT_US };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBackmainAbout();
	virtual BOOL OnInitDialog();
};
