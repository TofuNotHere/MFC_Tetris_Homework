// NameInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainMenu.h"
#include "NameInput.h"
#include "afxdialogex.h"


// CNameInput �Ի���

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


// CNameInput ��Ϣ�������


void CNameInput::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_NAME_INPUT)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
