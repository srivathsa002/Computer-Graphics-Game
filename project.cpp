#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>



char t[10];

typedef enum {PROJECT,PUZZLE,PLAY,EXIT} MenuChoices;
float mov,xc;
float angle=0;
float goldloc=35,lavloc=100,pinkloc=165,greenloc=230,boatloc=1,flashloc=457.5;
int boatcapacity=0,boatseat1=0,boatseat2=0,land1=4,land2=0,disp=5;
int value,time=17;
int flagp=0,flagr=0,flagc=0;
GLint i,j;
GLfloat x[100]={0.0},y[100]={0.0};

void *currentfont;

void man(float);
void MenuInit(void);
void display(void);


void delay()
{
	int in,jn;
	for(in=0;in<1000;in++)
		for(jn=0;jn<5000;jn++);
}




void setFont(void *font)
{
	currentfont=font;
}



void drawstring(float x,float y,float z,char *string)
{
	    char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{
		glColor3f(1.0,1.0,1.0);
		glutBitmapCharacter(currentfont,*c);
	}
}


void drawman()
{
	glColor3f(0.81,0.71,0.23);
	man(goldloc);

	glColor3f( 0.917647,0.678431,0.917647);
	man(lavloc);

	glColor3f(1.00,0.43,0.78);
	man(pinkloc);

	glColor3f(0.196078,0.8,0.6);
	man(greenloc);
}







void man(float xc)
{
float r,yc=260;


	for(r=0.05;r<=20;r=r+.05)
	{
		glBegin(GL_LINE_LOOP);
		for(angle=0; angle<=360; angle=angle+5)
		{
			float angle_radians = angle * (float)3.14159 /(float)180;
			float x = xc + r* (float)cos(angle_radians);
			float y = yc + r* (float)sin(angle_radians);
			glVertex2f(x,2*y);
		}
		glEnd();
	}
	for(r=0.05;r<=20;r=r+.05)
	{
		glBegin(GL_LINE_LOOP);
		for(angle=0; angle<=360; angle=angle+5)
		{
			float angle_radians = angle * (float)3.14159 /(float)180;
			float x1 = xc +	r* (float)cos(angle_radians);
			float y1 = 570 + r* (float)sin(angle_radians);
			glVertex2f(x1,y1);
		}
		glEnd();
	}
	glColor3f(0,0,0);
	for(r=0.1;r<=3;r=r+.1)
	{
		glBegin(GL_LINES);
		for(angle=0; angle<=360; angle=angle+5)
		{
			float angle_radians = angle * (float)3.14159 /(float)180;
			float x2 = xc-10+ r* (float)cos(angle_radians);
			float y2 = 575 + r* (float)sin(angle_radians);
			glVertex2f(x2,y2);
		}
	}
	glColor3f(0.0,0.0,0.0);
	for(r=0.1;r<=3;r=r+.1)
	{
		glBegin(GL_LINES);
		for(angle=0; angle<=360; angle=angle+5)
		{
			float angle_radians = angle * (float)3.14159 /(float)180;
			float x2 = xc+10+ r* (float)cos(angle_radians);
			float y2 = 575 + r* (float)sin(angle_radians);
			glVertex2f(x2,y2);
		}
	}
		glEnd();

		glColor3f(1.0,1.0,1.0);
		glLineWidth(4);

		//left hand
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc-10,550);
		glVertex2f(xc-30,520);
		glEnd();
		//right hand
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc+10,550);
		glVertex2f(xc+30,520);
		glEnd();

		//left leg
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc-10,485);
		glVertex2f(xc-10,435);
		glEnd();

		//right leg
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc+10,485);
		glVertex2f(xc+10,435);
		glEnd();

		//left toe
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc-20,435);
		glVertex2f(xc-10,435);
		glEnd();

		//right toe
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc+10,435);
		glVertex2f(xc+20,435);
		glEnd();


		//mouth
		glBegin(GL_LINE_LOOP);
		glVertex2f(xc-5,560);
		glVertex2f(xc+5,560);
		glEnd();

		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1.0,0,0);
		glVertex2f(xc-30,580);
		glColor3f(0.0,1.0,0);
		glVertex2f(xc,600);
		glColor3f(0.0,0,1.0);
		glVertex2f(xc+30,580);

		glEnd();
		glLineWidth(1);
}






