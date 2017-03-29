#include<stdio.h>
#include<conio.h>
void main()
{
int a[3]={43,55,32};
int pos, i;
clrscr();
for(i=0;i<3;i++)
{
printf("%d	",a[i]);
}
printf("\n Enter position to change");
scanf("%d",&pos);
printf("please provide the data:	");
scanf("%d",&a[pos-1]);
for(i=0;i<3;i++)
{
printf("%d	",a[i]);
}
getch();
}