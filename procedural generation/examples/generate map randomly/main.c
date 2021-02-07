#include <raylib.h>
#include "generation.h"

int main(void)
{
	srand(time(0));
	int seed = rand(); /*generate random seed*/
  
	const int sw = 512; /*screen width*/
  const int sh = 512; /*screen height*/

  /*init*/
  InitWindow(sw, sh, "window");
  SetTargetFPS(60);

    /*game loop*/
    while(!WindowShouldClose())
    {
        /*Draw*/
        BeginDrawing();

        ClearBackground(WHITE);

        DrawRectangle(0, 0, 512, 512, BLACK);
        gen(8, 200, sw, sh, seed); /*size of tiles, amount of tiles, screen width, screen height and seed*/

        EndDrawing();
    }
    CloseWindow();

	return 0;
}
