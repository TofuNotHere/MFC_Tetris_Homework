// NameInput.cpp : 实现文件
//

#include "stdafx.h"
#include "MainMenu.h"
#include "NameInput.h"
#include "afxdialogex.h"


// CNameInput 对话框

IMPLEMENT_DYNAMIC(CNameInput, CDialogEx)

CNameInput::CNameInput(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNameInput::IDD, pParent)
	, m_name(_T(""))
{

}

CNameInput::~CNameInput()
{
}

void CNameInput::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME_INPUT, m_name);
}


BEGIN_MESSAGE_MAP(CNameInput, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNameInput::OnBnClickedOk)
END_MESSAGE_MAP()


// CNameInput 消息处理程序


void CNameInput::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	CDialogEx::OnOK();
}


CString CNameInput::GetName()
{
	return m_name;
}


BOOL CNameInput::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_NAME_INPUT)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
