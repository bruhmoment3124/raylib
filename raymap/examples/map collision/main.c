#include <raylib.h>
#include "map.h"

int main(void)
{
  const int sw = 512; /*screen width*/
  const int sh = 512; /*screen height*/

  /*init*/
	InitWindow(sw, sh, "window");
  SetTargetFPS(60);
	
	/*player variables*/
	int x = 256;
	int y = 32;
	int w = 32;
	int h = 32;
	int pdx = 0;
	int pdy = 0;

  /*game loop*/
  while(!WindowShouldClose())
  {
		pdy += 1; /*gravity*/
		int pstanding; /*if the player is on the ground*/
		if(IsKeyDown(KEY_A)) pdx-=3; /*left*/
		if(IsKeyDown(KEY_D)) pdx+=3; /*right*/
		if(IsKeyDown(KEY_W) && pstanding == 1) pdy-=15; /*jump*/
		
		/*Y collision*/
		if(collidemap("map.txt", 32, x, y + pdy, w, h))
		{
			pdy = 0;
			pstanding = 1;
		} else
		{
			pstanding = 0;
		}
		
		/*X collision*/
		if(collidemap("map.txt", 32, x + pdx, y, w, h)) pdx = 0;
		
		x += pdx;
		y += pdy;
		pdx *= .6;
		pdy *= 1;
		
    /*Draw*/
		BeginDrawing();

    ClearBackground(WHITE);
	
			loadmap("map.txt", 32, BLACK);
			DrawRectangle(x, y, w, h, BLUE);

    EndDrawing();
  }
  CloseWindow();

	return 0;
}
