


#include"iostream.h"
#include<alloc.h>
#include"dos.h"
#include"conio.h"
#include<graphics.h>
#include<stdlib.h>

int layout() ;
int ball() ;
int out() ;
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
	setcolor(YELLOW);

	rectangle(0,10,10,maxy) ;
	rectangle(maxx-10,10,maxx,maxy);

	return 0 ;
}

int ball()
{
	int maxx , maxy ;

	setcolor(RED);
	maxx = getmaxx() ;
	maxy = getmaxy() ;

	setfillstyle(2,RED);
	circle(maxx/2,350,20);
	floodfill(maxx/2,350,RED);

	return 0 ;
}

int game()
{
	char ch ,*buff,*buff1,*buff2,*buff3 ;

	int maxx , maxy , area , area1 , area2 , area3 ;

	maxx = getmaxx() ;
	maxy = getmaxy() ;

	int x1 = 15 , y1 = 50 , x2 = 213 , y2 = 60 ;
	int x3 = 213 , y3 = 50 , x4 = 426 , y4 = 60 ;
	int x5 = 426 , y5 = 50 , x6 = 610 , y6 = 60 ;

	int tr1 = 1 , tr2 = 1 , tr3 = 1 ;

	int recx1 = 15 , recy1 = 50 , recx2 = (maxx-15) , recy2 = 60 ;

	int rec1 = 0 , rec2 = 0 , rec3 = 0 ;

	int count1 = 1 , count2 = 1 , count3 = 1 ;

	int hump1 = 1 , hump2 = 1 , hump3 = 1 , hump4 = 1 ;

	int flag1 = 0 , flag2 = 0 , flag_rec = 0 ;

	int xc = (maxx/2) , yc = 350 , rc = 20 ;

	int gh = 1 ;

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

			while(1)
			{

			cleardevice() ;
			layout();

			if(tr1 == 1)
			{
			setfillstyle(4,BLUE);
			setcolor(BLUE);
			rectangle(x1,y1,x2,y2);
			floodfill(x1+3,y1+3,BLUE);
			y1 = y1 + 5 ;
			y2 = y2 + 5 ;

			area = imagesize(x1,y1,x2,y2);
			buff =(char *)malloc(area);
			getimage(x1,y1,x2,y2,buff);

			delay(10);

			free(buff) ;
			count1++ ;
			count2++ ;
			}

			if(count1 == 25)
			flag1 = 1 ;
			if(count2 == 45)
			flag2 = 1 ;

			if(flag1 == 1 && tr2 == 1)
			{
				area1 = imagesize(x3,y3,x4,y4);
				buff1 = (char*)malloc(area1);
				rectangle(x3,y3,x4,y4);
				floodfill(x3+3,y3+3,BLUE);

				y3 = y3 + 5;
				y4 = y4 + 5;

				getimage(x3,y3,x4,y4,buff1);
				free(buff1);

				delay(10);
			}

			if(flag2 == 1 && tr3 == 1)
			{
				area2 = imagesize(x5,y5,x6,y6);
				buff2 = (char*)malloc(area2);
				rectangle(x5,y5,x6,y6);
				floodfill(x5+3,y5+3,BLUE);

				y5= y5 + 5;
				y6= y6 + 5;

				getimage(x5,y5,x6,y6,buff2) ;
				free(buff2);

				delay(10);
			}

			if( y2 >= maxy || y1 >= maxy )
			{
				y2 = 60 ;
				y1 = 50 ;
				hump1 = 1 ;
				count1 = 0 ;
				rec1++ ;
				count2 = 0 ;
			}

			if( y4 >= maxy || y3 >= maxy )
			{
				y4 = 60 ;
				y3 = 50 ;
				hump2 = 1 ;
				flag1 = 0 ;
				rec2++;
				count1 = 0 ;
			}

			if( y6 >= maxy || y5 >= maxy )
			{
				y5 = 50;
				y6 = 60;
				rec3++ ;
				hump3 = 1 ;
				hump4 = 1 ;
				flag2 = 0 ;
				count2 = 0 ;
			}

	// For the ball movement

			setcolor(RED);
			setfillstyle(SOLID_FILL,RED);
			circle(xc,yc,rc);
			floodfill(xc,yc,RED);

			if(kbhit())
			{
				ch = getch();
				if(ch == '8')
				exit(0);
			}

			if(kbhit())
			{
				ch = getch();
				switch(ch)
				{
					case 77:
						xc = xc + 25 ;
						break;
					case 75:
						xc = xc - 25 ;
						break;
				}
			}

			if( y2 > yc+20)
			hump1 = 0 ;

			if( y4 > yc+20)
			hump2 = 0 ;

			if( y6 > yc+20)
			hump3 = 0;

			if( xc < 220 )
			hump4 = 0 ;

			if( xc > maxx )
			hump4 = 1 ;

			if(xc <= 30)
			{
				xc = 30 ;
			}
			if(xc >= ((maxx-40)))
			{
				xc = maxx - 30;
			}

			if( (y1 >= (yc-20) && y2 <= (yc+20) && (xc-20) <= x2) && hump1 == 1)
			{
				delay(1000);
				out();
				getch() ;
				closegraph();
				restorecrtmode();
				exit(0);
			}

			if( (y3 >= (yc-20) && y4 <= (yc+20) && (xc+20) >= x3 && (xc+20) <= x4 && (xc-20) <= x4 ) && hump2 == 1)
			{
				delay(1000);
				out();
				getch();
				closegraph();
				restorecrtmode();
				exit(0);
			}

			if( (y3 >= (yc-20) && y4 <= (yc+20)  && (xc-20) <= x4 ) && hump4 == 1)
			{
				delay(1000);
				out();
				getch();
				closegraph();
				restorecrtmode();
				exit(0);
			}

			if( (y5 >= (yc-20) && y6 <= (yc+20) && (xc+20) >= x5) && hump3 == 1)
			{
				delay(1000);
				out();
				getch();
				closegraph();
				restorecrtmode();
				exit(0);
			}

			if( (rec1+rec2+rec3) >= 4 )
			{
				 y1 = 50 ; y2 = 60 ;
				 y3 = 50 ; y4 = 60 ;
				 y5 = 50 ; y6 = 60 ;

			  //	cout<<"hi" ;
				tr1 = 0 ;
				tr2 = 0 ;
				tr3 = 0 ;

				flag_rec = 1 ;

				setcolor(GREEN);
				setfillstyle(1,GREEN);
				rectangle(recx1,recy1,recx2,recy2);
				floodfill(recx1+5,recy1+5,GREEN);

				recy1 = recy1 + 5 ;
				recy2 = recy2 + 5 ;

				area3 = imagesize(recx1,recy1,recx2,recy2);
				buff3 = (char*)malloc(area3) ;
				getimage(recx1,recy1,recx2,recy2,buff3);

				delay(50);

				free(buff3);
			}

			if( flag_rec == 1 && kbhit() )
			{
				cout<<"game";
				char ch = getch() ;

				if(ch==32)
				{
					setlinestyle(0,0,3);
					setcolor(WHITE);
					line(xc+20,yc,maxx-10,350);
					line(10,yc,xc-20,yc);
					delay(30);
					cout<<"what";
				}
				if(kbhit())
				{
					ch = getch();
					if(ch == 80)
					{
						char *buffc ;
						int areac ;
						setlinestyle(0,0,3);
						yc = yc+25 ;
						if(yc+20 >= maxy)
						{
						yc = maxy-20 ;
						int bu = 1 ;
		    //				goto gy ;
						}
						setcolor(RED);
						setfillstyle(1,RED);
						circle(xc,yc,20);
						floodfill(xc,yc,RED);

						setcolor(WHITE);
						line(xc+20,yc,maxx-10,350);
						line(10,350,xc-20,yc);
						delay(30);
				       }
				}
				setlinestyle(0,0,0);
			}
			else{
					  yc = 350 ; rc = 20 ;
				       }

			if(recy2 >= yc-20 && gh == 1)
			{
				rec1 = 0 ;
				rec2 = 0 ;
				rec3 = 0 ;
				tr1 = 1 ;
				tr2 = 1 ;
				tr3 = 1 ;
				recx1 = 15 ;
				recx2 = maxx - 15 ;
				recy1 = 50 ;
				recy2 = 60 ;
				flag1 = 0 ;
				flag_rec = 0 ;

			}

			delay(50);
		    }
		}
	}
	return 0 ;
}

int out()
{

		  int maxx = getmaxx() , maxy = getmaxy() , y ;
		  while(!kbhit())
		  {
		  db9:
		  cleardevice();
		  srand(time(NULL));
		  y = rand()%16;
		  if(y == WHITE)
		  goto db9;
		  setcolor(y);
		  setbkcolor(BLACK);
		  settextstyle(TRIPLEX_FONT,0,5) ;
		  outtextxy((maxx/2)-100,maxy/5,"GAME OVER");
		  settextstyle(TRIPLEX_FONT,0,3);
		  outtextxy(100,300," PRESS Any key to exit ");
		  delay(100);
		  }
		  return 0 ;
}

