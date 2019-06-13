/**
*
* @Name : MinesweeperCLI/app.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2018-07-13
* @Released under : https://github.com/BaseMax/MinesweeperCLI/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/MinesweeperCLI
*
**/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int game(int,int);
const int width=10, height=4;

int mn[width][width],m[height];
char bz[width][width],a;

void display() {
	int i,j;
	clrscr();
	for(i=0;i<width;i++) {
		for(j=0;j<width;j++)
			printf("%4c",bz[i][j]);
		printf("\n\n");
	}
}

int check(void) {
	int i,j,k=0;
	for(i=0;i<width;i++)
		for(j=0;j<width;j++)
			if(bz[i][j]=='o' || bz[i][j]=='p')
				k++;
	if(k==height) {
		for(i=0;i<width;i++)
			for(j=0;j<width;j++)
			if(bz[i][j]=='o' || bz[i][j]=='p')
				bz[i][j]='G';
		display();
		printf("      *     you win       *       ");
		return 1;
	}
	return 0;
}

int game(int x, int y) {
	int k=0,i,j;
	if(x<width-1 && mn[x+1][y])
		k++;
	if(y<width-1 && mn[x][y+1])
		k++;
	if(x>0 && mn[x-1][y])
		k++;
	if(y>0 && mn[x][y-1])
		k++;
	if(x<width-1 && y>0 && mn[x+1][y-1])
		k++;
	if(x>0 && y<width-1 && mn[x-1][y+1])
		k++;
	if(x<width-1 && y<width-1 && mn[x+1][y+1])
		k++;
	if(x>0 && y>0 && mn[x-1][y-1])
		k++;
	bz[x][y]=k+48;
	if(k==0) {
		if(x<width-1 && bz[x+1][y]=='o')
			game(x+1,y);
		if(y<width-1 && bz[x][y+1]=='o')
			game(x,y+1);
		if(x>0 && bz[x-1][y]=='o')
			game(x-1,y);
		if(y>0 && bz[x][y-1]=='o')
			game(x,y-1);
		if(x<width-1 && y>0 && bz[x+1][y-1]=='o')
			game(x+1,y-1);
		if(x>0 && y<width-1 && bz[x-1][y+1]=='o')
			game(x-1,y+1);
		if(x<width-1 && y<width-1 && bz[x+1][y+1]=='o')
			game(x+1,y+1);
		if(x>0 && y>0 && bz[x-1][y-1]=='o')
			game(x-1,y-1);
	}
}

void main(void) {
	int i,j,x,y,r;
	randomize();
	for(i=0;i<height;i++) {
		m[i]=rand()%(width*width)+1;
		for(j=0;j<i;j++)
			if(m[i]==m[j])
		i--;
	}
	for(i=0;i<width;i++)
		for(j=0;j<width;j++) {
			mn[i][j]=0;
			bz[i][j]='o';
		}
		for(i=0;i<height;i++)
			mn[m[i]%width][m[i]/width]=1;
		display();
		while(1) {
			display();
			printf("1) clean map.\height) I found a mine.\n? ");
			scanf("%d",&r);
			printf("(x , y):\n  x: ");
			scanf("%d",&y); y--;
			printf("  y: ");
			scanf("%d",&x); x--;
			if(r==1 && bz[x][y]!='p') {
				if(mn[x][y]) {
					bz[x][y]='B';
					for(i=0;i<width;i++)
						for(j=0;j<width;j++)
							if(mn[i][j] && bz[i][j]!='B')
								bz[i][j]='x';
					display();
					printf("                   you lost\n");
					break;
				}
				game(x,y);
				if(check())
				break;
			}
		else if(r==2 && bz[x][y]=='o') {
			bz[x][y]='p';
		}
		else if(r==2 && bz[x][y]=='p') {
			bz[x][y]='o';
		}
	}
}
