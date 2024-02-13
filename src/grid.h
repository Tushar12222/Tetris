#pragma once
#include <vector>
#include <raylib.h>

class Grid {
	public:
		Grid(); // constructor
		void Initialize(); // function to initialize grid
		void Print(); // function to print the grid
		void Draw(); // function to draw the grid on to the screen
		bool IsCellEmpty(int row, int col); // func to check if a cell is empty in the grid
		bool IsCellOutside(int row, int col); // // func to check if aa cell is outside the game grid
		int ClearFullRows(); // func that checka for all the completed rows in the grid and removes them
		int grid[20][10]; // variable to store the grid
	
	private:
		bool IsRowFull(int row); // func to check if a row is full
		void ClearRow(int row); // func to clear a row
		void MoveRowDown(int row, int numRows); // func that moves a row down in the grid
		int numRows; // variable to store the num of rows in the grid
		int numCols; // variable to store the num of cols in the grid
		int cellSize; // variable to store the size of each cell in the grid
		std::vector<Color> colors; // vector to hold all the colors used for the tetris blocks

};
