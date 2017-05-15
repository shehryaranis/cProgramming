#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#define fname "question.mbn"

void load_scr();  	// load fun
void main_scr();  	// main scr fun
void selm(int s);	//selection menu fun
void add_scr();		//add question fun
void add_ra(int s);	// add ques select ri8 ans
void sr_q(); 		//search question fun
void del_q(); 		//DELETE QUESTIONS
void all_q(); 		//see all questions
void quiz_q(); 		//Take a Quiz

struct ques
	{
	char q[100],a1[100],a2[100],a3[100],a4[100];
	int r;
	};
//main code
void main()
	{
	int gdriver=DETECT,gmode;
	int sm=1;
	char s;

	struct ques m;



	initgraph(&gdriver,&gmode,"c://tc//bgi");
	load_scr();
	//select screen

	mmenu://label
	sm=1;
	s=' ';

	main_scr();
	do
	  {
	  selm(sm);
	  s=getch();
	  switch(s)
		{
		case 72:
		if(sm!=1)
		sm-=1;
		else
		sm=6;
		break;
		case 80:
		if(sm!=6)
		sm+=1;
		else
		sm=1;
		break;
		}
	  }while(s!='\r');

	switch(sm)
		{
		case 1:
		// ADD QUESTION
		add_scr();
		break;
		case 2:
		//SEARCH QUESTION
		sr_q();
		break;
		case 3:
		//DELETE QUESTION
		del_q();
		break;
		case 4:
		// All ques
		all_q();
		break;
		case 5:
		//take a quiz
		quiz_q();
		break;
		case 6:
		//EXIT
		cleardevice();
		setcolor(7);
		setfillstyle(8,3);
		rectangle(1,1,639,479);
		rectangle(20,20,620,460);
		floodfill(2,2,7);
		setcolor(7);
		line(20,190,620,190);
		line(20,200,620,200);
		setfillstyle(11,8);
		floodfill(25,25,7);
		setcolor(5);
		settextstyle(8,0,6);
		outtextxy(100,80,"QUESTION BANK");
		setfillstyle(12,1);
		setfillstyle(12,1);
		floodfill(21,201,7);

		setcolor(3);
		settextstyle(6,0,3);
		outtextxy(70,200,"COURSE INSTRUCTOR");
		setcolor(6);
		settextstyle(6,0,1);
		outtextxy(95,230,"SIR AMEEN KHOWAJA");

		setcolor(3);
		settextstyle(6,0,3);
		outtextxy(420,200,"LAB INSTRUCTOR");
		setcolor(6);
		settextstyle(6,0,1);
		outtextxy(425,230,"SIR ADNAN AHMED");

		setcolor(3);
		settextstyle(6,0,3);
		outtextxy(220,300,"PROJECT MEMBERS");
		setcolor(6);
		settextstyle(6,0,1);
		outtextxy(180,330,"WAJAHAT AHMED AND ALI HAIDER");

		setcolor(7);
		settextstyle(7,0,1);
		outtextxy(100,380,"SINDH MADARESSATUL ISLAM UNIVERSITY");

		getch();
		closegraph();
		exit(1);
		break;
		}


	goto mmenu;    //jump to label mmenu

	}
