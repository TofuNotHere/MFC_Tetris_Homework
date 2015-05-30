#pragma once
#include "Blocks.h"
#include <sstream>
#include <cstring>
using namespace std;

enum STATE
{
	RUN,
	STOP,
	PAUSE
};

struct Block_Show{
	bool hasBlock;
	int color;
};

class Game
{
public:
	Game();
	~Game();


private:
	Block_Show *Background;
	Block_Show *NextBlock;
	STATE state;

	int LOC_X;
	int LOC_Y;
	int Height;
	int Width;
	int GameRank;
	int GameScore;

	Blocks *block;
	Blocks *nextBlock;

	void AddBlocksToBackground();
	void RandomNext();

	void MoveDown();
	void MoveLeft();
	void MoveRight();

	bool CanMoveDown();
	bool CanMoveLeft();
	bool CanMoveRight();
	bool CanRoll();

	void MoveLines();
	bool CanMoveLine(int index);
	void MoveLine(int index);

	

public:

	Block_Show * GetBackground();
	Block_Show * GetNextBlock();
	void StartAndStop();
	void PauseAndContinue();
	void OnInput(UINT nChar);
	void Start();
	bool GameOver();
	bool Run();
	STATE GetGameState();
	string GetGameRank();
	string GetGameScore();
	int GetHeight();
	int GetWidth();
	int GetLoc_X();
	int GetLoc_Y();
	int* GetBlocks();
	int GetGamerank_Timer();
private:
	bool LevelUp;
public:
	bool isLevelUp();
};

