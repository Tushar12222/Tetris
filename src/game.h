#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
	public:
		Game(); // constructor
		Block GetRandomBlock(); // func that returns a random block
		std::vector<Block> GetAllBlocks(); // func that returns all the blocks used in the game
		void Draw(); // func that draws the entire game to the screen
		void HandleInput(); // func to handle inputs from the user
		void MoveBlockLeft(); // func to move the block to the left
		void MoveBlockRight(); // func to move the block to the right
		void MoveBlockDown(); // func to move the block down
		Grid grid;

	private:
		bool IsBlockOutside(); // func to check if any cell is outside the gaame grid
		std::vector<Block> blocks; // holds all the possible blocks in the game 
		Block currentBlock; // holds the current block being displayed on the screen
		Block nextBlock; // holds the next block that will be drawn to the screen
};