//TAKE A QUIZ
void quiz_q()

	{
	struct ques m;
	FILE *f;
	char ch,scs[10];
	int t=0,sc=0;
	f=fopen(fname,"a+");
	cleardevice();
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	floodfill(2,2,7);
	setcolor(15);
	rectangle(40,40,600,440);
	setfillstyle(1,8);
	floodfill(44,44,15);
	settextstyle(3,0,5);
	outtextxy(70,44,"WELCOME TO THE QUIZ !!!");
	settextstyle(2,0,5);
	outtextxy(150,250,"PRESS ANY KEY TO START.ENTER TO BACK ON MENU");
	ch=getch();
	if(ch=='\r')
		{
		goto endqz;
		}
	while(fread(&m,sizeof(m),1,f)!=0)
		{
		if(t<10)
			{
			cleardevice();
			setcolor(7);
			setfillstyle(8,3);
			rectangle(1,1,639,479);
			rectangle(20,20,620,460);
			floodfill(2,2,7);
			floodfill(2,2,7);
			setcolor(15);
			rectangle(40,40,600,440);
			setfillstyle(1,8);
			floodfill(44,44,15);
			settextstyle(3,0,5);
			outtextxy(250,44,"QUIZ");

			settextstyle(2,0,5);
			outtextxy(150,150,"PRESS The RIGHT ANSWER KEY(A B C D)");
			outtextxy(60,200,"Q : ");
			outtextxy(100,200,m.q);
			outtextxy(60,250,"A : ");
			outtextxy(100,250,m.a1);
			outtextxy(360,250,"B : ");
			outtextxy(400,250,m.a2);
			outtextxy(60,300,"C : ");
			outtextxy(100,300,m.a3);
			outtextxy(360,300,"D : ");
			outtextxy(400,300,m.a4);
			t++;
			ch=getch();
			switch(ch)
				{
				case 'A':
				case 'a':
				if(m.r==1)
				sc++;
				break;
				case 'B':
				case 'b':
				if(m.r==2)
				sc++;
				break;
				case 'C':
				case 'c':
				if(m.r==3)
				sc++;
				break;
				case 'D':
				case 'd':
				if(m.r==4)
				sc++;
				break;

				}
			}
		}

			cleardevice();
			setcolor(7);
			setfillstyle(8,3);
			rectangle(1,1,639,479);
			rectangle(20,20,620,460);
			floodfill(2,2,7);
			floodfill(2,2,7);
			setcolor(15);
			rectangle(40,40,600,440);
			setfillstyle(1,8);
			floodfill(44,44,15);
			settextstyle(6,0,5);
			outtextxy(250,44,"FINAL SCORE");
			itoa(sc,scs,10);
			settextstyle(2,0,5);
			outtextxy(280,200,scs);
			outtextxy(310,200,"OUT OF");
			itoa(t,scs,10);
			outtextxy(380,200,scs);
			outtextxy(200,250,"Press Any Key TO go Back on Menu");

			getch();

	endqz:
	fclose(f);
	}
//All Questions
void all_q()
	{
	struct ques m;
	FILE *f;
	char ch;
	f=fopen(fname,"a+");
	resaq:
	while(fread(&m,sizeof(m),1,f)!=0)
	{
	cleardevice();
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	floodfill(2,2,7);
	setcolor(15);
	rectangle(40,40,600,440);
	setfillstyle(1,8);
	floodfill(44,44,15);
	settextstyle(3,0,5);
	outtextxy(200,44,"ALL QUESTIONS");
	settextstyle(2,0,5);
	outtextxy(150,150,"PRESS ANY KEY TO CHANGE.ENTER TO BACK ON MENU");
	outtextxy(60,200,"Q : ");
	outtextxy(100,200,m.q);

	if(m.r==1)
	  {
	  setcolor(GREEN);
	  }else setcolor(15);

	  outtextxy(60,250,"A : ");
	  outtextxy(100,250,m.a1);
	if(m.r==2)
	  {
	  setcolor(GREEN);
	  }else setcolor(15);

	  outtextxy(360,250,"B : ");
	  outtextxy(400,250,m.a2);
	if(m.r==3)
	  {
	  setcolor(GREEN);
	  }else setcolor(15);

	  outtextxy(60,300,"C : ");
	  outtextxy(100,300,m.a3);
	if(m.r==4)
	  {
	  setcolor(GREEN);
	  }else setcolor(15);

	  outtextxy(360,300,"C : ");
	  outtextxy(400,300,m.a4);

	 setcolor(15);
	ch=getch();
	if(ch=='\r')
		{
		fclose(f);
		goto endaq;
		}
	}
	rewind(f);
	goto resaq;
	endaq:
	}
