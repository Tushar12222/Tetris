#include <raylib.h>
#include "game.h"

int main() {
	// stores the color as a struct defined in the raylib library
	Color darkBlue = {44, 44, 127, 255};
	
	// initializes a window with the given height, width and title 
	InitWindow(300, 600, "Tetris");
	
	// sets the frames to be drawn per second (if not specified the frames are drawn as many as possible by the hardware which we do not want in this case as it move the tetris blocks faster on a betteer pc) 
	SetTargetFPS(60);

	Game game = Game();

	// game loop
	while(!WindowShouldClose()) {
		game.HandleInput();


		// provides an empty canvas to draw on
		BeginDrawing();
		
		// clears the new background and fills in the new background color specified
		ClearBackground(darkBlue);

		game.Draw();
		
		EndDrawing();
	}
	
	// closes the gui window
	CloseWindow();
}
