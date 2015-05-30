// about_us.cpp : 实现文件
//
#include "stdafx.h"
#include "about_us.h"
#include "afxdialogex.h"


// about_us 对话框

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


// about_us 消息处理程序


void about_us::OnBnClickedButtonBackmainAbout()
{
	// TODO:  在此添加控件通知处理程序代码
	this->SendMessage(WM_CLOSE);
}



BOOL about_us::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;
}
