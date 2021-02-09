#include <raylib.h>
#include "mapt.h"

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
          mapload("maps/map1.txt", 32);
        } else if(m == 1)
        {
          mapload("maps/map2.txt", 32);
        } else if(m == 2)
        {
          mapload("maps/map3.txt", 32);
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