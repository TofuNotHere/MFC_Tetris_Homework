
// MainMenuDlg.h : ͷ�ļ�
//
#pragma once


// CMainMenu �Ի���
class CMainMenu : public CDialogEx
{
// ����
public:
	CMainMenu(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAINMENU_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStartGame();
	afx_msg void OnBnClickedButtonRanklist();
	afx_msg void OnBnClickedButtonAboutUs();
	afx_msg void OnBnClickedButtonExit();
};
