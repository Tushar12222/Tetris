#include "block.h"

// implementation of block constructor that initializes the cellsize, rotationState, and the colors vector
Block::Block() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	colOffset = 0;
}

// implementation of the draw func that draws the block to the screen
void Block::Draw() {
	// gets the current cell coordinates for the current rotation state and offset
	std::vector<Position> tiles = GetCellPositions();
	
	for(Position item: tiles) {
		DrawRectangle(item.col * cellSize+1, item.row * cellSize+1, cellSize-1, cellSize-1, colors[id]);
	}
}


// Moves the block with the help of an offset
void Block::Move(int rows, int cols) {
	rowOffset += rows;
	colOffset += cols;
}

// returns the current cell coordinates based on the current offset
std::vector<Position> Block::GetCellPositions() {
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for(Position item: tiles) {
		Position newPos = Position(item.row + rowOffset, item.col + colOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}

// implementing the rotate func that handles rotation of the block
void Block::Rotate() {
	rotationState++;
	if(rotationState == (int)cells.size())
		rotationState = 0;
}


// implementing the undorotation func that undoes the previous rotation
void Block::UndoRotation() {
	rotationState--;
	if(rotationState == -1)
		rotationState = cells.size() - 1;
}
