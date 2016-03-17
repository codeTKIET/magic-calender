#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include"string.h"
#include"stdlib.h"
#include<dos.h>
void findday(int , int ,int);
void cal();
void about(void);
void thanku(void);
int main(void);
class one
{
public:
int d,m,y;
int n,b,v,p,q,w,r,e,z,f,g,h;
void getdata1();
void getdata2();
void getdata3();
void getdata4();
void calender();
};
void one::getdata1()
{
cout<<"Enter the DATE MONTH and YEAR:";
cin>>d>>m>>y;

if(y>=1582&&y<=20000)
{
if(m==2)
{
if(y%400==0)
{
if(d>=1&&d<=29)
{
getdata2();
getdata3();
getdata4();
calender();
}
else
{
cout<<"invalid date";
}
}
else if(y%100==0)
{
if(d>=1&&d<=28)
{
getdata2();
getdata3();
getdata4();
calender();
}
else
{
cout<<"invalid date";
}
}
else if(y%4==0)
{
 if(d>=1&&d<=29)
{
getdata2();
getdata3();
getdata4();
calender();
}
else
{
cout<<"invalid date";
}
}
else
{
if(d>=1&&d<=28)
{
getdata2();
getdata3();
getdata4();
calender();
}
else
{
cout<<"invalid date";
}
}

}
if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
{
if(d>=1&&d<=31)
{
getdata2();
getdata3();
getdata4();
calender();
}
else
{
cout<<"invalid date";
}
}
if(m==4||m==6||m==9||m==11)
{
if(d>=1&&d<=30)
{
getdata2();
getdata3();
getdata4();
calender();
}
else
{
cout<<"invalid date";
}
}
}
else
cout<<"Invalid date";
}


void one::getdata2()
{
b=y-1;
cout<<"\nremaining years are:"<<b<<"\n";
v=b%100;
  cout<<"\nno. of years left"<<v<<"\n";
p=b-v;
cout<<p<<"\n";
if(p%400==100)
{
q=5;
}
if(p%400==200)
{
q=3;
}
if(p%400==300)
{
q=1;
}
if(p%400==0)
{
q=0;
}
cout<<"no. of odd days in"<<p<<"years is:"<<q<<"\n";
//for remaining years
w=v/4;
cout<<"out of"<<v<<"yeras leap years are:"<<w<<"\n";
e=v-w;
cout<<"remaining normal years are:"<<e<<"\n";
if(w && e)
{
r=w*2;
cout<<"no. of odd days in"<<w<<"yeras is :"<<r<<"\n";
z=e;
cout<<"no. of odd days in"<<e<<"yeras is:"<<z<<"\n";
}
}

void one::getdata3()
{
f=m-1;
cout<<"remaining months are:"<<f<<"\n";
if(f==0)
{
g=0;
}
if(f==1)
{
g=3;

}
if(f==2)
{
if(y%4==0||y%400==0)
{
g=4;
}
else
{
g=3;
}
}
if(f==3)
{
g=6;
}
if(f==4)
{
g=8;
}
 if(f==5)
{
g=11;
}
if(f==6)
{
g=13;
}
 if(f==7)
{
g=16;
}
 if(f==8)
{
g=19;
}
if(f==9)
{
g=21;
}
if(f==10)
{
g=24;
}
if(f==11)
{
g=26;
}
cout<<"no. of odd days in"<<f<<" months is "<<g<<"\n";
}


