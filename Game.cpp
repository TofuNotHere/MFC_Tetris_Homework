#include "stdafx.h"
#include "Game.h"
#define _CRT_SECURE_NO_WARNINGS

Game::Game()
{
	Height = 24;
	Width = 12;
	Background = NULL;
	NextBlock = NULL;

	block = NULL;
	nextBlock = NULL;

	state = STOP;
	GameRank = 500;
}


Game::~Game()
{
}


void Game::MoveDown()
{
	LOC_Y++;
}


void Game::MoveLeft()
{
	LOC_X--;
}


void Game::MoveRight()
{
	LOC_X++;
}


bool Game::CanMoveDown()
{
	bool *temp = new bool[Height*Width];
	int Sum_before = 4, Sum_after = 0;
	//复制并统计小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			if (Background[i * Width + j].hasBlock)
				Sum_before++;
			temp[i * Width + j] = Background[i * Width + j].hasBlock;
		}
	//假设可以移动
	int *tmp = block->GetData();
	int X = LOC_X, Y = LOC_Y + 1;
	for (int i = Y; i < Y + 4; i++)
		for (int j = X; j < X + 4; j++){
			if (i >= 0 && i < Height &&
				j >= 0 && j < Width  &&
				tmp[(i - Y)*4 + j - X])
				temp[i*Width + j] = 1;
		}
	//统计移动后小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			if (temp[i * Width + j])
			Sum_after ++ ;
		}
	delete(temp);
	//delete(tmp);
	return Sum_before == Sum_after;
}


bool Game::CanMoveLeft()
{
	bool *temp = new bool[Height*Width];
	int Sum_before = 4, Sum_after = 0;
	//复制并统计小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			Sum_before += Background[i * Width + j].hasBlock;
			temp[i * Width + j] = Background[i * Width + j].hasBlock;
		}
	//假设可以移动
	int *tmp = block->GetData();
	int X = LOC_X-1, Y = LOC_Y;
	for (int i = Y; i < Y + 4; i++)
		for (int j = X; j < X + 4; j++){
			if (i >= 0 && i < Height &&
				j >= 0 && j < Width  &&
				tmp[(i - Y)*4 + j - X])
				temp[i*Width + j] = 1;
		}
	//统计移动后小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			Sum_after += temp[i * Width + j];
		}
	delete(temp);
	//delete(tmp);
	return Sum_before == Sum_after;
}


bool Game::CanMoveRight()
{
	bool *temp = new bool[Height*Width];
	int Sum_before = 4, Sum_after = 0;
	//复制并统计小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			Sum_before += Background[i * Width + j].hasBlock;
			temp[i * Width + j] = Background[i * Width + j].hasBlock;
		}
	//假设可以移动
	int *tmp = block->GetData();
	int X = LOC_X + 1, Y = LOC_Y;
	for (int i = Y; i < Y + 4; i++)
		for (int j = X; j < X + 4; j++){
			if (i >= 0 && i < Height &&
				j >= 0 && j < Width  &&
				tmp[(i - Y)*4 + j - X])
				temp[i*Width + j] = 1;
		}
	//统计移动后小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			Sum_after += temp[i * Width + j];
		}
	delete(temp);
	//delete(tmp);
	return Sum_before == Sum_after;
}


bool Game::CanRoll()
{
	bool *temp = new bool[Height*Width];
	int Sum_before = 4, Sum_after = 0;
	//复制并统计小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			Sum_before += Background[i * Width + j].hasBlock;
			temp[i * Width + j] = Background[i * Width + j].hasBlock;
		}
	//假设可以移动
	int *tmp = block->GetRollBlock();
	int X = LOC_X , Y = LOC_Y;
	for (int i = Y; i < Y + 4; i++)
		for (int j = X; j < X + 4; j++){
			if (i >= 0 && i < Height &&
				j >= 0 && j < Width  &&
				tmp[(i - Y)*4 + j - X])
				temp[i*Width + j] = 1;
		}
	//统计移动后小块个数
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++){
			Sum_after += temp[i * Width + j];
		}
	delete(temp);
	delete(tmp);
	return Sum_before == Sum_after;
}

void Game::MoveLines()
{
	LevelUp = false;
	int score = 0;
	int cnt = 0;
	for (int i = 0; i < Height; i++)
		if (CanMoveLine(i))
		{
			MoveLine(i);
			cnt++;
		}
	if (cnt)
		GameScore += cnt*cnt;
	if (GameScore > 15 * GameRank){
		GameRank++;
		LevelUp = true;
	}
}

bool Game::CanMoveLine(int index)
{
	int cnt = 0;
	for (int i = 0; i < Width; i++){
		cnt += Background[index*Width + i].hasBlock;
	}
	return cnt == Width;
}


