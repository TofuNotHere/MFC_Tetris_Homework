#pragma once

// CNameInput 对话框

class CNameInput : public CDialogEx
{
	DECLARE_DYNAMIC(CNameInput)

public:
	CNameInput(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNameInput();

// 对话框数据
	enum { IDD = IDD_NAME_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //玩家姓名
	CString m_name;
	afx_msg void OnBnClickedOk();
	CString GetName();
	virtual BOOL OnInitDialog();
};