//DELETE QUESTION
void del_q()
	{
	//cleardevice();
	char s[100],ch,qq[100];
	int c=0,count=0,nav=0,l=0,mt=0;
	struct ques m;
	FILE *f,*fd;
	f=fopen(fname,"a+");
	fd=fopen("tmp.bnk","w");
	while(fread(&m, sizeof(m),1,f)!=0)
		{
		for(int aa=0;aa<30;aa++)
			for(int a=0;a<30;a++)
			{
			if(m.q[a]==s[aa] && m.q[a-1]==s[aa-1] && m.q[a+1]==s[aa+1])
			   {
			   if(m.q[a]!='\0')
			   mt=1;
			   }
			 }
		if(mt==1)
		count++;
		mt=0;
		}
		rewind(f);
	for(int i=0;i<100;i++)
		{
		s[i]='\0';
		}
	cleardevice();
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	floodfill(2,2,7);
	setcolor(15);
	rectangle(40,40,600,440);
	setfillstyle(1,8);
	floodfill(44,44,15);
	outtextxy(200,44,"DELETE QUESTION");
	line(40,90,600,90);
	line(40,95,600,95);
	settextstyle(3,0,1);
	outtextxy(50,110,"TYPE TO SEARCH");
	outtextxy(100,400,"Press Tab to find more like (Unstable)::Enter to Proceed!!");
	//search bar
	setfillstyle(1,15);
	setcolor(0);
	bar(50,140,580,170);
	// bar end
	settextstyle(2,0,5);
	do{
	  s[c]='|';
	  setfillstyle(1,15);
	  bar(50,140,580,170);
	  outtextxy(54,144,s);
	  ch=getch();
	  //75 77
	  switch(ch)
		{
		case '\t':
		if(nav<count)
		   nav++;
		   else
		   nav=1;
		break;
		case '\r':

		break;
		case '\b':
		if(c>0)
		{
		s[c]='\0';
		c--;

		}
		break;
		default:
		s[c]=ch;
		c++;
		}
		setfillstyle(1,7);

		  l=1;
		  while(fread(&m, sizeof(m),1,f)!=0)
			{

			for(int aa=0;aa<30;aa++)
			for(int a=0;a<30;a++)
			{
			if(m.q[a]==s[aa] && m.q[a-1]==s[aa-1] && m.q[a+1]==s[aa+1])
			   {
			   if(m.q[a]!='\0')
			   mt=1;
			   }
			 }

			if(l!=nav && mt==1)
				{

				bar(50,200,580,400);
				settextstyle(2,0,7);
				outtextxy(51,300,"Q: ");
				outtextxy(70,300,m.q);
				settextstyle(2,0,5);

				strcpy(qq,m.q);
				l++;
				}
			mt=0;
			}
			rewind(f);

	  }while(ch!='\r');
	  rewind(f);
	  cleardevice();
	  setcolor(15);
	  outtextxy(200,200,"ARE YOU SURE YOU WANT TO DELETE?(PRESS Y)");
	  ch=' ';
	  ch=getch();
	  switch(ch)
	  {
	  case 'y':
	  case 'Y':
	  while(fread(&m, sizeof(m), 1,f))
		{
		if(strcmp(qq,m.q)!=0)
			{
			fwrite(&m,sizeof(m),1, fd);
			}
		}

		fclose(f);
		fclose(fd);
		remove(fname);
		rename("tmp.bnk",fname);

	  break;
	  }
	  fclose(f);
	  fclose(fd);
	  }





