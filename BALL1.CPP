#include"iostream.h"
#include<alloc.h>
#include"dos.h"
#include"conio.h"
#include<graphics.h>
#include<stdlib.h>

//#define REC2
//#define REC3

int layout() ;
int ball() ;
int game() ;

int main()
{
	int gd = DETECT , gm , i ;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	layout() ;
	ball() ;
	game() ;

	getch() ;

	return 0 ;
}

int layout()
{

	int maxx , maxy ;

	maxx = getmaxx() ;
	maxy = getmaxy() ;
	setcolor(WHITE);

	rectangle(0,10,10,maxy) ;
	rectangle(maxx-10,10,maxx,maxy);

	return 0 ;
}

int ball()
{
	int maxx , maxy ;

	maxx = getmaxx() ;
	maxy = getmaxy() ;

	circle(maxx/2,350,20);

	return 0 ;
}

int game()
{
	char ch ,*buff,*buff1,*buff2 ;

	int maxx , maxy , area , area1 , area2 ;
	int x1 = 15 , y1 = 50 , x2 = 213 , y2 = 60 ;
	int x3 = 213 , y3 = 50 , x4 = 426 , y4 = 60 ;
	int x5 = 426 , y5 = 50 , x6 = 610 , y6 = 60 ;

	int count1 = 1 , count2 = 1 , count3 = 1 ;

	int flag1 = 0 , flag2 = 0 ;

	maxx = getmaxx() ;
	maxy = getmaxy() ;

	srand(time(NULL));

	while(!kbhit())
	{
		setcolor(RED);
		settextstyle(TRIPLEX_FONT,0,7);
		outtextxy(220,150,"START");

		setcolor(YELLOW);
		settextstyle(TRIPLEX_FONT,0,4);
		outtextxy(180,110,"Press Enter to Play");

		while((ch = getch()) == 13)
		{

			while(!kbhit())
			{

			int g = rand()%50 ;

			cleardevice() ;
			layout();
			y1 = y1 + 5 ;
			y2 = y2 + 5 ;
			setcolor(BLUE);
			rectangle(x1,y1,x2,y2);

			area = imagesize(x1,y1,x2,y2);
			buff =(char *)malloc(area);
			getimage(x1,y1,x2,y2,buff);

			delay(50);

			free(buff) ;
			count1++ ;
			count2++ ;

			    #ifdef REC2
				y3 = y3 + 5;
				y4 = y4 + 5;
				rectangle(x3,y3,x4,y4);

				area1 = imagesize(x3,y3,x4,y4);
				buff1 = (char*)malloc(area1);
				getimage(x3,y3,x4,y4,buff1);

				delay(50);

				free(buff1);
			    #endif

			    #ifdef REC3
				y5= y5 + 5;
				y6= y6 + 5;
				rectangle(x5,y5,x6,y6);

				area2 = imagesize(x5,y5,x6,y6);
				buff2 = (char*)malloc(area2);
				getimage(x5,y5,x6,y6,buff2) ;

				delay(50);

				free(buff2);
			    #endif

			if(count1 == 20 )
			#define REC2

			if(count2 == 40 )
			#define REC3

			if( y2 >= maxy || y1 >= maxy )
			{
				y2 = 60 ;
				y1 = 50 ;
			}

			if( y4 >= maxy || y3 >= maxy )
			{
				y4 = 60 ;
				y3 = 50 ;
				count1 = 0 ;
				#undef REC1
			}

			if(y6 >= maxy || y5 >= maxy )
			{
				y5 = 50;
				y6 = 60;
				count2 = 0 ;
				#undef REC2
			}
		    }
		}
	}
	return 0 ;
}