#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>

#define H 4
#define W 6
//maze map
char tiny_maze[H][W] = { "+-+-+",
                         "| |#|",
                         "|   |",
                    	 "+---+" };
void draw ()
{
	int i, j;
	for (i = 0; i < H; i++)
	  {
		  for (j = 0; j < W; j++)
				  printf ("%c", tiny_maze[i][j]);
		  printf ("\n");
	  }
	printf ("\n");
}
void refresh(char *program, int length){
	int x, y;     //Player position
	int ox, oy;   //Old player position
	x = 1;
	y = 1;
	tiny_maze[y][x]='X';
	draw();

	int index=0;

	while(index<length){
		ox = x;    //Save old player position
		oy = y;

		bool break_out_wile = false;
		switch (program[index])
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
				break_out_wile = true;
				break;
		}
		if (tiny_maze[y][x] != ' ') {
			x = ox;
			y = oy;
		}
		system("clear");
		tiny_maze[y][x]='X';
		draw();
		usleep(250000);
		index++;
		if (break_out_wile == true) break;
	}
	//char command[1024];
	//strncpy(command,program,index);
	printf("Command is: %s", program);
	printf("and this window will be shut down within 3 seconds");
	sleep(3);
	
}

//argv[1]:program, the first argv in command line.
//argv[2]:filepath, the second argv in command line.
int main(int argc, char *argv[]){
	if(argc==2){
		refresh(argv[1],sizeof(argv[1])/sizeof(argv[1][0]));
	}
	else if(argc==3){
	char *filepath = argv[2];
	FILE *fp;
	fp=fopen(filepath, "r");
	if(!fp)printf("%s open error", filepath);
	fseek(fp,0L,SEEK_END);
	int flen = ftell(fp);//get the length of characters
	char *p = (char *)malloc(flen+1);
	if(p == NULL)//it is a empty file
	{
		fclose(fp);
		printf("it is a empty file.");
		return 0;
	}
	fseek(fp,0L,SEEK_SET);
	fread(p,flen,1,fp);
	p[flen] = '\0';//set the last one as '\0'
	refresh(p,flen);
	}
}
