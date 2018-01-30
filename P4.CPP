#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>



int bkround()
{
	setbkcolor(0);
	setcolor(GREEN);
	line(0,(getmaxy()*3)/4,getmaxx(),(getmaxy()*3)/4);
	setfillstyle(HATCH_FILL,GREEN);
	floodfill(getmaxx(),getmaxy(),1);
	setcolor(11);
	line(0,(getmaxy()*3)/4,getmaxx(),(getmaxy()*3)/4);
	setfillstyle(SOLID_FILL,11);
	floodfill(0,0,1);
	setcolor(YELLOW);

	for(int i=25;i>=0;i--)
		circle(((getmaxx()*3)/4)+80,35,i);



	return 0;
}

int brk1(int x)
{
	if(x!=0)
	{
		setfillstyle(INTERLEAVE_FILL,BROWN);
		bar(getmaxx()-45,((getmaxy()*3)/4)-20,getmaxx()-5,((getmaxy()*3)/4)+20);
	}
}

int brk2(int x)
{
	if(x!=0)
	{
		setfillstyle(INTERLEAVE_FILL,BROWN);
		bar(getmaxx()-90,((getmaxy()*3)/4)-20,getmaxx()-50,((getmaxy()*3)/4)+20);
	}
}

int brk3(int x)
{
	if(x!=0)
	{
		setfillstyle(INTERLEAVE_FILL,BROWN);
		bar(getmaxx()-135,((getmaxy()*3)/4)-20,getmaxx()-95,((getmaxy()*3)/4)+20);
	}
}
int brk4(int x)
{
	if(x!=0)
	{
		setfillstyle(INTERLEAVE_FILL,BROWN);
		bar(getmaxx()-65,((getmaxy()*3)/4)-62,getmaxx()-25,((getmaxy()*3)/4)-22);
	}
}
int brk5(int x)
{
	if(x!=0)
	{
		setfillstyle(INTERLEAVE_FILL,BROWN);
		bar(getmaxx()-110,((getmaxy()*3)/4)-62,getmaxx()-70,((getmaxy()*3)/4)-22);
	}
}
int brk6(int x)
{
	if(x!=0)
	{
		setfillstyle(INTERLEAVE_FILL,BROWN);
		bar(getmaxx()-90,((getmaxy()*3)/4)-104,getmaxx()-50,((getmaxy()*3)/4)-64);
	}
}
int brkall(int b1,int b2,int b3,int b4,int b5,int b6)
{
	int failsafe=10;

	if(b5==0)
		b6=0;
	if(b3==0)
		b5=0;
	if(b6!=0)
		b4=failsafe;
	if(b5!=0)
		b2=failsafe;
	if(b4!=0)
		b1=failsafe;

	brk1(b1);
	brk2(b2);
	brk3(b3);
	brk4(b4);
	brk5(b5);
	brk6(b6);
}
int initiate()
{
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
	setbkcolor(1);
	setcolor(15);
	int x=getmaxx()/2;
	int y=getmaxy()/2;

	setcolor(13);
	outtextxy(x,y,"WE PRESENT TO YOU");
	delay(2000);
	cleardevice();

	for(int i=0;i<=getmaxx();i++)
	{
		setcolor(10);
		outtextxy(x,y,"A DHARMA PRODUCTIONS GAME");
		setcolor(7);
		circle(i,((getmaxy()*3)/4),10);
		setcolor(10);
		circle(i,(getmaxy()/4),10);
		setcolor(5);
		circle(i,((getmaxy()*3)/4)+25,10);
		setcolor(3);
		circle(i,(getmaxy()/4)-25,10);
	}
	delay(3000);
	cleardevice();
}

int load_scr()
 {
   clrscr();
     for(int i=1;i<=50;i++)
      { clrscr();
  cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';
 for(int j=1;j<=i;j++)
  cout<<"²";
  cout<<"\n\n\t "<<2*i<<"%";
 if( i > 1 && i < 20)
  cout<<"\n\n\tCreating Temporary files";
 else if( i > 20 && i<40)
  cout<<"\n\n\tAccessing Main Memory";
 else if(i >40 && i<48)
  cout<<"\n\n\tAccessing Cache";
 else cout<<"\n\n\tComplete. Press Enter to Continue ";
  delay(150 - i*3);
      }
getch();
 }

 int main_menu()
 {
	setbkcolor(0);
	cleardevice();
	int midx=getmaxx()/2,maxx=getmaxx(),maxy=getmaxy(),miny=10,midy=getmaxy()/2;
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	setcolor(14);
	outtextxy(midx,0,"THE BIRDS");
	setfillstyle(LTBKSLASH_FILL,LIGHTRED);
	bar(0,0,30,maxy);
	bar(maxx,0,maxx-30,maxy);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
	setcolor(1);
	outtextxy(midx,midy,"1.PLAY");
	outtextxy(midx,midy+40,"2.INSTRUCTIONS");
	outtextxy(midx,midy+80,"3.EXIT");
	int menu;
	cin>> menu;

	return menu;
}
double ball_traj(double angle)
{
   long double g=9.8;
   long double max_height=(3*getmaxy())/4,ycoor;
   long double velocity=0,time=0;
   long double tmp1=0,tmp2=0,tmp3=0,tmp4=0;

   tmp1=(sin(angle)*sin(angle));              //defining velocity
   tmp2=2*g*max_height;
   velocity=sqrt(tmp2/tmp1);

   tmp3=velocity*sin(angle);
   time=tmp3/g;
   tmp4=(velocity*cos(angle));


   for(int t1=0;t1<=time/2;t1++)
   {
       for(int i=0;i<=max_height;i=i+tmp3-(g*t1))
       {
	   circle(0+(tmp4*t1),getmaxy()+i,15);
	   delay(1000);
	   cleardevice();


       }


   }



}

void main()
{
	int gd=DETECT,gm;

      //	load_scr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");

     //	initiate();
	cleardevice();
    //	int menu=main_menu();

       //	bkround();
	brkall(1,2,3,4,5,6);
	ball_traj(0.785);


	getch();
	cleardevice();
	closegraph();

}