void bridge(void)
{

	glColor3f(0.0,0.5,0.0);

glBegin(GL_QUADS);

	glColor3f(1.0,0.8,0.2);
	glVertex2f(400,435);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(1010,435);
	glColor3f(1.0,0.7,1.0);
	glVertex2f(1010,405);
	glColor3f(0.4,0.8,1.0);
	glVertex2f(400,405);
glEnd();


glBegin(GL_QUADS);

	glColor3f(0.5,0.0,0.0);
	glVertex2f(400,405);
	glColor3f(1.0,0.0,0.9);
	glVertex2f(1010,405);
	glColor3f(1.0,0.7,0.2);
	glVertex2f(1010,395);
	glColor3f(0.6,1.0,0.4);
	glVertex2f(400,395);
glEnd();



}

void lanwa()
{


	//land
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.5,0);
	glVertex2f(0,435);
	glColor3f(0.0,0.5,0);
	glVertex2f(400,435);
	glColor3f(0,1,0);
	glVertex2f(400,395);
	glColor3f(0,1,0);
	glVertex2f(0,275);

	glEnd();

	//land
	glColor3f(0,1,0);
	glBegin(GL_QUADS);
	glColor3f(0,.5,0);
	glVertex2f(1010,435);
	glColor3f(0,.5,0);
	glVertex2f(1405,435);
	glColor3f(0,1,0);
	glVertex2f(1450,275);
	glColor3f(0,1,0);
	glVertex2f(1010,395);


	glEnd();


	//water
	glBegin(GL_QUADS);
	glColor3f(0.0,0.03,0.9);
	glVertex2f(10,175);
	glColor3f(0.0,0.07,0.9);
	glVertex2f(1385,175);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(1385,12);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(10,12);
	glEnd();

	glPointSize(2.0);

}



void flashlamp(float xc)
{

	float r,yc=610;
	glLineWidth(4);


	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(xc,yc);
		glVertex2f(xc,yc-90);

	glEnd();



	glColor3f(1,1,0);
	for(r=0.002;r<=15;r=r+.002)
	{
		glBegin(GL_LINE_LOOP);
		for(angle=0; angle<=360; angle=angle+5)
		{
			float angle_radians = angle * (float)3.14159 /(float)180;
			float x1 = xc +	r* (float)cos(angle_radians);
			float y1 = 610 + r* (float)sin(angle_radians);
			glVertex2f(x1,y1);
		}
		glEnd();
	}


}






void myMouse(int button,int state,int x,int y)
{

      if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){MenuInit();}

}