void one::getdata4()
{
//to find out no. of odd days in that month
n=(d%7);
cout<<"no. of odd days in that months are"<<n<<"\n";
if(y%4==0 || y%400==0)
{
if(f>2)
{
h=(q+r+z+g+n+1)%7;
}
else
{
h=(q+r+z+g+n)%7;
}
}
else
{
h=(q+r+z+g+n)%7;
}
if(h==0)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<"is sunday\n";
}
else if(h==1)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<" is monday\n";
}
else if(h==2)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<"is tuesday\n";
}
else if(h==3)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<"is wednesday\n";
}
else if(h==4)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<"is thursday\n";
}
else if(h==5)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<"is friday\n";
}
else if(h==6)
{
cout<<"\nthe day on"<<d<<"/"<<m<<"/"<<y<<"is saturday\n";
}
}
void one::calender()
{
  clrscr();
  int gd=EGA,gm=EGAHI;
  initgraph(&gd,&gm,"C:\\TC\\bgi ");
  findday(m,y,d);
  getch();
  closegraph();
}
void findday(int mon,int y,int date)
{
  int k=1,m=11,D,C,f,i,total=0,t,I,d,x1=115,y1=160,q,r,v,top,left,bottom,right;
 static int s=0;
 char st2[3],st3[9],st4[5];
  int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
  char
*month[]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMEBER"};
 // restorecrtmode();
  y-=1;
  C=y/100;
  D=y%100;
  f=(k+((13*m-1)/5)+D+(D/4)+(C/4)-(2*C));
  i=f%7;
  if(i<0)
     i+=7;
  y++;
  if(y%4==0)
  days[1]=29;
  for(t=0;t<mon-1;t++)
  {
     total+=days[t];
  }
  I=total%7;
  d=I+i;
  if(d>=7)
     d=d%7;
  setgraphmode(getgraphmode());
  cal();
  v=mon-1;
  strcpy(st3,month[v]);
  itoa(y,st4,10);
  settextstyle(2,0,8);
  outtextxy(100,90,st3);
  outtextxy(250,90,st4);
  q=days[mon-1];
  settextstyle(1,0,2);
  setcolor(15);
  for(r=1;r<=d;r++)
  {
     x1+=58;
     s++;
  }
  for(r=1;r<=q;r++)
  {
     itoa(r,st2,10);
     if(date==r)
     {
      if((date==26&&mon==1)|(date==15&&mon==8))
      {
      setcolor(BLUE);
       left=x1-11,top=y1-5,right=x1+42,bottom=y1+5;
      setfillstyle(SOLID_FILL, 6);
      bar(left,top,right,bottom);
       left=x1-11,top=y1+5,right=x1+42,bottom=y1+15;
      setfillstyle(SOLID_FILL, WHITE);
      bar(left,top,right,bottom);
      setcolor(WHITE);
       left=x1-11,top=y1+15,right=x1+42,bottom=y1+25;
      setfillstyle(SOLID_FILL, GREEN);
      bar(left,top,right,bottom);
      }
     else{
       left=x1-11,top=y1-4,right=x1+42,bottom=y1+24;
      setfillstyle(SOLID_FILL, RED);
      bar(left,top,right,bottom);
     }}
     if(s>=6)
     {
	outtextxy(x1,y1,st2);
	y1+=30;
	x1=112;
	s=0;
	continue;
     }
     outtextxy(x1,y1,st2);
     x1+=60;
     s++;

  }
  s=0;
}
void cal()
{
  cleardevice();
  int l=100,t=125,r=155,b=185,g,x=110,y=127;
  char *day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  char st1[4];
  setbkcolor(0);
  setcolor(15);
  settextstyle(10,0,5);
  outtextxy(160,-20,"CALENDAR");
  setfillstyle(1,9);
  bar(85,115,530,345);
  setfillstyle(1,0);
  bar3d(l,t,r,b,0,0);
  bar3d(l,t+30,r,b+30,0,0);
  bar3d(l,t+60,r,b+60,0,0);
  bar3d(l,t+90,r,b+90,0,0);
  bar3d(l,t+120,r,b+120,0,0);
  bar3d(l,t+150,r,b+150,0,0);
  bar3d(l,t+180,r,b+150,0,0);
  bar3d(l+60,t,r+60,b,0,0);
  bar3d(l+60,t+30,r+60,b+30,0,0);
  bar3d(l+60,t+60,r+60,b+60,0,0);
  bar3d(l+60,t+90,r+60,b+90,0,0);
  bar3d(l+60,t+120,r+60,b+120,0,0);
  bar3d(l+60,t+150,r+60,b+150,0,0);
  bar3d(l+60,t+180,r+60,b+150,0,0);
  bar3d(l+120,t,r+120,b,0,0);
  bar3d(l+120,t+30,r+120,b+30,0,0);
  bar3d(l+120,t+60,r+120,b+60,0,0);
  bar3d(l+120,t+90,r+120,b+90,0,0);
  bar3d(l+120,t+120,r+120,b+120,0,0);
  bar3d(l+120,t+150,r+120,b+150,0,0);
  bar3d(l+120,t+180,r+120,b+150,0,0);
  bar3d(l+180,t,r+180,b,0,0);
  bar3d(l+180,t+30,r+180,b+30,0,0);
  bar3d(l+180,t+60,r+180,b+60,0,0);
  bar3d(l+180,t+90,r+180,b+90,0,0);
  bar3d(l+180,t+120,r+180,b+120,0,0);
  bar3d(l+180,t+150,r+180,b+150,0,0);
  bar3d(l+180,t+180,r+180,b+150,0,0);
  bar3d(l+240,t,r+240,b,0,0);
  bar3d(l+240,t+30,r+240,b+30,0,0);
  bar3d(l+240,t+60,r+240,b+60,0,0);
  bar3d(l+240,t+90,r+240,b+90,0,0);
  bar3d(l+240,t+120,r+240,b+120,0,0);
  bar3d(l+240,t+150,r+240,b+150,0,0);
  bar3d(l+240,t+180,r+240,b+150,0,0);
  bar3d(l+300,t,r+300,b,0,0);
  bar3d(l+300,t+30,r+300,b+30,0,0);
  bar3d(l+300,t+60,r+300,b+60,0,0);
  bar3d(l+300,t+90,r+300,b+90,0,0);
  bar3d(l+300,t+120,r+300,b+120,0,0);
  bar3d(l+300,t+150,r+300,b+150,0,0);
  bar3d(l+300,t+180,r+300,b+150,0,0);
  bar3d(l+360,t,r+360,b,0,0);
  bar3d(l+360,t+30,r+360,b+30,0,0);
  bar3d(l+360,t+60,r+360,b+60,0,0);
  bar3d(l+360,t+90,r+360,b+90,0,0);
  bar3d(l+360,t+120,r+360,b+120,0,0);
  bar3d(l+360,t+150,r+360,b+150,0,0);
  bar3d(l+360,t+180,r+360,b+150,0,0);
  settextstyle(1,0,2);
  setcolor(15);
  for(g=0;g<7;g++)
  {
     strcpy(st1,day[g]);
     outtextxy(x,y,st1);
     x+=60;
  }
}


