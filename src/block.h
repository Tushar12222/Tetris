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
		void Move(int rows, int cols); // func to move the block
		void Rotate(); // func to handle block rotation
		void UndoRotation(); // func to undo the previous rotation
		std::vector<Position> GetCellPositions(); // func that returns all the cell positions of the current block
		std::map<int, std::vector<Position>> cells; // holds all the possible rotation positions for the block

	private:
		int cellSize; // holds cellsize
		int rotationState; // holds the current rotation state
		std::vector<Color> colors; // holds all the possible block colors
		int rowOffset; // holds the rowofffset for the movement
		int colOffset; // holds the coloffset for the movement

};
