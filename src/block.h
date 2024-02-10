#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
	public:
		Block(); // constructor
		int id; // id tells us the color off the block
		void Draw(); // draws the block to the screen
		void Move(int rows, int cols);
		std::vector<Position> GetCellPositions();
		std::map<int, std::vector<Position>> cells; // holds all the possible rotation position for the block

	private:
		int cellSize; // holds cellsize
		int rotationState; // holds the current rotation state
		std::vector<Color> colors; // holds all the possible block colors
		int rowOffset;
		int colOffset;

};