void disply()
{

     if(disp==3)
	{

		flagr=1;
		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,0,0);
		drawstring(150,500.0,0.0,"RULE VOILATED");
		glColor3f(0,1,0);
		drawstring(150,345.0,0.0,"BETTER LUCK NEXT TIME :-(");
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(0,1,1);
		drawstring(50,750.0,0,"<PRESS <r|R> to RESTART>");
		glColor3f(0,1,1);
		drawstring(50,725.0,0,"<PRESS 'e|E' to EXIT or>");
		glColor3f(0,1,1);
		drawstring(50,700,0.0,"RIGHT CLICK FOR OPTIONS");



		glFlush();
	}

	else if(disp==4)
	{
		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,0,0);
		drawstring(150,500.0,0.0,"CONGRATS YOU WON :-) ");
		glColor3f(0,1,0);
		drawstring(150,345.0,0.0,"MISSION SUCCESSFUL :-)");

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,1,1);
		drawstring(50,750.0,0,"<PRESS <r|R> to RESTART>");
		glColor3f(1,1,1);
		drawstring(50,725.0,0,"<PRESS 'e|E' to EXIT or>");
		glColor3f(1,1,1);
		drawstring(50,700,0.0,"RIGHT CLICK FOR OPTIONS");



	    flagc=1;

		glFlush();

	}

	else if(disp==5)
	{

		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);
		lanwa();
		drawman();
		bridge();
		flashlamp(flashloc);

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,1,0);
		drawstring(500,655,0.0,"TIME LEFT  :");
		sprintf(t,"%d",time);
		glColor3f(1,1,0);
		drawstring(650.0,655.0,0.0,t);

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,0,0);
		drawstring(50,780,0.0,"<PRESS '1' to move GOLD MAN;   1   SEC>");
		glColor3f(1,0,0);
		drawstring(50,755,0.0,"<PRESS '2' to move LAVENDER MAN;   2   SEC>");
		glColor3f(1,0,0);
		drawstring(50,730,0.0,"<PRESS '3' to move PINK MAN;  5   SEC>");
		glColor3f(1,0,0);
		drawstring(50,705,0.0,"<PRESS '4' to move GREEN MAN;  10   SEC>");
		glColor3f(0,1,0);
		drawstring(700,780,0.0,"<PRESS 'm' to MOVE FROM LEFT TO RIGHT>");
		glColor3f(0,1,0);
		drawstring(700,755,0.0,"<PRESS 'M' to MOVE FROM RIGHT TO LEFT>");
		glColor3f(0,1,0);
		drawstring(700,730,0.0,"<PRESS 'e|E' to EXIT>");
		glColor3f(0,1,0);
		drawstring(700,705,0.0,"<PRESS 'r|R' to RESTART>");

		glFlush();
		MenuInit();

	}

}


void aboutthepuzzle()
{
		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,0,0);
		drawstring(100,500,0,"ABOUT THE GAME");
		glColor3f(0,1,0);
		drawstring(100,475,0,"We have to move all 4 persons to other side of the bridge in 17 SECONDS.");
		glColor3f(1,0,0);


		drawstring(100,400,0,"RULES FOR THE GAME:");
		glColor3f(0,1,0);
		drawstring(100,375,0,"1.Flashlight has to be moved back and forth.");
		glColor3f(0,1,0);
		drawstring(100,350,0,"2.At a time 2 persons can move from left to right or from right to left of bridge.");
		glColor3f(0,1,0);
		drawstring(100,325,0,"3.GOLD MAN can pass bridge in 1 sec, LAVENDER MAN can pass in 2 sec.");
		glColor3f(0,1,0);
		drawstring(100,300,0,"4.PINK MAN can pass in 5 sec, GREEN MAN can pass in 10 sec.");
		glColor3f(0,1,0);
		drawstring(100,275,0,"5.If two persons are moving, slowest person's pace will be considered.");

		glFlush();
}



void firstscreen()
{

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		setFont(GLUT_BITMAP_HELVETICA_18);
	 	drawstring(440,750,0.0,"MVSR ENGINEERING COLLEGE");
		glColor3f(1.0,1.0,0.0);
		setFont(GLUT_BITMAP_HELVETICA_18);
	 	drawstring(340,680,0.0,"Dept. OF COMPUTER SCIENCE AND ENGINEERING");

		glColor3f(0.0,1.0,0.0);
		setFont(GLUT_BITMAP_HELVETICA_18);
	 	drawstring(450,600,0.0,"17 SECONDS BRIDGE PUZZLE");
		glColor3f(0.0,1.0,0.0);
	 	drawstring(450,590,0.0,"__________________________");
		glColor3f(1.0,0.0,1.0);
		drawstring(450,500,0.0,"BY");
		glColor3f(1.0,0.0,1.0);
	 	drawstring(450,490,0.0,"___");
		glColor3f(1.0,0.0,0.0);
		drawstring(450,450,0.0,"MUTHYALA SAI SRIVATHSA");
		glColor3f(1.0,0.0,0.0);
		drawstring(750,450,0.0,"2451-16-733-013");

		glColor3f(1.0,0.0,1.0);
		drawstring(450,350,0.0,"PROJECT GUIDE:");
		glColor3f(1.0,0.0,1.0);
	 	drawstring(450,340,0.0,"_______________");
		glColor3f(0.0,0.0,1.0);
		drawstring(450,280,0.0,"Mr.T. SUJANAVAN");
		glColor3f(0.0,1.0,1.0);
		drawstring(450,250,0.0,"Asst. Prof,Dept. of CSE");
		

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1.0,1.0,0.0);
		drawstring(828,40,0.0,"CLICK RIGHT MOUSE BUTTON TO PROCEED");





		glColor3f(1,0,1);//outline
		glLineWidth(4);

		glBegin(GL_LINE_LOOP);
			glVertex2f(8,8);
			glVertex2f(1392,8);
			glVertex2f(1392,792);
			glVertex2f(8,792);
		glEnd();


		glFlush();






}

