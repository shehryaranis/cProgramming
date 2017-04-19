#include<conio.h>
#include<stdio.h>
	void main()
		{
		int a[4][3];
		int x,y;
		clrscr();
		for(x=0;x<4;x++)
			{
			for(y=0;y<3;y++)
				{
				printf("Enter Array Element For [%d][%d]",x,y);
				 scanf("%d",&a[x][y]);
				 clrscr();
				}
			}
			clrscr();
			getch();

		for(x=0;x<4;x++)
			{
			for(y=0;y<3;y++)
				{
				if(a[x][y]%3==0)
				{
				a[x][y]+=a[x][y];
				printf("%d", a[x][y]);
				}
			       //	printf("%d ", a[x][y]);
				}
			printf("\n");
			}
		getch();
		}
