// #include <stdlib.h>
#include <cstdio>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "point.h"

#define HEIGHT 16
#define WIDTH 16

int screen_matrix[WIDTH * HEIGHT] = {0};

void updateMatrix(void)
{
	for(int i = HEIGHT; i > 0; --i)
	{
		for(int x=0; x<WIDTH; ++x)
		{
			screen_matrix[(i*16) + x] = screen_matrix[((i-1)*16) + x];
		}
	}
	for(int i = 0; i<WIDTH; ++i)
	{
		screen_matrix[i] = 0;
	}
}

void drawScreen(void)
{
	for(int r=0; r<HEIGHT; ++r)
	{
		for(int c=0; c<WIDTH; ++c)
		{
			if(screen_matrix[(r * WIDTH) + c] == 1)
			{
				printf("O");
			}
			else printf("_");
		}
		printf("\n");
	}
}

void zeroLine(void)
{
	for(int i=0; i<WIDTH; i++)
	{
		screen_matrix[i] = 0;
	}
}

int main()
{
	srand((unsigned) time(NULL));
	while(1)
	{
		updateMatrix();
		system("cls");
		screen_matrix[rand()%16] = 1;
		drawScreen();
		Sleep(500);
	}
	return 0;
}