#include "grid.h"
#include <iostream>

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

// implementing the getCellColors function that returns all the colors used in the game
std::vector<Color> Grid::GetCellColors() {
	Color darkGrey = {26, 31, 40, 255};
	Color green = {47, 238, 23, 255};
	Color red = {232, 18, 18, 255};
	Color orange = {226, 116, 17, 255};
	Color yellow = {237, 234, 4, 255};
	Color purple = {166, 0, 247, 255};
	Color cyan = {21, 204, 209, 255};
	Color blue = {13, 64, 216, 255};

	return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
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