void playscreen()
{
		flagp=1;


		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);
		flashlamp(flashloc);
		lanwa();
		drawman();
		bridge();


		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,1,0);
		drawstring(500,655,0.0,"TIME LEFT  :");
		sprintf(t,"%d",time);
		glColor3f(1,1,0);
		drawstring(650.0,655.0,0.0,t);

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,0,0);
		drawstring(50,780,0.0,"<PRESS '1' to move GOLD MAN;   1   SEC>");
		glColor3f(1,0,0);
		drawstring(50,755,0.0,"<PRESS '2' to move LAVENDER MAN;   2   SEC>");
		glColor3f(1,0,0);
		drawstring(50,730,0.0,"<PRESS '3' to move PINK MAN;  5   SEC>");
		glColor3f(1,0,0);
		drawstring(50,705,0.0,"<PRESS '4' to move GREEN MAN;  10   SEC>");
		glColor3f(0,1,0);
		drawstring(700,780,0.0,"<PRESS 'a' to MOVE FROM LEFT TO RIGHT>");
		glColor3f(0,1,0);
		drawstring(700,755,0.0,"<PRESS 'd' to MOVE FROM RIGHT TO LEFT>");
		glColor3f(0,1,0);
		drawstring(700,730,0.0,"<PRESS 'e|E' to EXIT>");
		glColor3f(0,1,0);
		drawstring(700,705,0.0,"<PRESS 'r|R' to RESTART>");

		glFlush();


}






