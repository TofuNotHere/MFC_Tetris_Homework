#pragma once

// CNameInput �Ի���

class CNameInput : public CDialogEx
{
	DECLARE_DYNAMIC(CNameInput)

public:
	CNameInput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNameInput();

// �Ի�������
	enum { IDD = IDD_NAME_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// //�������
	CString m_name;
	afx_msg void OnBnClickedOk();
	CString GetName();
	virtual BOOL OnInitDialog();
};
