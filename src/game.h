#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
	public:
		Game(); // constructor
		~Game(); // destructor
		void Draw(); // func that draws the entire game to the screen
		void HandleInput(); // func to handle inputs from the user
		void MoveBlockDown(); // func to move the block down
		bool gameOver; // tells us if the game is over
		int score; // holds the score
		Music music; // holds the background music to be played

	private:
		Block GetRandomBlock(); // func that returns a random block
		std::vector<Block> GetAllBlocks(); // func that returns all the blocks used in the game
		Grid grid;
		void MoveBlockLeft(); // func to move the block to the left
		void MoveBlockRight(); // func to move the block to the right
		void UpdateScore(int linesCleared, int moveDownPoints); // func to update the score
		void Reset(); // func to reset the game
		bool IsBlockOutside();// func to check if any cell is outside the game grid
		void LockBlock(); // func to lock the block in position
		bool BlockFits(); // func to check if a block fits
		void RotateBlock(); // func to handle rotation of the blocks
		std::vector<Block> blocks; // holds all the possible blocks in the game 
		Block currentBlock; // holds the current block being displayed on the screen
		Block nextBlock; // holds the next block that will be drawn to the screen
		Sound rotateSound; // holds the sound to be played when the block is rotated
		Sound clearSound; // holds the sound to be played when a row is cleared

};
