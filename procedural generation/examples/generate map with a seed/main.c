#include <raylib.h>
#include "generation.h"

int main(void)
{
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
        gen(8, 200, sw, sh, 256); /*size of tiles, amount of tiles, screen width, screen height and seed*/

        EndDrawing();
    }
    CloseWindow();

	return 0;
}
