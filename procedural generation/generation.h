#include <raylib.h>
#include <stdlib.h>
#include <time.h>

void gen(int size, int tiles, int sw,  int sh, int seed)
{
	srand(seed);
	int tilex = rand() % sw; /*random x based on screen width*/
	int tiley = rand() % sh; /*random y based on screen height*/
  int dir; /*directions*/

  int i;
  for(i=0; i<tiles; i++)
  {
		dir = rand() % 4;
    if(dir == 0) DrawRectangle(tilex, tiley -= size, size, size, WHITE); /*north*/
    if(dir == 1) DrawRectangle(tilex += size, tiley, size, size, WHITE); /*east*/
    if(dir == 2) DrawRectangle(tilex, tiley += size, size, size, WHITE); /*south*/
    if(dir == 3) DrawRectangle(tilex -= size, tiley, size, size, WHITE); /*west*/
  }
}