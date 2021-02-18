#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>

/*loads map from text file and displays it on screen*/
void loadmap(char *map, int size, Color clr)
{
	int c; /*characters in file*/
	FILE *m = fopen(map, "r"); /*opens map*/
	int x = 0, y = 0; /*X position and Y position*/
	
	while((c = fgetc(m)) != EOF)
	{
		/*whitespace*/
		if(c == '-')
    {
			x = 0;
      y += size;
    }

    if(c == '.')
		{
    	x += size;
		}

		/*ground*/
    if(c == '#')
    {
			DrawRectangle(x, y, size, size, clr);
      x += size;
		}
	}	
	fclose(m);
}

/*map collision function (this function is simmilar to the loadmap function, just used in a different context)*/
bool collidemap(char *map, int size, int px, int py, int pw, int ph)
{
	int c; /*characters in file*/
	FILE *m = fopen(map, "r"); /*opens map*/
	int x = 0, y = 0; /*X position and Y position*/
	
	bool collide = false; /*collision*/
	while((c = fgetc(m)) != EOF)
	{
		/*whitespace*/
		if(c == '-')
    {
			x = 0;
      y += size;
    }

    if(c == '.')
		{
    	x += size;
		}

		/*ground*/
    if(c == '#')
    {
			/*collision*/
			if (px < x + size &&
					px + pw > x &&
					py < y + size &&
					py + ph > y) 
					{
					collide = true;
			}
      
			x += size;
		}
	}	
	fclose(m);
	
	return collide;
}