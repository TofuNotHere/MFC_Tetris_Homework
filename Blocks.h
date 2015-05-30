#pragma once
#include <cstring>
class Blocks
{
public:
	Blocks(int type);
	~Blocks();

	int GetType();
	int* GetData();

	void RollBlock();
	int* GetRollBlock();
private:
	int data[4][4];
	int type;

	void creatBlock_1();
	void creatBlock_2();
	void creatBlock_3();
	void creatBlock_4();
	void creatBlock_5();
	void creatBlock_6();
	void creatBlock_7();
};