void about()
{
  char msg[80];
  int gdriver = EGA, gmode = EGAHI, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setbkcolor(15);
  setcolor(RED);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
  outtextxy(50,40,"Tatyasaheb Kore College Of Engineering & Technology");
  outtextxy(200,80,"Department Of CSE");
  outtextxy(200,130,"Mini Project By");
  outtextxy(200,160,"Omkar S. Malgaonkar");
  outtextxy(200,190,"Prafful J. Patil");
  outtextxy(200,220,"Ruturaj P. Patil");
  outtextxy(200,250,"Sushant S. Gaikwad");

  setcolor(2);
  int h=getmaxy() - 35;
  int k=10;
  for(int b=0;b<77;b++)
  {
   outtextxy(k,h,"-");
   k+=8;
   delay(100);
       }

  closegraph();
}

void thanku()
{
  int a,b;
  char msg[80];
  int gdriver = EGA, gmode = EGAHI, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setbkcolor(3);
  a = getmaxx() / 2;
  a=a-100;
  b = getmaxy() / 2;
  b=b-50;
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
      outtextxy(a, b, "Thank YOU !");
      delay(2500);
  closegraph();
}

int main()
{
clrscr();
about();
one asd;
char c;
do
{
clrscr();
cout<<"1.proceed\n0.exit\nenter your choice";
cin>>c;
switch(c)
{
case '1':
asd.getdata1();
getch();
break;
}
}
while(c!='0');
thanku();
return 0;

}