//search question
void sr_q()
	{
	char s[100],ch;
	int c=0,count=0,l=0,mt=0,cc=0;
	struct ques m;
	FILE *f;
	f=fopen(fname,"a+");
	for(int i=0;i<100;i++)
		{
		s[i]='\0';
		}
	cleardevice();
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	floodfill(2,2,7);
	setcolor(15);
	rectangle(40,40,600,440);
	setfillstyle(1,8);
	floodfill(44,44,15);
	outtextxy(200,44,"SEARCH QUESTION");
	line(40,90,600,90);
	line(40,95,600,95);
	settextstyle(3,0,1);
	outtextxy(50,110,"TYPE TO SEARCH");
	outtextxy(200,400,"Press Enter After Entering Keyword");
	//search bar
	setfillstyle(1,15);
	setcolor(0);
	bar(50,140,580,170);
	// bar end
	settextstyle(2,0,5);
	do{
	  s[c]='|';
	  setfillstyle(1,15);
	  bar(50,140,580,170);
	  outtextxy(54,144,s);
	  ch=getch();
	  switch(ch)
		{
		case '\b':
		if(c>0)
		{
		s[c]='\0';
		c--;
		}
		break;
		default:
		s[c]=ch;
		c++;
		}
		setfillstyle(1,7);




	  }while(ch!='\r');
	  ch=' ';
	  do{
	  setfillstyle(1,8);
	  bar(0,0,640,480);
	  settextstyle(2,0,8);
	  outtextxy(40,10+count,"SEARCH RESULTS (USE UP/DOWN ARROWS)");
	  switch(ch)
		{
		case 72:
		if(cc>11)
		count-=5;
		break;
		case 80://+
		if(cc>11)
		count+=5;
		break;
		}

			 //string
		 cc=1;
	  setfillstyle(1,15);

	  while(fread(&m,sizeof(m),1,f)!=0)
		{
			for(int aa=0;aa<30;aa++)
			for(int a=0;a<30;a++)
			{
			if(m.q[a]==s[aa] && m.q[a-1]==s[aa-1] && m.q[a+1]==s[aa+1])
			   {
			   if(m.q[a]!='\0')
			   mt=1;
			   }
			 }

		if(mt==1)
		{
		cc++;
		bar(10,40+l,630,80+l);
		settextstyle(3,0,2);

		outtextxy(10,40+l,m.q);
		setcolor(5);
		if(m.r==1)
		outtextxy(430,40+l,m.a1);
		if(m.r==2)
		outtextxy(430,40+l,m.a2);
		if(m.r==3)
		outtextxy(430,40+l,m.a3);
		if(m.r==4)
		outtextxy(430,40+l,m.a4);
		setcolor(0);
		l+=42;

		}
		mt=0;
		}

		rewind(f);

		l=count;
	  ch=getch();

	     }while(ch!='\r');

	fclose(f);
	}
