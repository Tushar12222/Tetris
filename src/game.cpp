#include "game.h"
#include <cstdlib>

// constructor that initializes the grid, the ccurrent block and the next block
Game::Game() {
	grid = Grid();
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
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
	currentBlock.Draw();
}

// implementing the handleinput func that handles input
void Game::HandleInput() {
	int keyPressed = GetKeyPressed();
	switch(keyPressed) {
		case KEY_LEFT:
			MoveBlockLeft();
			break;

		case KEY_RIGHT:
			MoveBlockRight();
			break;
		
		case KEY_DOWN:
			MoveBlockDown();
			break;

		case KEY_UP:
			RotateBlock();
			break;
	}
}

// implementing the moveblockleft func that moves the block to the left
void Game::MoveBlockLeft() {
	currentBlock.Move(0, -1);
	if(IsBlockOutside()) currentBlock.Move(0, 1);
}

// implementing the moveblockright func that moves the block to the right
void Game::MoveBlockRight() {
	currentBlock.Move(0, 1);
	if(IsBlockOutside()) currentBlock.Move(0, -1);
}

// implementing the moveblockdown func that moves the block down
void Game::MoveBlockDown() {
	currentBlock.Move(1, 0);
	if(IsBlockOutside()) currentBlock.Move(-1, 0);
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
	currentBlock.Rotate();
	if(IsBlockOutside())
		currentBlock.UndoRotation();
}
