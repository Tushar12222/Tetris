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
			DrawRectangle(col * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
		}
	}
}

// implementing the iscelloutside func that checks if a cell is outside the grid
bool Grid::IsCellOutside(int row, int col) {
	if(row >= 0 && row < numRows && col >= 0 && col < numCols) 
		return false;
	return true;
}

// implementing a func to check if a cell is empty
bool Grid::IsCellEmpty(int row, int col) {
	if(grid[row][col] == 0) return true;
	return false;
}

// implenting the isrowfull func that checks if a row is full
bool Grid::IsRowFull(int row) {
	for(int col = 0; col < numCols; col++) {
		if(grid[row][col] == 0)
			return false;
	}
	return true;
}

// implementing the clear row func that clears a row
void Grid::ClearRow(int row) {
	for(int col = 0; col < numCols; col++)
		grid[row][col] = 0;
}

// implementing the moverowdown func that moves the row down
void Grid::MoveRowDown(int row, int numRows) {
	for(int col = 0; col < numCols; col++) {
		grid[row + numRows][col] = grid[row][col];
		grid[row][col] = 0;
	}
}

// implementing the clearfullrows func that checks for all completed rows in the grid and removes them
int Grid::ClearFullRows() {
	int completed = 0;
	for(int row = numRows - 1; row >= 0; row--) {
		if(IsRowFull(row)) {
			ClearRow(row);
			completed++;
		} else if(completed > 0) {
			MoveRowDown(row, completed);
		}
	}
	return completed;
}
