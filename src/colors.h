#pragma once
#include <raylib.h>
#include <vector>

// each hold a specific color
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;

// func to get all the possible  block colors
std::vector<Color> GetCellColors();