//add ques
void add_scr()
	{
	struct ques m;
	for(int x=0;x<100;x++)
		{
		m.q[x]='\0';
		m.a1[x]='\0';
		m.a2[x]='\0';
		m.a3[x]='\0';
		m.a4[x]='\0';
		}
	char c,t[300];
	int ct[5]={0,0,0,0,0},in=1;
	cleardevice();
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	setcolor(15);
	rectangle(40,40,600,440);
	setfillstyle(1,8);
	floodfill(44,44,15);
	outtextxy(200,44,"ADD A QUESTION");
	line(40,90,600,90);
	line(40,95,600,95);
	settextstyle(3,0,1);
	outtextxy(50,110,"ENTER QUESTION");
	outtextxy(50,190,"ENTER OPTION A");
	outtextxy(50,250,"ENTER OPTION B");
	outtextxy(50,310,"ENTER OPTION C");
	outtextxy(50,370,"ENTER OPTION D");

	settextstyle(2,0,5);
	outtextxy(400,300,"TAB: SWITCH INPUT BOX");
	outtextxy(400,320,"ENTER: DONE!!!");
	hit_c:
	//input boxes
	setfillstyle(1,15);
	setcolor(0);
	bar(50,140,580,170);

	bar(50,220,380,250);
	bar(50,280,380,310);
	bar(50,340,380,370);
	bar(50,400,380,430);



	//input cursor
	if(in==1)
	m.q[ct[0]]='|';
	if(in==2)
	m.a1[ct[1]]='|';
	if(in==3)
	m.a2[ct[2]]='|';
	if(in==4)
	m.a3[ct[3]]='|';
	if(in==5)
	m.a4[ct[4]]='|';

	//inputed text visibility
	outtextxy(54,144,m.q);
	outtextxy(54,224,m.a1);
	outtextxy(54,284,m.a2);
	outtextxy(54,344,m.a3);
	outtextxy(54,404,m.a4);

	c=getch();
	//various keys while typing
	switch(c)
		{

		case '\r':
		if(in==1)
		m.q[ct[0]]=' ';
		if(in==2)
		m.a1[ct[1]]=' ';
		if(in==3)
		m.a2[ct[2]]=' ';
		if(in==4)
		m.a3[ct[3]]=' ';
		if(in==5)
		m.a4[ct[4]]=' ';
		setfillstyle(1,0);
		bar(40,40,600,440);
		setcolor(7);
		settextstyle(8,0,4);
		outtextxy(180,50,"ADD A QUESTION");
		setcolor(15);
		settextstyle(3,0,1);
		outtextxy(220,100,"Select Correct Answer");
		line(40,130,600,130);
		line(40,135,600,135);
		settextstyle(2,0,6);
		setcolor(15);

		outtextxy(80,180,"Q: ");
		outtextxy(100,180,m.q);

		outtextxy(80,250,"A):");
		outtextxy(102,250,m.a1);

		outtextxy(290,250,"B):");
		outtextxy(304,250,m.a2);

		outtextxy(80,300,"C):");
		outtextxy(102,300,m.a3);

		outtextxy(290,300,"D):");
		outtextxy(304,300,m.a4);

		outtextxy(230,400,"Select From Arrow Keys!!!");

		add_ra(1);

		m.r=1;c=' ';

		do
		{
		c=getch();
		switch(c)
			{
			case 72:
			if(m.r==1)
				m.r=3;
			else if(m.r==3)
				m.r=1;
			else if(m.r==4)
				m.r=2;
			else if(m.r==2)
				m.r=4;

			break;
			case 80:
			if(m.r==1)
				m.r=3;
			else if(m.r==3)
				m.r=1;
			else if(m.r==4)
				m.r=2;
			else if(m.r==2)
				m.r=4;
			break;
			case 75:
			if(m.r==1)
				m.r=2;
			else if(m.r==2)
				m.r=1;
			else if(m.r==4)
				m.r=3;
			else if(m.r==3)
				m.r=4;
			break;
			case 77:
			if(m.r==1)
				m.r=2;
			else if(m.r==2)
				m.r=1;
			else if(m.r==4)
				m.r=3;
			else if(m.r==3)
				m.r=4;
			break;
			}

		       add_ra(m.r);


		}while(c!='\r');

		FILE *fptr;
		fptr=fopen(fname,"a+");
		fwrite(&m, sizeof(m), 1, fptr);
		fclose(fptr);

		break;
		case '\t':

		if(in!=5)
			{
			in++;
			}else in=1;
		if(in!=1)
		m.q[ct[0]]=' ';
		if(in!=2)
		m.a1[ct[1]]=' ';
		if(in!=3)
		m.a2[ct[2]]=' ';
		if(in!=4)
		m.a3[ct[3]]=' ';
		if(in!=5)
		m.a4[ct[4]]=' ';
		goto hit_c;

		case '\b':
		if(ct[0]!=0 || ct[1]!=0 || ct[2]!=0 || ct[3]!=0 || ct[4]!=0)
		{
		if(in==1)
			{
			m.q[ct[0]]=' ';
			ct[0]--;
			}
		if(in==2)
			{
			m.a1[ct[1]]=' ';
			ct[1]--;
			}
		if(in==3)
			{
			m.a2[ct[2]]=' ';
			ct[2]--;
			}
		if(in==4)
			{
			m.a3[ct[3]]=' ';
			ct[3]--;
			}
		if(in==5)
			{
			m.a4[ct[4]]=' ';
			ct[4]--;
			}
		 }
		goto hit_c;

		default:
		if(in==1)
			{
			if(ct[0]<64)
				{
				m.q[ct[0]]=c;
				ct[0]++;
				}
			}
		if(in==2)
			{
			if(ct[1]<40)
				{
				m.a1[ct[1]]=c;
				ct[1]++;
				}
			}
		if(in==3)
			{
			if(ct[2]<40)
				{
				m.a2[ct[2]]=c;
				ct[2]++;
				}
			}
		if(in==4)
			{
			if(ct[3]<40)
				{
				m.a3[ct[3]]=c;
				ct[3]++;
				}
			}
		if(in==5)
			{
			if(ct[4]<40)
				{
				m.a4[ct[4]]=c;
				ct[4]++;
				}
			}

		goto hit_c;
		}


	}
