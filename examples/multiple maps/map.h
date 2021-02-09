#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>

/*loads map from text file and displays it on screen*/
void mapload(char *map, int size)
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
            DrawRectangle(x, y, size, size, BLACK);
            x += size;
        }
	}	
	
	fclose(m);
}