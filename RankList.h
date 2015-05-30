#pragma once

// CRankList �Ի���

class CRankList : public CDialogEx
{
	DECLARE_DYNAMIC(CRankList)

public:
	CRankList(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRankList();

// �Ի�������
	enum { IDD = IDD_RANKLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBackMain();
	virtual BOOL OnInitDialog();
private:
	struct ScoreSave{
		char name[20];
		char score[5];
		ScoreSave(){};
		ScoreSave(char * _name, const char* _score){
			strcpy(name, _name);
			strcpy(score, _score);
		}
		bool operator < (const ScoreSave & right) const {
			return atoi(score) > atoi(right.score);
		}
	};
public:
	void shot_Rank();
	int cmp(const void * a,const void* b);
};
