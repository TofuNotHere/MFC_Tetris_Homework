// about_us.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "about_us.h"
#include "afxdialogex.h"


// about_us �Ի���

IMPLEMENT_DYNAMIC(about_us, CDialogEx)

about_us::about_us(CWnd* pParent /*=NULL*/)
	: CDialogEx(about_us::IDD, pParent)
{

}

about_us::~about_us()
{
}

void about_us::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(about_us, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BACKMAIN_ABOUT, &about_us::OnBnClickedButtonBackmainAbout)
END_MESSAGE_MAP()


// about_us ��Ϣ�������


void about_us::OnBnClickedButtonBackmainAbout()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->SendMessage(WM_CLOSE);
}



BOOL about_us::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;
}