//correct answer while adding
void add_ra(int s)
	{
	setcolor(0);
	rectangle(70,250,280,270);
	rectangle(280,250,480,270);
	rectangle(70,300,280,320);
	rectangle(280,300,480,320);
	setcolor(15);
	if(s==1)
	rectangle(70,250,280,270);
	if(s==2)
	rectangle(280,250,480,270);
	if(s==3)
	rectangle(70,300,280,320);
	if(s==4)
	rectangle(280,300,480,320);
	}
//select menu code
void selm(int s)
	{
	setlinestyle(2,0,1);
	setcolor(0);
	rectangle(180,160,480,200);
	rectangle(180,210,480,250);
	rectangle(180,260,480,300);
	rectangle(180,310,480,350);
	rectangle(180,360,480,400);
	rectangle(180,410,480,450);


	setcolor(15);
	switch(s)
		{
		case 1:
		rectangle(180,160,480,200);
		break;
		case 2:
		rectangle(180,210,480,250);
		break;
		case 3:
		rectangle(180,260,480,300);
		break;
		case 4:
		rectangle(180,310,480,350);
		break;
		case 5:
		rectangle(180,360,480,400);
		break;
		case 6:
		rectangle(180,410,480,450);
		break;
		}
	setlinestyle(0,0,1);

	}

//Loading screen of QUES BANK
void load_scr()
	{
	//first page look code
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	setcolor(7);
	line(20,190,620,190);
	line(20,200,620,200);
	setfillstyle(11,8);
	floodfill(25,25,7);
	setcolor(5);
	settextstyle(8,0,6);
	outtextxy(100,80,"QUESTION BANK");
	setfillstyle(12,1);
	setfillstyle(12,1);
	floodfill(21,201,7);
	setcolor(3);
	settextstyle(9,0,1);
	outtextxy(60,240,"Please Wait Until The Program Loads");
	setcolor(7);
	settextstyle(7,0,1);
	outtextxy(100,380,"SINDH MADARESSATUL ISLAM UNIVERSITY");
	//loading bar loop
	rectangle(93,313,557,347);
	rectangle(95,315,555,345);
	for(int x=1;x<=450;x++)
		{
		delay(5);
		setfillstyle(9,10);
		bar(100,320,x+100,340);
		}
	delay(1000);
	cleardevice();
	}

//Main screen of QUES BANK
void main_scr()
	{

	clearviewport();
	//first page look code
	setcolor(7);
	setfillstyle(8,3);
	rectangle(1,1,639,479);
	rectangle(20,20,620,460);
	floodfill(2,2,7);
	setfillstyle(1,0);
	floodfill(25,25,7);
	setcolor(5);
	settextstyle(8,0,6);
	outtextxy(100,80,"QUESTION BANK");
	setcolor(8);
	settextstyle(3,0,4);
	outtextxy(220,160,"ADD QUESTION");
	outtextxy(200,210,"Search QUESTION");
	outtextxy(200,260,"DELETE QUESTION");
	outtextxy(220,310,"ALL QUESTIONS");
	outtextxy(230,360,"TAKE A QUIZ");
	outtextxy(280,410,"EXIT");
	}
