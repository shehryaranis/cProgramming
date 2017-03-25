#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm,i,xy,yz,j;
initgraph(&gd,&gm,"C:\\TC\\BGI");
for(i=0;i<=500;i+=5)
{

line(40,400,600,400);
if(i%2==0)
{
line(60+i,400,80+i,360);
line(80+i,360,100+i,400);
line(80+i,325,60+i,350);
delay(20);
}
else
{
line(80+i,400,80+i,360);
line(80+i,325,70+i,350);
delay(20);
}
line(80+i,360,80+i,320);
circle(80+i,305,15);

line(80+i,325,100+i,350);
arc(100+i,345,180,360,5);
line(105+i,347,105+i,280);
arc(115+i,280,0,180,10);
arc(95+i,280,0,180,10);
arc(75+i,280,0,180,10);
arc(135+i,280,0,180,10);
arc(105+i,280,0,180,40);
xy=getmaxx();
yz=getmaxy();
for(j=0;j<100;j++)
{
outtextxy(random(xy),random(yz),"|");

setcolor(WHITE);
}

delay(100);
cleardevice();
}

getch();
closegraph();

}
