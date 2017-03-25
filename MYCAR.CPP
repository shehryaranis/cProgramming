#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm;
int i;
initgraph(&gd,&gm,"C://TC/BGI");
//loop to move car
for(i=0;i<=500;i+=5){
cleardevice();



//road
setcolor(3);

line(0,270,640,270);
//car body
setcolor(2);
line(110+i,210,180+i,210);
line(180+i,210,200+i,230);
line(200+i,230,240+i,235);
line(240+i,235,242+i,236);
line(242+i,236,242+i,250);

line(242+i,250,240+i,252);
line(240+i,252,200+i,252);
arc(184+i,252,0,180,15);
line(170+i,252,130+i,252);
arc(115+i,252,0,180,15);
line(100+i,252,80+i,252);
line(110+i,210,80+i,230);
line(80+i,230,80+i,252);

circle(115+i,252,10);
circle(184+i,252,10);
//INTERNAL CAR
line(155+i,214,178+i,214);
line(178+i,214,193+i,229);
line(193+i,229,155+i,229);
line(155+i,229,155+i,214);
line(150+i,214,120+i,214);
line(150+i,229,120+i,229);
line(120+i,214,120+i,229);
line(150+i,214,150+i,229);
line(110+i,214,110+i,229);
line(110+i,214,90+i,229);
line(90+i,229,110+i,229);
setfillstyle(1,1);

//circle(90+i,240,5);
floodfill(90+i,240,2);
delay(100);
}
getch();
closegraph();



}