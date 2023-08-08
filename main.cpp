// #include <stdlib.h>
#include <cstdio>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "point.h"

#define HEIGHT 16
#define WIDTH 16
#define MAX_POINTS_NUM 16

int screen_buffer[WIDTH * HEIGHT] = {0};

Point points[MAX_POINTS_NUM];
void clearBuffer(void)
{
	for(int i=0; i<WIDTH * HEIGHT; ++i)
	{
		screen_buffer[i] = 0;
	}
}

void updateBuffer(void)
{
	clearBuffer();
	for(int i=0; i< MAX_POINTS_NUM; ++i)
	{
		if(FALSE == points[i].alive)
		{
			points[i].x = rand()%16;
			points[i].y = 0;
			points[i].alive = TRUE;
			break;
		}
	}
	for(int i=0; i< MAX_POINTS_NUM; ++i)
	{
		if(TRUE == points[i].alive)
		{
			screen_buffer[points[i].y*16 + points[i].x] = 1;
			points[i].y++;
			if(points[i].y > HEIGHT) points[i].alive = FALSE;
		}
	}
}

void drawScreen(void)
{
	for(int r=0; r<HEIGHT; ++r)
	{
		for(int c=0; c<WIDTH; ++c)
		{
			if(screen_buffer[(r * WIDTH) + c] == 1)
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
		screen_buffer[i] = 0;
	}
}

int main()
{
	srand((unsigned) time(NULL));
	while(1)
	{
		updateBuffer();
		system("clear");
		// screen_buffer[rand()%16] = 1;
		drawScreen();
		Sleep(500);
	}
	return 0;
}