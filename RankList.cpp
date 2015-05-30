// RankList.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainMenu.h"
#include "RankList.h"
#include <fstream>
#include "afxdialogex.h"
#include <vector>
#include <atlconv.h>
#include <algorithm>
#include <cstdlib>
using namespace std;


// CRankList �Ի���

IMPLEMENT_DYNAMIC(CRankList, CDialogEx)

CRankList::CRankList(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRankList::IDD, pParent)
{

}

CRankList::~CRankList()
{
}

void CRankList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRankList, CDialogEx)
	ON_BN_CLICKED(ID_Back_Main, &CRankList::OnBnClickedBackMain)
END_MESSAGE_MAP()


// CRankList ��Ϣ�������


void CRankList::OnBnClickedBackMain()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->SendMessage(WM_CLOSE);
}


BOOL CRankList::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CListCtrl *wnd = (CListCtrl *)GetDlgItem(IDC_LIST_RANK);
	wnd->GetClientRect(&rect);
	wnd->SetExtendedStyle(wnd->GetExtendedStyle() /*| LVS_EX_FULLROWSELECT*/ | LVS_EX_GRIDLINES);
	wnd->InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 7, 0);
	wnd->InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width() / 7 * 3, 1);
	wnd->InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width() / 7 * 3, 2);


	int cnt = 0;
	fstream f;
	ScoreSave data;
	f.open("RankList.dat", ios::in | ios::binary);
	if (f.fail()){
		AfxMessageBox(_T("�����а�ʧ��"));
		this->SendMessage(WM_CLOSE);
	}
	else{
		shot_Rank();
		while (!f.eof() && cnt < 20){
			f.read((char *)&data, sizeof(ScoreSave));
			char num[3];
			_itoa(cnt + 1, num, 10);
			USES_CONVERSION;
			wnd->InsertItem(cnt, A2T(num));
			wnd->SetItemText(cnt, 1, A2T(data.name));
			wnd->SetItemText(cnt, 2, A2T(data.score));
			cnt++;
		}
	}
	wnd->DeleteItem(--cnt);
	f.close();
	//wnd->DeleteItem(-- -- cnt);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//int CRankList::cmp(const void* a,const void* b)
//{
//	return atoi(((ScoreSave*)a)->score) - atoi(((ScoreSave*)b)->score);
//}

//���а�����
void CRankList::shot_Rank()
{
	int cnt = 0;
	vector<ScoreSave> rank;
	ScoreSave data;
	fstream f;
	f.open("RankList.dat", ios::in | ios::binary);
	while (!f.eof()){
		f.read((char *)&data, sizeof(ScoreSave));
		rank.push_back(data);
	}
	rank.pop_back();
	f.close();
	sort(rank.begin(),rank.end());

	f.open("RankList.dat", ios::out | ios::binary);
	for (int i = 0; i < 20 && i < rank.size(); i++)
		f.write((char*)&rank[i], sizeof(ScoreSave));
	f.close();
}

