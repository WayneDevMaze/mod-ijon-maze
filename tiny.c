
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>

#define H 4
#define W 6

#define ITERS 512

char maze[H][W] = { "+-+-+",
                    "| |#|",
                    "|   |",
                    "+---+" };
void draw ()
{
	int i, j;
	for (i = 0; i < H; i++)
	  {
		  for (j = 0; j < W; j++)
				  printf ("%c", maze[i][j]);
		  printf ("\n");
	  }
	printf ("\n");
}

int
main (int argc, char *argv[])
{
	int x, y;     //Player position
	int ox, oy;   //Old player position
	int i = 0;    //Iteration number
	char program[ITERS];
	x = 1;
	y = 1;
	maze[y][x]='X';
	draw();
	read(0,program,ITERS);
	while(i < ITERS)
	{
#ifndef MAZE_NO_BT
		maze[y][x]=' ';
#endif
		ox = x;    //Save old player position
		oy = y;
    		//transition(hashint(x,y));
		//IJON_SET(ijon_hashint(x,y));
		switch (program[i])
		{
			case 'w':
				y--;
				break;
			case 's':
				y++;
				break;
			case 'a':
				x--;
				break;
			case 'd':
				x++;
				break;
			default:
				printf("Wrong command!(only w,s,a,d accepted!)\n");
				printf("You lose!\n");
				exit(-1);
		}
		if (maze[y][x] == '#')
		{
		char sys_show[ITERS + 100];
		strcpy(sys_show,"gnome-terminal --geometry=80x40+70+30 --command \"./maze_show ");
		strcat(sys_show,program);
		strcat(sys_show," \"");
		system(sys_show);
              	assert(0);
		}
		if (maze[y][x] != ' ') {
			x = ox;
			y = oy;
		}
#ifdef MAZE_NO_BT
		if (ox==x && oy==y){
			printf("You lose\n");
			exit(-2);
		}
#endif

		maze[y][x]='X';
		draw ();          //draw it
		i++;
	}
	printf("You lose\n");
}
