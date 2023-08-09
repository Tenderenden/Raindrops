// #include <stdlib.h>
#include <cstdio>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "point.h"
#include <queue>

#define HEIGHT 16
#define WIDTH 16
#define MAX_POINTS_NUM 16

std::queue <int> kolejka;
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
	int i=0;
	clearBuffer();
	if(false == kolejka.empty())
	{
		i = kolejka.front();
		kolejka.pop();
		points[i].x = rand()%16;
		points[i].y = 0;
		points[i].alive = TRUE;
	}

	for(i=0; i< MAX_POINTS_NUM; ++i)
	{
		if(TRUE == points[i].alive)
		{
			screen_buffer[points[i].y*16 + points[i].x] = 1;
			points[i].y++;
			if(points[i].y > HEIGHT)
			{
				points[i].alive = FALSE;
				kolejka.push(i);
			}
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
				printf("%c", 219);
			}
			else printf("%c", 178);
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
	for(auto i=0; i<WIDTH; ++i) kolejka.push(i);
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