void Game::MoveLine(int index)
{
	for (int i = index; i > 0; i--)
		for (int j = 0; j < Width; j++){
			Background[i*Width + j] = Background[(i - 1)*Width + j];
		}
	for (int i = 0; i < Width; i++)
		Background[i].hasBlock = 0;
}


void Game::AddBlocksToBackground()
{
	int *tmp = block->GetData();
	int X = LOC_X, Y = LOC_Y;
	for (int i = Y; i < Y + 4; i++)
		for (int j = X; j < X + 4; j++){
			if (i >= 0 && i < Height &&
				j >= 0 && j < Width  &&
				tmp[(i - Y) * 4 + j - X]){
				Background[i*Width + j].hasBlock = 1;
				Background[i*Width + j].color = block->GetType();
			}
		}
}


void Game::RandomNext()
{
	LOC_Y = 0;
	LOC_X = (Width - 4) / 2;
	block = nextBlock;

	srand(time(NULL));
	nextBlock = new Blocks(rand() % 7 + 1);
	for (int i = 0; i < 16; i++){
		NextBlock[i].hasBlock = nextBlock->GetData()[i];
		NextBlock[i].color = nextBlock->GetType();
	}

}


Block_Show * Game::GetBackground()
{
	Block_Show *res = new Block_Show[Width*Height];
	Block_Show *tmp = new Block_Show[16];
	if (block)
		for (int i = 0; i < 16; i++){
			(tmp + i)->hasBlock = *(block->GetData()+i);
			(tmp + i)->color = block->GetType();
		}
	int X = LOC_X, Y = LOC_Y;
	if (Background)
	{
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Width; j++){
				res[i * Width + j] = Background[i * Width + j];
			}
		for (int i = Y; i < Y + 4; i++)
			for (int j = X; j < X + 4; j++){
				if (i >= 0 && i < Height &&
					j >= 0 && j < Width  &&
					tmp[(i - Y) * 4 + j - X].hasBlock){
					res[i*Width + j].hasBlock = 1;
					res[i*Width + j].color = tmp[(i - Y) * 4 + j - X].color;
				}
			}
		return res;
	}
	else{
		return NULL;
	}
}


Block_Show * Game::GetNextBlock()
{
	return NextBlock;
}


void Game::StartAndStop()
{
	if (state != RUN)
		Start();
	else
		state = STOP;
}


void Game::PauseAndContinue()
{
	if (state == PAUSE)
		state = RUN;
	else if (state == RUN)
		state = PAUSE;
}


void Game::OnInput(UINT nChar)
{
	switch (nChar){
	case VK_UP:		if (CanRoll())			block->RollBlock(); break;
	case VK_DOWN:	while (CanMoveDown())	MoveDown();			break;
	case VK_LEFT:	if (CanMoveLeft())		MoveLeft();			break;
	case VK_RIGHT:	if (CanMoveRight())		MoveRight();		break;
	}
}


void Game::Start()
{
	block = NULL;
	NextBlock = NULL;
	state = RUN;
	GameScore = 0;
	GameRank = 1;

	Background = new Block_Show[Height*Width];
	NextBlock = new Block_Show[4 * 4];

	std::memset(Background, 0, Width*Height*sizeof(Block_Show));
	std::memset(NextBlock, 0, 16*sizeof(Block_Show));

	RandomNext();
	RandomNext();
}


bool Game::GameOver()
{
	for (int i = 0; i < Width; i++){
		if (Background[Width+i].hasBlock)
			return true;
	}
	return false;
}



bool Game::Run()
{
	if (CanMoveDown()){
		MoveDown();
		return true;
	}
	else{
		AddBlocksToBackground();
		MoveLines();
		if (GameOver()){
			state = STOP;
			return false;
		}
		else{
			RandomNext();
			return true;
		}
	}
}


STATE Game::GetGameState()
{
	return state;
}


string Game::GetGameRank()
{
	char temp[10];
	sprintf_s(temp, 10, "%d\0", GameRank);
	string rank(temp);
	return rank;
}

string Game::GetGameScore(){
	char temp[10];
	sprintf_s(temp,10, "%d\0", GameScore);
	string score(temp);
	return score;
}

int Game::GetHeight()
{
	return Height;
}


int Game::GetWidth()
{
	return Width;
}


int Game::GetLoc_X()
{
	return LOC_X;
}


int Game::GetLoc_Y()
{
	return LOC_Y;
}


int* Game::GetBlocks()
{
	return block->GetData();
}


int Game::GetGamerank_Timer()
{
	return 1000/GameRank;
}


bool Game::isLevelUp()
{
	return LevelUp;
}
