#include<stdio.h>
#include<conio.h>
#include "my.h"

	void main()
		{
		int a[2][3];
		//int pos;
		int i,j;
		clrscr();
		for(j=0;j<2;j++)
			{
				for(i=0;i<3;i++)
					{
					scanf("%d",&a[i][j]);
					}
			}
			/*
			printf("\n Enter Position where you want to store the data : ");
			scanf("%d",&pos);
			printf("Please provide the data : ");
			scanf("%d",&a[pos-1]);*/

		       for(j=0;j<2;j++)
				{
				for(i=0;i<3;i++)
					{
					printf("%d   ",a[i][j]);
					}
					printf("\n");
			       }


		getch();		// library function
		}

