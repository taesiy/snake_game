#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void draw();
void setup();
void control();
void logic();

int height=20,width=40,x,y,fruitx,fruity,flag,gameend,score;
int tailx[100],taily[100];
int piece=0;

void logic()
{
	int i;
	int prevx,prevy,prev2x,prev2y;
	prevx=tailx[0];
	prevy=taily[0];
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<=piece;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(flag)
	{
		case 1:
			{
				x--;
				break;
			}
		case 2 :
			{
				x++;
				break;
			}
		case 3 :
			{
				y--;
				break;
			}
		case 4 :
		{
			 y++;
			 break;
		}		
	}
	if(x==0 || x==height || y==0 || y==width)
	{
		gameend=1;
	}
	if (x==fruitx && y==fruity)
	{
		label3:
	fruitx=rand()%20;
	if(fruitx==0)
	goto label3;
	
	label4:
	fruity=rand()%40;
	if(fruity==0)
	goto label4;
	score=score+1;
	piece++;
	}
}
void control()
{
	if(kbhit())
	{
		 switch(getch())
		 {
		 	case 'w' :
		 		{
		 			flag=1;
		 			break;
					}
				case 's' :
		 		{
		 			flag=2;
		 			break;
					}
				case 'a' :
		 		{
		 			flag=3;
		 			break;
					}
				case 'd' :
		 		{
		 			flag=4;
		 			break;
					}
			}
	}
}
void setup()
{
	x=height/2;
	y=width/2;
	
	label1:
	fruitx=rand()%20;
	if(fruitx==0)
	goto label1;
	
	label2:
	fruity=rand()%40;
	if(fruity==0)
	goto label2;
	gameend=0;
	score=0;
	piece++;
	
}
void draw()
{
	system("cls"); //used to clearscreen
	int i,j,k,ch;
	for(i=0;i<=height;i++)
	{
		for(j=0;j<=width;j++)
		{
			if(i==0 || i==height || j==0 || j==width)
			{
				printf("*");
			}
			else
			{
				if(i==x && j==y)
				{
					printf("0");
				}
				else if (i==fruitx && j==fruity)
				{
					printf("+");
				}
				else
				{
					ch=0;
					for(k=0;k<piece;k++)
					{
						if(i==tailx[k] && j==taily[k])
						{
							printf("o");
							ch=1;
						}
					}
					if(ch==0);
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	printf("your score = %d",score);
}
int main()
{
	setup();
	while(gameend!=1)
	{
		control();
 draw();
 logic();
	}
	
}
