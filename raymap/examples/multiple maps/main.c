#include <raylib.h>
#include "map.h"

int main(void)
{
    const int sw = 512; /*screen width*/
    const int sh = 512; /*screen height*/

    /*init*/
	  InitWindow(sw, sh, "window");
    SetTargetFPS(60);

    int m = 0; /*current map*/

    /*game loop*/
    while(!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_D)) m++;
        if(IsKeyPressed(KEY_A)) m--;

        /*Draw*/
        BeginDrawing();

		    ClearBackground(WHITE);

		/*loads maps*/
        if(m == 0)
        {
          loadmap("maps/map1.txt", 32, BLACK);
        } else if(m == 1)
        {
          loadmap("maps/map2.txt", 32, BLACK);
        } else if(m == 2)
        {
          loadmap("maps/map3.txt", 32, BLACK);
        }
		
		/*corrects map loading*/
		if(m >= 3)
		{
			m = 0;
		} else if(m < 0)
		{
			m = 2;
		}


        EndDrawing();
    }
    CloseWindow();

	return 0;
}
