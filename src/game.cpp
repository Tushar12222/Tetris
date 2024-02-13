#include "game.h"
#include <cstdlib>

// constructor that initializes the grid, the ccurrent block and the next block
Game::Game() {
	grid = Grid();
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
	InitAudioDevice();
	music = LoadMusicStream("sounds/music.mp3");
	PlayMusicStream(music);
	rotateSound = LoadSound("sounds/rotate.mp3");
	clearSound = LoadSound("sounds/clear.mp3");
}

// destructor to remove the music
Game::~Game() {
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	UnloadMusicStream(music);
	CloseAudioDevice();
}


// implementing the GetRandomBlock func that returns a random block whenever called
Block Game::GetRandomBlock() {
	if(blocks.empty()) {
		blocks = GetAllBlocks();	
	}

	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

//implementing the GetAllBlocks that returns all the blocks used in the game
std::vector<Block> Game::GetAllBlocks() {
	return blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

// implementing the draw func that draws all the game items to the screen
void Game::Draw() {
	grid.Draw();
	currentBlock.Draw(11, 11);
	switch(nextBlock.id) {
		case 3:
			nextBlock.Draw(255, 290);
			break;
		
		case 4:
			nextBlock.Draw(255, 280);
			break;

		default:
			nextBlock.Draw(270, 270);
			break;
	}
}

// implementing the handleinput func that handles input
void Game::HandleInput() {
	int keyPressed = GetKeyPressed();
	if(gameOver && keyPressed != 0) {
		gameOver = false;
		Reset();
	}
	switch(keyPressed) {
		case KEY_LEFT:
			MoveBlockLeft();
			break;

		case KEY_RIGHT:
			MoveBlockRight();
			break;
		
		case KEY_DOWN:
			MoveBlockDown();
			UpdateScore(0, 1);
			break;

		case KEY_UP:
			RotateBlock();
			break;
	}
}

// implementing the moveblockleft func that moves the block to the left
void Game::MoveBlockLeft() {
	if(!gameOver) {
		currentBlock.Move(0, -1);
		if(IsBlockOutside() || !BlockFits()) currentBlock.Move(0, 1);
	}
}

// implementing the moveblockright func that moves the block to the right
void Game::MoveBlockRight() {
	if(!gameOver) {
		currentBlock.Move(0, 1);
		if(IsBlockOutside() || !BlockFits()) currentBlock.Move(0, -1);
	}
}

// implementing the moveblockdown func that moves the block down
void Game::MoveBlockDown() {
	if(!gameOver) {
		currentBlock.Move(1, 0);
		if(IsBlockOutside() || !BlockFits()) {
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

// implemmenting the isblock outside func that checks if a block is outside the game grid
bool Game::IsBlockOutside() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for(Position item: tiles) {
		if(grid.IsCellOutside(item.row, item.col)) return true;
	}
	return false;
}

// implementing hte rotateblock func that handles the rotation of the block
void Game::RotateBlock() {
	if(!gameOver) {
		currentBlock.Rotate();
		if(IsBlockOutside() || !BlockFits())
			currentBlock.UndoRotation();
		else
			PlaySound(rotateSound);
	}
}

// implementing the lockblock func that locks the block in piosition when it cannot move own any further
void Game::LockBlock() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for(Position item: tiles) {
		grid.grid[item.row][item.col] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if(!BlockFits()) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	if(rowsCleared > 0) {
		PlaySound(clearSound);
		UpdateScore(rowsCleared, 0);
	}
}

// implementing the blockfits func that checks if a blocks fits
bool Game::BlockFits() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for(Position item: tiles) {
		if(!grid.IsCellEmpty(item.row, item.col))
			return false;
	}
	return true;
}

// implementing the reset func that resets the game
void Game::Reset() {
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

// implementing the updatescore func that updates the score
void Game::UpdateScore(int linesCleared, int moveDownPoints) {
	switch(linesCleared) {
			case 1:
				score += 100;
				break;

			case 2:
				score += 300;
				break;

			case 3:
				score += 500;
				break;

			default:
				break;
	}

	score += moveDownPoints;
}
