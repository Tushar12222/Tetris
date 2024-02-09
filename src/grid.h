#pragma once
#include <vector>
#include <raylib.h>

class Grid {
	public:
		Grid(); // constructor
		void Initialize(); // function to initialize grid
		void Print(); // function to print the grid
		void Draw(); // function to draw the grid on to the screen
		int grid[20][10]; // variable to store the grid
	
	private:
		std::vector<Color> GetCellColors(); // function to get all the block colors used in the game
		int numRows; // variable to store the num of rows in the grid
		int numCols; // variable to store the num of cols in the grid
		int cellSize; // variable to store the size of each cell in the grid
		std::vector<Color> colors; // vector to hold all the colors used for the tetris blocks

};