void mykeyboard(unsigned char key,int x,int y)
{

	 if(disp==5)
	{
		if(key=='r'|| key=='R')
		{
			goldloc=35;
			lavloc=100;
			pinkloc=165;
			greenloc=230;
			boatloc=1;
			boatcapacity=0;
			boatseat1=0;
			boatseat2=0;
			land1=4;
			land2=0;
			time=17;
			flashloc=457.5;
			disp=5;
			playscreen();
			mov=0;
		}
		else if(key=='e'||key=='E')
			exit(0);
		else if(key=='1')
		{
			if((boatloc==1) && (goldloc==35) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					goldloc=490;
					boatseat1=1;
				}
				else if(boatseat2==0)
				{
					goldloc=425;
					boatseat2=1;
				}
				boatcapacity++;
				land1--;
			}
			else if((boatloc==1) && (goldloc==425|| goldloc==490))
			{
				goldloc=35;
				boatcapacity--;
				if(boatseat1==1)
					boatseat1=0;
				else if(boatseat2==1)
					boatseat2=0;
				land1++;
			}
			else if((boatloc==2) && (goldloc==1170) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					goldloc=983.5;
					boatseat1=1;
				}
				else if(boatseat2==0)
				{
					goldloc=918.5;
					boatseat2=1;
				}
				boatcapacity++;
				land2--;
			}
			else if((boatloc==2) && (goldloc==918.5 || goldloc==983.5))
			{
				goldloc=1170;
				boatcapacity--;
				if(boatseat1==1)
					boatseat1=0;
				else if(boatseat2==1)
					boatseat2=0;
				land2++;
			}
		}
		else if(key=='2')
		{
			if((boatloc==1) && (lavloc==100) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					lavloc=490;
					boatseat1=2;
				}
				else if(boatseat2==0)
				{
					lavloc=425;
					boatseat2=2;
				}
				boatcapacity++;
				land1--;
			}
			else if((boatloc==1) && (lavloc==425 || lavloc==490))
			{
				lavloc=100;
				boatcapacity--;
				if(boatseat1==2)
					boatseat1=0;
				else if(boatseat2==2)
					boatseat2=0;
				land1++;
			}
			else if((boatloc==2) && (lavloc==1235) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					lavloc=983.5;
					boatseat1=2;
				}
				else if(boatseat2==0)
				{
					lavloc=918.5;
					boatseat2=2;
				}
				boatcapacity++;
				land2--;
			}
			else if((boatloc==2) && (lavloc==918.5) || lavloc==983.5)
			{
				lavloc=1235;
				boatcapacity--;
				if(boatseat1==2)
					boatseat1=0;
				else if(boatseat2==2)
					boatseat2=0;
				land2++;
			}
		}
		else if(key=='3')
		{
			if((boatloc==1) && (pinkloc==165) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					pinkloc=490;
					boatseat1=3;
				}
				else if(boatseat2==0)
				{
					pinkloc=425;
					boatseat2=3;
				}
				boatcapacity++;
				land1--;
			}
			else if((boatloc==1) && (pinkloc==425 || pinkloc==490))
			{
				pinkloc=165;
				boatcapacity--;
				if(boatseat1==3)
					boatseat1=0;
				else if(boatseat2==3)
					boatseat2=0;
				land1++;
			}
			else if((boatloc==2) && (pinkloc==1300) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					pinkloc=983.5;
					boatseat1=3;
				}
				else if(boatseat2==0)
				{
					pinkloc=918.5;
					boatseat2=3;
				}
				boatcapacity++;
				land2--;
			}
			else if((boatloc==2) && (pinkloc==918.5 || pinkloc==983.5))
			{
				pinkloc=1300;
				boatcapacity--;
				if(boatseat1==3)
					boatseat1=0;
				else if(boatseat2==3)
					boatseat2=0;
				land2++;
			}
		}

		else if(key=='4')
		{
			if((boatloc==1) && (greenloc==230) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					greenloc=490;
					boatseat1=4;
				}
				else if(boatseat2==0)
				{
					greenloc=425;
					boatseat2=4;
				}
				boatcapacity++;
				land1--;
			}
			else if((boatloc==1) && (greenloc==425 || greenloc==490))
			{
				greenloc=230;
				boatcapacity--;
				if(boatseat1==4)
					boatseat1=0;
				else if(boatseat2==4)
					boatseat2=0;
				land1++;
			}
			else if((boatloc==2) && (greenloc==1365) && (boatcapacity!=2))
			{
				if(boatseat1==0)
				{
					greenloc=983.5;
					boatseat1=4;
				}
				else if(boatseat2==0)
				{
					greenloc=918.5;
					boatseat2=4;
				}
				boatcapacity++;
				land2--;
			}
			else if((boatloc==2) && (greenloc==918.5 || greenloc==983.5))
			{
				greenloc=1365;
				boatcapacity--;
				if(boatseat1==4)
					boatseat1=0;
				else if(boatseat2==4)
					boatseat2=0;
				land2++;
			}
		}
		else if((key=='m') && ((boatseat1!=0)||( boatseat2!=0))&&(boatloc==1))
		{
			if(land1==3)
				goto move1;



move1:			float i=0,j=0,k=0,l=0,ci=0,fi=0;


				for(mov=0;mov<=63;mov=mov+1.5)
				{
					if(fi<mov)
					{
					flashloc=flashloc-fi+mov;
					fi++;
					}

					if((boatseat1==1 || boatseat2==1) && i<mov)
					{
						goldloc=goldloc-i+mov;
						i++;
					}
					if((boatseat1==2 || boatseat2==2) && j<mov)
					{
						lavloc=lavloc-j+mov;
						j++;
					}
					if((boatseat1==3 || boatseat2==3) && k<mov)
					{
						pinkloc=pinkloc-k+mov;
						k++;
					}
					if((boatseat1==4 || boatseat2==4) && k<mov)
					{
						greenloc=greenloc-l+mov;
						l++;
					}
					disply();
//					delay();
				}




/*move1:			float i=0,j=0,k=0,l=0,ci=0;
				if(boatseat1==1)
				{
					goldloc=983.5;
				}
				else if(boatseat2==1)
				{
					goldloc=918.5;
				}
				if(boatseat1==2)
				{
					lavloc=983.5;
				}
				else if(boatseat2==2)
				{
					lavloc=918.5;
				}
				if(boatseat1==3)
				{
					pinkloc=983.5;
				}
				else if(boatseat2==3)
				{
					pinkloc=918.5;
				}
				if(boatseat1==4)
				{
					greenloc=983.5;
				}
				else if(boatseat2==4)
				{
					greenloc=918.5;
				}
				flashloc=952;*/



				boatloc=2;
				mov=0;

				if((goldloc==983.5||goldloc==918.5)&&(lavloc==983.5||lavloc==918.5))
					time=time-2;
				else if((goldloc==983.5||goldloc==918.5)&&(pinkloc==983.5||pinkloc==918.5))
					time=time-5;
				else if((goldloc==983.5||goldloc==918.5)&&(greenloc==983.5||greenloc==918.5))
					time=time-10;
				else if((lavloc==983.5||lavloc==918.5)&&(pinkloc==983.5||pinkloc==918.5))
					time=time-5;
				else if((lavloc==983.5||lavloc==918.5)&&(greenloc==983.5||greenloc==918.5))
					time=time-10;
				else if((pinkloc==983.5||pinkloc==918.5)&&(greenloc==983.5||greenloc==918.5))
					time=time-10;
				else if(goldloc==983.5||goldloc==918.5)
					time=time-1;
				else if(lavloc==983.5||lavloc==918.5)
					time=time-2;
				else if(pinkloc==983.5||pinkloc==918.5)
					time=time-5;
				else if(greenloc==983.5||greenloc==918.5)
					time=time-10;


				if(time<0)
				{
						//delay();

						disp=3;

						goto skip;
				}


			}
			else if((key=='M') && ((boatseat1!=0) || (boatseat2!=0))&&(boatloc==2))
			{

				if(land1==3)
				goto move2;

move2:		float i=0,j=0,k=0,l=0,ci=0,fi=0;


				for(mov=0;mov<=63;mov=mov+1.5)
				{
					if(fi<mov)
					{
					flashloc=flashloc+fi-mov;
					fi++;
					}
					if((boatseat1==1 || boatseat2==1) && i<mov)
					{
						goldloc=goldloc+i-mov;
						i++;
					}
					if((boatseat1==2 || boatseat2==2) && j<mov)
					{
						lavloc=lavloc+j-mov;
						j++;
					}
					if((boatseat1==3 || boatseat2==3) && k<mov)
					{
						pinkloc=pinkloc+k-mov;
						k++;
					}
					if((boatseat1==4 || boatseat2==4) && l<mov)
					{
						greenloc=greenloc+l-mov;
						l++;
					}
					disply();
//					delay();
				}

/*move2:		float i=0,j=0,k=0,l=0,ci=0;

				if(boatseat1==1)
				{
					goldloc=490;
				}
				else if(boatseat2==1)
				{
					goldloc=425;
				}
				if(boatseat1==2)
				{
					lavloc=490;
				}
				else if(boatseat2==2)
				{
					lavloc=425;
				}
				if(boatseat1==3)
				{
					pinkloc=490;
				}
				else if(boatseat2==3)
				{
					pinkloc=425;
				}
				if(boatseat1==4)
				{
					greenloc=490;
				}
				else if(boatseat2==4)
				{
					greenloc=425;
				}
				flashloc=457.5;*/



				boatloc=1;
				mov=0;


				if((goldloc==425||goldloc==490)&&(lavloc==425||lavloc==490))
					time=time-2;
				else if((goldloc==425||goldloc==490)&&(pinkloc==425||pinkloc==490))
					time=time-5;
				else if((goldloc==425||goldloc==490)&&(greenloc==425||greenloc==490))
					time=time-10;
				else if((lavloc==425||lavloc==490)&&(pinkloc==425||pinkloc==490))
					time=time-5;
				else if((lavloc==425||lavloc==490)&&(greenloc==425||greenloc==490))
					time=time-10;
				else if((pinkloc==425||pinkloc==490)&&(greenloc==425||greenloc==490))
					time=time-10;
				else if(goldloc==425||goldloc==490)
					time=time-1;
				else if(lavloc==425||lavloc==490)
					time=time-2;
				else if(pinkloc==425||pinkloc==490)
					time=time-5;
				else if(greenloc==425||greenloc==490)
					time=time-10;


				if(time<0)
				{
					//	delay();
						disp=3;
						goto skip;
				}



			}

		if(land2==4)
		{

			delay();
			disp=4;

			if(key=='r'||key=='R')
			{
				goldloc=35;
				lavloc=100;
				pinkloc=165;
				greenloc=230;
				boatloc=1;
				boatcapacity=0;
				boatseat1=0;
				boatseat2=0;
				land1=4;
				land2=0;
				time=17;
				flashloc=457.5;
				disp=5;
				mov=0;
			}
			else if(key=='e'||key=='E')
				exit(0);
		}


	}

	else if(disp==3)
	{
		if(key=='r'||key=='R')
		{
				goldloc=35;
				lavloc=100;
				pinkloc=165;
				greenloc=230;
				boatloc=1;
				boatcapacity=0;
				boatseat1=0;
				boatseat2=0;
				land1=4;
				land2=0;
				time=17;
				flashloc=457.5;
				disp=5;
				mov=0;

		}


		else if(key=='e'||key=='E')
			exit(0);
	}
	else if(disp==4)
	{
		if(key=='r'||key=='R')
		{

				goldloc=35;
				lavloc=100;
				pinkloc=165;
				greenloc=230;
				boatloc=1;
				boatcapacity=0;
				boatseat1=0;
				boatseat2=0;
				land1=4;
				land2=0;
				time=17;
				flashloc=457.5;
				disp=5;
				mov=0;



		}
		else if(key=='e'||key=='E')
			exit(0);
		delay();
	}
