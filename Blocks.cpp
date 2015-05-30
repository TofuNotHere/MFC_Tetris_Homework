#include "stdafx.h"
#include "Blocks.h"

Blocks::Blocks(int type)
{
	this->type = type;
	std::memset(data, 0, sizeof(data));

	switch (this->type){
	case 1: creatBlock_1(); break;
	case 2: creatBlock_2(); break;
	case 3: creatBlock_3(); break;
	case 4: creatBlock_4(); break;
	case 5: creatBlock_5(); break;
	case 6: creatBlock_6(); break;
	case 7: creatBlock_7(); break;
	}
}


Blocks::~Blocks()
{
}
//--
void Blocks::creatBlock_1(){
	data[1][0] = data[1][1] = data[1][2] = data[1][3] = 1;
}
//[]
void Blocks::creatBlock_2(){
	data[1][1] = data[1][2] = data[2][1] = data[2][2] = 1;
}
//p
void Blocks::creatBlock_3(){
	data[1][1] = data[1][2] = data[2][1] = data[3][1] = 1;
}
//q
void Blocks::creatBlock_4(){
	data[1][0] = data[1][1] = data[2][1] = data[3][1] = 1;
}
//z
void Blocks::creatBlock_5(){
	data[1][0] = data[1][1] = data[2][1] = data[2][2] = 1;
}
//~z
void Blocks::creatBlock_6(){
	data[2][0] = data[2][1] = data[1][1] = data[1][2] = 1;
}
//͹
void Blocks::creatBlock_7(){
	data[2][0] = data[2][1] = data[1][1] = data[2][2] = 1;
}

int Blocks::GetType(){
	return type;
}

int* Blocks::GetData(){
	return &data[0][0];
}

void Blocks::RollBlock(){

	int temp[4][4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			temp[i][j] = data[i][j];
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			data[i][j] = temp[j][3 - i];
	}
}

int* Blocks::GetRollBlock(){
	int *temp = new int[16];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			temp[i * 4 + j] = data[j][3 - i];
	}

	return temp;
}
