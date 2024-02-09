#include "grid.h"
#include <iostream>
#include "colors.h"

// implenting the constructor
Grid::Grid() {
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	colors = GetCellColors();
}

// implementing the initialize function that initializes the entire grid with zeros
void Grid::Initialize() {
	for(int row = 0; row < numRows; row++) {
		for(int col = 0; col < numCols; col++) {
			grid[row][col] = 0;
		}
	}
}

// implementing the print function that prints the current state of the grid
void Grid::Print() {
	for(int row = 0; row < numRows; row++) {
		for(int col = 0; col < numCols; col++) {
				std::cout << grid[row][col] << " ";	
		}
		std::cout << std::endl;
	}
}

// implementing the draw function that draws the grid on to the screen
void Grid::Draw() {
	for(int row = 0; row < numRows; row++) {
		for(int col = 0; col < numCols; col++) {
			int cellValue = grid[row][col];
			DrawRectangle(col * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
		}
	}
}