skip :	disply();
}






void display()
{
				glClear(GL_COLOR_BUFFER_BIT);

				goldloc=35;
				lavloc=100;
				pinkloc=165;
				greenloc=230;
				boatloc=1;
				boatcapacity=0;
				boatseat1=0;
				boatseat2=0;
				land1=4;
				land2=0;
				time=17;
				flashloc=457.5;
				disp=5;
				mov=0;

				playscreen();
				delay();
				glFlush();
}



void display1()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
//	disp();
	aboutthepuzzle();
	delay();
	glFlush();

}



void display2()
{

			firstscreen();
			glFlush();
}







void handlemenu(int value)
{
  switch(value)
  {
  case PROJECT:display2();
	  break;
  case PUZZLE:display1();
	  break;
  case PLAY:display();
         break;
 // case RESTART:display2();
	 // break;

  case EXIT:exit(0);
		  break;
  }

}
void MenuInit(void)
{
  glutCreateMenu(handlemenu);
  glutAddMenuEntry("view first screen",PROJECT);
  glutAddMenuEntry("about the puzzle",PUZZLE);
  glutAddMenuEntry("play",PLAY);
  glutAddMenuEntry("Exit", EXIT);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

}



void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1400,0,800);
	glMatrixMode(GL_MODELVIEW);
	glColor3i(1.0,0.0,0.0);
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(1000,1000);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(-0.5,0.5);
	glutCreateWindow("17 Seconds Bridge Puzzle");
	glutMouseFunc(myMouse);
	glutKeyboardFunc(mykeyboard);
	glutDisplayFunc(firstscreen);
	MenuInit();
	init();
	glutMainLoop();
}
