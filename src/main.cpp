#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

// holds the last time the time passed
double lastUpdateTime = 0;

// func that tells if a certain amount of time has passed
bool timePassed(double interval) {
	double currentTime = GetTime();
	if(currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}


int main() {
	// initializes a window with the given height, width and title 
	InitWindow(500, 620, "Tetris");
	
	// sets the frames to be drawn per second (if not specified the frames are drawn as many as possible by the hardware which we do not want in this case as it moves the tetris blocks faster on a better pc) 
	SetTargetFPS(60);
	
	// load the font
	Font font = LoadFont("font/Raleway-Regular.ttf");

	Game game = Game();

	// game loop
	while(!WindowShouldClose()) {
		// handles playing the background music each frame
		UpdateMusicStream(game.music);

		// Handles the game input
		game.HandleInput();

		// provides an empty canvas to draw on
		BeginDrawing();
		
		// clears the new background and fills in the new background color specified
		ClearBackground(darkBlue);
		
		// draws the text to the screen
		DrawTextEx(font, "Score", {355, 15}, 38, 2, WHITE);

		DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
		
		if(game.gameOver)
			DrawTextEx(font, "GAME OVER", {335, 500}, 26, 2, WHITE);
		
		// draws the blue rounded rectangle to the screen
		DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

		// holds the score to be displayeed to the screen
		char scoreText[10];
		sprintf(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
		
		DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);

		DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

		game.Draw();
		
		// pushes the current block down only if 0.2 secs have passed
		if(timePassed(0.2)) {
			game.MoveBlockDown();
		}
		
		EndDrawing();
	}
	
	// closes the gui window
	CloseWindow();
}
