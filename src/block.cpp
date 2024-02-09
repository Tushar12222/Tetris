#include "block.h"

// implementation of block constructor that initializes the cellsize, rotationState, and the colors vector
Block::Block() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
}

// implementation of the draw func that drawshe block to the screen
void Block::Draw() {
	std::vector<Position> tiles = cells[rotationState];
	
	for(Position item: tiles) {
		DrawRectangle(item.col * cellSize+1, item.row * cellSize+1, cellSize-1, cellSize-1, colors[id]);
	}
}
