#include "raylib.h"

//#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include <stdio.h>

bool menu(char* text);

int main ()
{	

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	 InitWindow(1024, 768, "Little Pong Clone =D");

	// System Variables
	const int WinnerTotalPoints = 5;
	
	char* startText = "New Pong!! Press The SPACE BAR to Start or ESC to Exit";
	bool isInMenu = 1;


	int playerScore = 0;
	int pcScore = 0;

	char playerScoreText[2];
	char pcScoreText[2];
	
	int ballMovementX = -10;
	int ballMovementY = -10;

	// Ball Movement
	int ballPositionX = GetScreenWidth() / 2 - 10;	
	int ballPositionY = GetScreenHeight() / 2 - 10;

	
	// Player Variables
	int playerPositionY = GetScreenHeight() / 2 - 125;
	int playerPositionX = 0;

	// PC Variables
	int pcPositionX = GetScreenWidth() - 10;
	int pcPositionY = GetScreenHeight() / 2 - 125;
	
	SetTargetFPS(60);
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// Update
		if(isInMenu){
			if(IsKeyPressed(KEY_SPACE)) {
				isInMenu = 0;
				if (playerScore == WinnerTotalPoints || pcScore == WinnerTotalPoints) {
					pcScore = 0;
					playerScore = 0;
				}
			}

			sprintf(playerScoreText, "%d", playerScore);
			sprintf(pcScoreText, "%d", pcScore);


		} else{
			if(IsKeyDown(KEY_DOWN)) playerPositionY += (playerPositionY >= GetScreenHeight() - 250) ? 0 : 6;
			if(IsKeyDown(KEY_UP)) playerPositionY -= (playerPositionY <= 0) ? 0 : 6 ;
			
			if(ballPositionX <= 20 && ballPositionX >= 11  && ballPositionY >= playerPositionY && ballPositionY <= playerPositionY + 250){
				ballMovementX *= -1;
			}

			if(ballPositionX >= GetScreenWidth() - 20 && ballPositionX <= GetScreenWidth() - 11 && ballPositionY >= pcPositionY && ballPositionY <= pcPositionY + 250){
				ballMovementX *= -1;
			}

			if(ballPositionX >= GetScreenWidth() - 10){
				++playerScore; 
				ballPositionX = GetScreenWidth() / 2 - 10;
				ballPositionY = GetScreenHeight() / 2 - 10;
				playerPositionY = GetScreenHeight() / 2 - 125;
				pcPositionY = GetScreenHeight() / 2 - 125;
				isInMenu = 1;
				ballMovementX *= -1;
			}
			if(ballPositionX <= 10){
				++pcScore; 
				ballPositionX = GetScreenWidth() / 2 - 10;
				ballPositionY = GetScreenHeight() / 2 - 10;
				playerPositionY = GetScreenHeight() / 2 - 125;
				pcPositionY = GetScreenHeight() / 2 - 125;
				ballMovementX *= -1;
				isInMenu = 1;
			}

			if(ballPositionY >= GetScreenHeight() - 10 || ballPositionY <= 10) ballMovementY *= -1;
			
			ballPositionX += ballMovementX;
			ballPositionY += ballMovementY;

			pcPositionY += 6 * (ballMovementY / 10);
		}

		// drawing
		BeginDrawing();
		
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		if(isInMenu){
			if(playerScore == WinnerTotalPoints) 
				DrawText("Player Wins!", GetScreenWidth() / 2.0f - MeasureText("Player Wins!", 20) / 2.0f, GetScreenHeight() / 2.0f - 35, 20, WHITE);
			if (pcScore == WinnerTotalPoints) 
				DrawText("PC Wins!", GetScreenWidth() / 2.0f - MeasureText("PC Wins!", 20) / 2.0f , GetScreenHeight() / 2.0f - 35, 20, WHITE);
			DrawText(startText, GetScreenWidth() / 2.0f - MeasureText(startText, 20) / 2.0f, GetScreenHeight() / 2.0f,20,WHITE);
			DrawText("Player Score: ", 0, 0, 20, WHITE);
			DrawText(playerScoreText, MeasureText("Player Score: ", 20), 0, 20, WHITE);
			DrawText("PC Score: ", GetScreenWidth() - MeasureText("PC Score: ", 20) - MeasureText("10", 20), 0, 20, WHITE);
			DrawText(pcScoreText, GetScreenWidth() - MeasureText("10", 20), 0, 20, WHITE);
		} else {
			DrawRectangle(playerPositionX, playerPositionY, 10, 250, WHITE);
			DrawRectangle(pcPositionX, pcPositionY, 10, 250, WHITE);
			DrawCircle(ballPositionX, ballPositionY, 10, WHITE);
		
		}
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();	
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

