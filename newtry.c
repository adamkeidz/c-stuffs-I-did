/*=============================================================================

              EDB 1063 Structured Programming and Interfacing

             Bachelor of Electrical and Electronic Engineering/Computer Engineering

                       Universiti Teknologi PETRONAS

-------------------------------------------------------------------------------

 JANUARY 2019            Project Assignment       Project Title: DICE

-------------------------------------------------------------------------------

 Author 1:  AHMAD ADAM BIN CHE ALANG IDIN ( 17003571 )

-------------------------------------------------------------------------------

  Levels Achieved:  1

-------------------------------------------------------------------------------

     File names:  newtry.c gfx.c gfx.h

=============================================================================*/
#include <stdio.h>
#include <ctype.h>//to use the check functions
#include <time.h>//to use the srand functions
#include <stdlib.h>
#include <stdbool.h>//boolean
#include "gfx.h"
#include <unistd.h>
#include <string.h>

void mainmenu();
void play();
void play2();
void stats();
int rollDice1();
int rollDice2();
int rollDice3();
int rollDice4(); 
void dice1L();
void dice1R();
void dice2L();
void dice2R();
void dice3L();
void dice3R();
void dice4L();
void dice4R();
void dice5L();
void dice5R();
void dice6L();
void dice6R();
void dice7L();
void dice7R();
void dice8L();
void dice8R();
void dice9L();
void dice9R();
void dice10L();
void dice10R();
void deco();

int main()
{
	int xsize = 800;
	int ysize = 600;
		
	gfx_open(xsize,ysize," Legal dice game :) ");
	
	mainmenu();
	
	return 0;	
}
void mainmenu()
{
	int x, y, num;
	int point1;
	int result1;
	int score_1;
	char c;		
	
	gfx_clear_color(110,0,190);
	gfx_clear();
	
	deco();
	
	gfx_color(0,0,0);
	
	gfx_fillrectangle(300,160,220,50);
	gfx_fillrectangle(300,230,220,50);
//fx_fillrectangle(300,300,220,50);

	gfx_color(255,255,255);

	gfx_rectangle(300,160,220,50);
	gfx_rectangle(300,230,220,50);
//fx_rectangle(300,300,220,50);

	gfx_text("Instructions for the game",325,190);
	gfx_text("Play the game",370,260);
	//x_text("Stats",390,330);

	
	while (1)
	{
		c = gfx_wait();		//wait for input
		
		if (c=0x01)			//input at the 1st screen
		{
			x = gfx_xpos();
			y = gfx_ypos();
			
			if ((x>=220 && x<=570) && (y>=160 && y<= 210))		//1stbutton 
			{
				gfx_clear();
				
				deco();
				
				gfx_color(0,0,0);
				gfx_fillrectangle(300,60,100,30);
				
				gfx_color(255,255,255);
				gfx_text(" How To Play ",310,80);

				gfx_color(255,255,255);
				gfx_fillrectangle(140,120,600,250);
				gfx_color(0,0,0);
				gfx_text("1. The player will go to Level 1 by clicking the button below",160,140);
				gfx_text("2. Player have to guess the dice value by clicking the number buttons",160,190);
				gfx_text("3. Roll the dice to know the real dice value ",160,240);
				
				gfx_fillrectangle(680,540,85,30);
				
				gfx_line(140,120,740,120);
	         gfx_line(140,120,140,370);
	         gfx_line(140,370,740,370);
	         gfx_line(740,120,740,370);
	
				gfx_color(255,255,255);
				gfx_text("Proceed",700,560);
				
	   		gfx_line(680,540,765,540);
	         gfx_line(680,540,680,570);
           	gfx_line(680,570,765,570);
	         gfx_line(765,540,765,570);
	         
	         gfx_line(300,60,400,60);
	         gfx_line(300,60,300,90);
         	gfx_line(300,90,400,90);
	         gfx_line(400,60,400,90);

				while (1)
				{
					c = gfx_wait();
					
					if (c=0x01)
					{
						x = gfx_xpos();
						y = gfx_ypos();
						
						
						if ((x>=680 && x<=765) && (y>=540 && y<=570))
						{
							gfx_clear();	
							deco();						
							play();
								}
						}
				}
				
			}else if((x>300 && x<520) && (y>230 && y<280)){
			   gfx_clear();
			   deco();
			   play();
			}
			
			}		
			
			else if ((x>350 && x<650) && (y>500 && y<570))		
			{
				gfx_clear();
				exit(1);
		
				gfx_color(0,0,0);
			}		
		}
}

void play(){ 
	int x, y;
	int num, num2,num3;
	int dice1 ;
	int dice2 ;
	int sum;
	int input1, input2, input3, input4, input5, input6;
	int counter1, counter2, counter3;
	int result =0;
	int point;
	char c;
		time_t t;
		
	gfx_color(255,255,255);				//colour of rectangles
	gfx_fillrectangle(365,75,70,40);
	gfx_fillrectangle(0,230,800,50);
							
	gfx_color(0,0,0);					//outline colour of rectangles
	gfx_rectangle(365,75,70,40);
	gfx_rectangle(0,230,800,50);
							
	gfx_text("LEVEL 1", 380,100);
	gfx_text("You have to guess the first dice value", 280,260);
		
	gfx_color(255,255,255);				//button 1	
	gfx_fillrectangle(75,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(75,350,50,50);
	gfx_color(0,0,0);
	gfx_text("1", 97,380);
				
	gfx_color(255,255,255);				//button 2			
	gfx_fillrectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_text("2", 197,380);
		
	gfx_color(255,255,255);				//button 3				
	gfx_fillrectangle(275,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(275,350,50,50);
	gfx_color(0,0,0);
	gfx_text("3", 297,380);
				
	gfx_color(255,255,255);				//button 4				
	gfx_fillrectangle(475,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(475,350,50,50);
	gfx_color(0,0,0);
	gfx_text("4", 497,380);
				
	gfx_color(255,255,255);				//button 5				
	gfx_fillrectangle(575,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(575,350,50,50);
	gfx_color(0,0,0);
	gfx_text("5", 597,380);
			
	gfx_color(255,255,255);				//button 6				
	gfx_fillrectangle(675,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(675,350,50,50);
	gfx_color(0,0,0);
	gfx_text("6", 697,380);

	while (1)
		{	
			
			c = gfx_wait();		//wait for input from user
					
			if (c=0x01)
			{
				x = gfx_xpos();
				y = gfx_ypos();
				
	
					
				if ((x>75 && x<125) && (y>350 && y<400))		// DICE 1 = 1 (level 1)
				{
					num = 1;
					gfx_clear();
					deco();
					gfx_color(255,255,255);				
					gfx_fillrectangle(0,150,800,50);
					gfx_color(0,0,0);
					gfx_text("Dice 1 : 1", 360,180);
					gfx_color(255,255,255);					
					gfx_fillrectangle(0,240,800,50);
					gfx_color(0,0,0);
					gfx_text("Pick the value of dice 2 ", 330,270);				
				}
				else if ((x>175 && x<225) && (y>350 && y<400))		// DICE 1 = 2 (level 1)
				{
					num = 2;
					gfx_clear();
					deco();
					gfx_color(255,255,255);				
					gfx_fillrectangle(0,150,800,50);
					gfx_color(0,0,0);
					gfx_text("Dice 1 : 2", 360,180);
					gfx_color(255,255,255);					
					gfx_fillrectangle(0,240,800,50);
					gfx_color(0,0,0);
					gfx_text("Pick the value of dice 2 ", 330,270);				
				}
				else if ((x>275 && x<325) && (y>350 && y<400))		// DICE 1 = 3 (level 1)
				{
					num = 3;
					gfx_clear();
					deco();
					gfx_color(255,255,255);				
					gfx_fillrectangle(0,150,800,50);
					gfx_color(0,0,0);
					gfx_text("Dice 1 : 3", 360,180);
					gfx_color(255,255,255);					
					gfx_fillrectangle(0,240,800,50);
					gfx_color(0,0,0);
					gfx_text("Pick the value of dice 2 ", 330,270);
				}
				else if ((x>475 && x<525) && (y>350 && y<400))		// DICE 1 = 4 (level 1)
				{
					num = 4;
					gfx_clear();
					deco();
					gfx_color(255,255,255);				
					gfx_fillrectangle(0,150,800,50);
					gfx_color(0,0,0);
					gfx_text("Dice 1 : 4", 360,180);
					gfx_color(255,255,255);					
					gfx_fillrectangle(0,240,800,50);
					gfx_color(0,0,0);
					gfx_text("Pick the value of dice 2 ", 330,270);
				}
				else if ((x>575 && x<625) && (y>350 && y<400))		//	DICE 1 = 5 (level 1)
				{
					num = 5; 
					gfx_clear();
					deco();
					gfx_color(255,255,255);				
					gfx_fillrectangle(0,150,800,50);
					gfx_color(0,0,0);
					gfx_text("Dice 1 : 5", 360,180);
					gfx_color(255,255,255);					
					gfx_fillrectangle(0,240,800,50);
					gfx_color(0,0,0);
					gfx_text("Pick the value of dice 2 ", 330,270);
				}
				else if ((x>675 && x<725) && (y>350 && y<400))		// DICE 1 = 6 (level 1)
				{
					num = 6;
					gfx_clear();
					deco();
					gfx_color(255,255,255);				
					gfx_fillrectangle(0,150,800,50);
					gfx_color(0,0,0);
					gfx_text("Dice 1 : 6", 360,180);
					gfx_color(255,255,255);					
					gfx_fillrectangle(0,240,800,50);
					gfx_color(0,0,0);
					gfx_text("Pick the value of dice 2 ", 330,270);						
				}
			}
        					
   gfx_color(255,255,255);				//button 1	
   gfx_fillrectangle(75,350,50,50);
   gfx_color(0,0,0);
	gfx_rectangle(75,350,50,50);
	gfx_color(0,0,0);
	gfx_text("1", 97,380);
				
	gfx_color(255,255,255);				//button 2			
	gfx_fillrectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_text("2", 197,380);
		
	gfx_color(255,255,255);				//button 3				
	gfx_fillrectangle(275,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(275,350,50,50);
	gfx_color(0,0,0);
	gfx_text("3", 297,380);
				
	gfx_color(255,255,255);				//button 4				
	gfx_fillrectangle(475,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(475,350,50,50);
	gfx_color(0,0,0);
	gfx_text("4", 497,380);
				
	gfx_color(255,255,255);				//button 5				
	gfx_fillrectangle(575,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(575,350,50,50);
	gfx_color(0,0,0);
	gfx_text("5", 597,380);
			
	gfx_color(255,255,255);				//button 6				
	gfx_fillrectangle(675,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(675,350,50,50);
	gfx_color(0,0,0);
	gfx_text("6", 697,380);

			while (1){
				c = gfx_wait();
										
				if (c=0x01)
				{						
					x = gfx_xpos();
					y = gfx_ypos();
							
					if ((x>75 && x<125) && (y>350 && y<400))		// DICE 2 = 1 (level 1)
					{
						num2 = 1;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 1", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);	

					}									
					else if ((x>175 && x<225) && (y>350 && y<400))	//DICE 2 = 2 (level 1)
					{
						num2 = 2;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 2", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}								
					else if ((x>275 && x<325) && (y>350 && y<400))		// DICE 2 = 3 (level 1)
					{	
						num2 = 3;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 3", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}									
					else if ((x>475 && x<525) && (y>350 && y<400))		// DICE 2 = 4 (level 1)
					{
						num2 = 4; 
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 4", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}								
					else if ((x>575 && x<625) && (y>350 && y<400))		// DICE 2 = 5 (level 1)
					{
						num2 = 5;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 5", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}							
					else if ((x>675 && x<725) && (y>350 && y<400))		// DICE 2 = 6 (level 1)
					{
						num2 = 6;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 6", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}
				}
				
            gfx_color(255,255,255);				//button 1	
            gfx_fillrectangle(75,350,50,50);
            gfx_color(0,0,0);
	        gfx_rectangle(75,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("1", 97,380);
				
	        gfx_color(255,255,255);				//button 2			
	        gfx_fillrectangle(175,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(175,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("2", 197,380);
		
	        gfx_color(255,255,255);				//button 3				
	        gfx_fillrectangle(275,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(275,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("3", 297,380);
				
	        gfx_color(255,255,255);				//button 4				
	        gfx_fillrectangle(475,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(475,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("4", 497,380);
				
	        gfx_color(255,255,255);				//button 5				
	        gfx_fillrectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("5", 597,380);
			
	        gfx_color(255,255,255);				//button 6				
	        gfx_fillrectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("6", 697,380);
	         
	        gfx_color(255,255,255);				//button 7				
	        gfx_fillrectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("7", 147,430);
	         
	        gfx_color(255,255,255);				//button 8				
	        gfx_fillrectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("8", 247,430);
	         
	        gfx_color(255,255,255);				//button 9				
	        gfx_fillrectangle(325,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(325,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("9", 347,430);
	         
	        gfx_color(255,255,255);				//button 10				
	        gfx_fillrectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("10", 547,430);
	         
	        gfx_color(255,255,255);				//button 11				
	        gfx_fillrectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("11", 647,430);
	         
	        gfx_color(255,255,255);				//button 12				
	        gfx_fillrectangle(725,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(725,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("12", 747,430);
	         
	        while (1){
			    c = gfx_wait();
										
				if (c=0x01)
				{						
					x = gfx_xpos();
					y = gfx_ypos();
							
					if ((x>75 && x<125) && (y>350 && y<400))		
					{
						num3 = 1;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 1", 360,180);

					}									
					else if ((x>175 && x<225) && (y>350 && y<400))	
					{
						num3 = 2;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 2", 360,180);
						
					}								
					else if ((x>275 && x<325) && (y>350 && y<400))		
					{	
						num3 = 3;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 3", 360,180);
						
					}									
					else if ((x>475 && x<525) && (y>350 && y<400))		
					{
						num3 = 4; 
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 4", 360,180);
						
					}								
					else if ((x>575 && x<625) && (y>350 && y<400))		
					{
						num3 = 5;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 5", 360,180);
						
					}							
					else if ((x>675 && x<725) && (y>350 && y<400))		
					{
						num3 = 6;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 6", 360,180);
						
					}
					else if ((x>125 && x<175) && (y>400 && y<450))		
					{
						num3 = 7;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 7", 360,180);
						
					}
					else if ((x>225 && x<275) && (y>400 && y<450))	
					{
						num3 = 8;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 8", 360,180);
						
					}
					else if ((x>325 && x<375) && (y>400 && y<450))		
					{
						num3 = 9;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 9", 360,180);
						
					}
					else if ((x>525 && x<575) && (y>400 && y<450))		
					{
						num3 = 10;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 10", 360,180);
						
					}
					else if ((x>625 && x<675) && (y>400 && y<450))		
					{
						num3 = 11;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 11", 360,180);
						
					}
					else if ((x>725 && x<775) && (y>400 && y<450))		
					{
						num3 = 12;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 12", 360,180);
						
					}
	            }
	        
	            
				gfx_color(255,255,255);					
				gfx_fillrectangle(275,250,250,40);
				gfx_color(0,0,0);
				gfx_text("LETS ROLL",340,275);
				
				gfx_color(255,255,255);					
				gfx_fillrectangle(275,300,250,40);
				gfx_color(0,0,0);
				gfx_text("LETS ALSO ROLL",340,325);

				while (1){	
					c = gfx_wait();
					
					if (c=0x01){						
						x = gfx_xpos();
						y = gfx_ypos();
					
						if ((x>275 && x<525) && (y>250 && y<290))		// dice 1 roll button (level 1)
						{
							srand(time(NULL));
							dice1 = rollDice1();
							
							if (dice1 == 1)
							{
								gfx_color(255,255,0);
								gfx_text("Dice 1 = 1",140,275);
								dice1L();
							}				
							else if (dice1 == 2)
							{
								gfx_color(255,255,0);
								gfx_text("Dice 1 = 2",140,275);
								dice2L();
							}			
							else if (dice1 == 3)
							{
								gfx_color(255,255,0);
								gfx_text("Dice 1 = 3",140,275);
								dice3L();
							}				
							else if (dice1 == 4)
							{
								gfx_color(255,255,0);
								gfx_text("Dice 1 = 4",140,275);
								dice4L();
							}				
							else if (dice1 == 5)
							{
								gfx_color(255,255,0);
								gfx_text("Dice 1 = 5",140,275);
								dice5L();
							}					
							else if (dice1 == 6)
							{
								gfx_color(255,255,0);
								gfx_text("Dice 1 = 6",140,275);
								dice6L();
							}
							
							FILE *fredice1lvl1;
							
							fredice1lvl1 = fopen("fredice1lvl1.txt","w");
							fprintf(fredice1lvl1,"%d\n", dice1);
							
							fclose(fredice1lvl1);
						}
					}

							if (c=0x01)
							{						
								x = gfx_xpos();
								y = gfx_ypos();
								
								if ((x>275 && x<525) && (y>300 && y<340))		//dice 2 roll button (level 1)
									{
										srand(time(NULL));
										dice2 = rollDice2();
										
										if (dice2 == 1)
										{
											gfx_color(255,255,0);
											gfx_text("Dice 2 = 1",660,275);
											dice1R();
										}					
										else if (dice2 == 2)
										{
											gfx_color(255,255,0);
											gfx_text("Dice 2 = 2",660,275);
											dice2R();
										}				
										else if (dice2 == 3)
										{
											gfx_color(255,255,0);
											gfx_text("Dice 2 = 3",660,275);
											dice3R();
										}					
										else if (dice2 == 4)
										{
											gfx_color(255,255,0);
											gfx_text("Dice 2 = 4",660,275);
											dice4R();
										}					
										else if (dice2 == 5)
										{
											gfx_color(255,255,0);
											gfx_text("Dice 2 = 5",660,275);
											dice5R();
										}					
										else if (dice2 == 6)
										{
											gfx_color(255,255,0);
											gfx_text("Dice 2 = 6",660,275);
											dice6R();
										}
										
										FILE *fredice2lvl1;
							
										fredice2lvl1 = fopen("fredice2lvl1.txt","w");
										fprintf(fredice2lvl1,"%d\n", dice2);
							
										fclose(fredice2lvl1);
									
								
								
							      	sum = dice1 + dice2;
								
							      	FILE *sumdice;
								
						      		sumdice = fopen("sumdice.txt","w");
							      	
						      		fprintf(sumdice,"%d\n", sum);
								
						      		fclose(sumdice);
								
                                    
										if (sum == 2)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 2",380,375);
										}
										else if (sum == 3)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 3",380,375);
										}
										else if (sum == 4)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 4",380,375);
										}
										else if (sum == 5)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 5",380,375);
										}
										else if (sum == 6)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 6",380,375);
										}
										else if (sum == 7)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 7",380,375);
										}
										else if (sum == 8)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 8",380,375);
										}
										else if (sum == 9)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 9",380,375);
										}
										else if (sum == 10)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 10",380,375);
										}
										else if (sum == 11)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 11",380,375);
										}
										else if (sum == 12)
										{
											gfx_color(255,255,0);
											gfx_text("Sum = 12",380,375);
										}


		                     if (dice1 == num){
		                        gfx_color(51,255,51);
		                        gfx_fillrectangle(100,470,100,40);
		                        gfx_color(0,0,0);
									   gfx_text("Correct",120,490);
									   result +=1;
									   gfx_color(255,0,0);
									   gfx_rectangle(101,471,100,40);
		                     }
		                     if(dice2 == num2){
		                        gfx_color(51,255,51);
		                        gfx_fillrectangle(665,470,100,40);
		                        gfx_color(0,0,0);
									   gfx_text("Correct",685,490);
									   result +=1;
									   gfx_color(255,0,0);
									   gfx_rectangle(666,471,100,40);
		                     }
		                     if(sum == num3){
		                        gfx_color(51,255,51);
		                        gfx_fillrectangle(360,405,100,40);
		                        gfx_color(0,0,0);
									   gfx_text("Correct",380,425);
									   result +=1;
									   gfx_color(255,0,0);
									   gfx_rectangle(361,406,100,40);
		                     }
		                     if(dice1 != num){
		                        gfx_color(255,0,0);
									   gfx_fillrectangle(100,470,100,40);
									   gfx_color(255,255,255);
									   gfx_text("Wrong",135,490);
									   gfx_color(51,255,51);
									   gfx_rectangle(101,471,100,40);
									   result += 0;
		                     }
		                     if(dice2 != num2){
		                        gfx_color(255,0,0);
									   gfx_fillrectangle(665,470,100,40);
									   gfx_color(255,255,255);
									   gfx_text("Wrong",700,490);
									   gfx_color(51,255,51);
									   gfx_rectangle(666,471,100,40);
									   result += 0;
		                     }
		                     if(sum != num3){
		                        gfx_color(255,0,0);
									   gfx_fillrectangle(360,405,100,40);
									   gfx_color(255,255,255);
									   gfx_text("Wrong",390,425);
									   gfx_color(51,255,51);
									   gfx_rectangle(361,406,100,40);
									   result += 0;
		                     }
								
								switch (result)
								{
									case 0:
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("No point for you!",365,475);
											gfx_text("0 point",390,515);
											gfx_text("Proceed",645,580);
											gfx_text("Exit",25,570);
											point = 0;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;
									case 1:	
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("Level 1 completed",365,475);
											gfx_text("1 point",390,515);
											gfx_text("Proceed",645,580);
											gfx_text("Exit",25,570);
											point = 1;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;	
									case 2:	
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("Level 1 completed",365,475);
											gfx_text("2 points",390,515);
											gfx_text("Proceed",645,580);
											gfx_text("Exit",25,570);
											point = 2;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;		
									case 3:	
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("Level 1 completed",365,475);
											gfx_text("3 points",390,515);
											gfx_text("Proceed",645,580);
											gfx_text("Exit",25,570);
											point = 3;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;	
							
									default:	
											break;	
								}
									FILE *score1;
									
									score1 = fopen("score1.txt", "w");
									
									fprintf(score1,"%d\n", point);
									
									
									fclose(score1);
                                
                                c = gfx_wait();
                               if (c=0x01){						
								       x = gfx_xpos();
							          y = gfx_ypos();
								
							          if ((x>630 && x<700) && (y>560 && y<590)){
							          gfx_clear();
			                      deco();
			                      play2();
							          }else if((x>15 && x<65) && (y>550 && y<580)){
							          exit(1);
							          }
									}	
									}	
                                    }																		
                   		       	}        		
                                          }		
                                          }
            }
 }    
void play2()
{
	int x, y;
	int num, num2,num3;
	int dice1 ;
	int dice2 ;
	int sum;
	int totDice1;
	int totDice2;
	int result;
	int score__1;
	int cumulativedice;
	int sum_score;
	int point2;
	char c;
		time_t t;	
		
	gfx_clear();
	deco();
	gfx_color(255,255,255);				//colour of rectangles
	gfx_fillrectangle(365,75,70,40);
	gfx_fillrectangle(0,230,800,50);
								
	gfx_color(0,0,0);					//outline colour of rectangles
	gfx_rectangle(365,75,70,40);
	gfx_rectangle(0,230,800,50);
						
	gfx_text("LEVEL 2", 380,100);
	gfx_text("You have to guess the value of dice", 280,260);
			
	gfx_color(255,255,255);				//button 1	
    gfx_fillrectangle(75,350,50,50);
    gfx_color(0,0,0);
	gfx_rectangle(75,350,50,50);
	gfx_color(0,0,0);
	gfx_text("1", 97,380);
				
	gfx_color(255,255,255);				//button 2			
	gfx_fillrectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_text("2", 197,380);
		
	        gfx_color(255,255,255);				//button 3				
	        gfx_fillrectangle(275,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(275,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("3", 297,380);
				
	        gfx_color(255,255,255);				//button 4				
	        gfx_fillrectangle(475,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(475,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("4", 497,380);
				
	        gfx_color(255,255,255);				//button 5				
	        gfx_fillrectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("5", 597,380);
			
	        gfx_color(255,255,255);				//button 6				
	        gfx_fillrectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("6", 697,380);
				
	        gfx_color(255,255,255);				//button 7				
	        gfx_fillrectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("7", 147,430);
	         
	        gfx_color(255,255,255);				//button 8				
	        gfx_fillrectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("8", 247,430);
				
	        gfx_color(255,255,255);				//button 9				
	        gfx_fillrectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("9", 547,430);
	         
	        gfx_color(255,255,255);				//button 10				
	        gfx_fillrectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("10", 647,430);
			
	while (1){
			    c = gfx_wait();
										
				if (c=0x01)
				{						
					x = gfx_xpos();
					y = gfx_ypos();
							
					if ((x>75 && x<125) && (y>350 && y<400))		
					{
						num = 1;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:1", 360,180);

					}									
					else if ((x>175 && x<225) && (y>350 && y<400))	
					{
						num = 2;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:2", 360,180);
						
					}								
					else if ((x>275 && x<325) && (y>350 && y<400))		
					{	
						num = 3;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:3", 360,180);
						
					}									
					else if ((x>475 && x<525) && (y>350 && y<400))		
					{
						num = 4; 
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:4", 360,180);
						
					}								
					else if ((x>575 && x<625) && (y>350 && y<400))		
					{
						num = 5;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:5", 360,180);
						
					}							
					else if ((x>675 && x<725) && (y>350 && y<400))		
					{
						num = 6;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:6", 360,180);
						
					}
					else if ((x>125 && x<175) && (y>400 && y<450))		
					{
						num = 7;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:7", 360,180);
						
					}
					else if ((x>225 && x<275) && (y>400 && y<450))	
					{
						num = 8;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:8", 360,180);
						
					}else if ((x>525 && x<575) && (y>400 && y<450))		
					{
						num = 9;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:9", 360,180);
						
					}
					else if ((x>625 && x<675) && (y>400 && y<450))		
					{
						num = 10;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 1:10", 360,180);
						
					}
                }
	
			
	gfx_color(255,255,255);				//button 1	
    gfx_fillrectangle(75,350,50,50);
    gfx_color(0,0,0);
	gfx_rectangle(75,350,50,50);
	gfx_color(0,0,0);
	gfx_text("1", 97,380);
				
	gfx_color(255,255,255);				//button 2			
	gfx_fillrectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(175,350,50,50);
	gfx_color(0,0,0);
	gfx_text("2", 197,380);
		
	gfx_color(255,255,255);				//button 3				
	gfx_fillrectangle(275,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(275,350,50,50);
	gfx_color(0,0,0);
	gfx_text("3", 297,380);
				
	gfx_color(255,255,255);				//button 4				
	gfx_fillrectangle(475,350,50,50);
	gfx_color(0,0,0);
	gfx_rectangle(475,350,50,50);
	gfx_color(0,0,0);
	gfx_text("4", 497,380);
				
    gfx_color(255,255,255);				//button 5				
	        gfx_fillrectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("5", 597,380);
			
	        gfx_color(255,255,255);				//button 6				
	        gfx_fillrectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("6", 697,380);
				
	        gfx_color(255,255,255);				//button 7				
	        gfx_fillrectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("7", 147,430);
	         
	        gfx_color(255,255,255);				//button 8				
	        gfx_fillrectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("8", 247,430);
				
	        gfx_color(255,255,255);				//button 9				
	        gfx_fillrectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("9", 547,430);
	         
	        gfx_color(255,255,255);				//button 10				
	        gfx_fillrectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("10", 647,430);
	
		while(1){
					c = gfx_wait();
		
					if (c=0x01){
					x = gfx_xpos();
					y = gfx_ypos();
					if ((x>75 && x<125) && (y>350 && y<400))		// DICE 2 = 1 (level 1)
					{
						num2 = 1;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 1", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);	

					}									
					else if ((x>175 && x<225) && (y>350 && y<400))	//DICE 2 = 2 (level 1)
					{
						num2 = 2;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 2", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}								
					else if ((x>275 && x<325) && (y>350 && y<400))		// DICE 2 = 3 (level 1)
					{	
						num2 = 3;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 3", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}									
					else if ((x>475 && x<525) && (y>350 && y<400))		// DICE 2 = 4 (level 1)
					{
						num2 = 4; 
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 4", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}								
					else if ((x>575 && x<625) && (y>350 && y<400))		// DICE 2 = 5 (level 1)
					{
						num2 = 5;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 5", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}							
					else if ((x>675 && x<725) && (y>350 && y<400))		// DICE 2 = 6 (level 1)
					{
						num2 = 6;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Dice 2 : 6", 360,180);
						gfx_color(255,255,255);					
					   gfx_fillrectangle(0,240,800,50);
					   gfx_color(0,0,0);
					   gfx_text("Make a guess for the sum ", 330,270);		
						
					}
                }
				
           gfx_color(255,255,255);				//button 1	
           gfx_fillrectangle(75,350,50,50);
           gfx_color(0,0,0);
	        gfx_rectangle(75,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("1", 97,380);
				
	        gfx_color(255,255,255);				//button 2			
	        gfx_fillrectangle(175,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(175,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("2", 197,380);
		
	        gfx_color(255,255,255);				//button 3				
	        gfx_fillrectangle(275,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(275,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("3", 297,380);
				
	        gfx_color(255,255,255);				//button 4				
	        gfx_fillrectangle(475,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(475,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("4", 497,380);
				
	        gfx_color(255,255,255);				//button 5				
	        gfx_fillrectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(575,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("5", 597,380);
			
	        gfx_color(255,255,255);				//button 6				
	        gfx_fillrectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(675,350,50,50);
	        gfx_color(0,0,0);
	        gfx_text("6", 697,380);
	         
	        gfx_color(255,255,255);				//button 7				
	        gfx_fillrectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(125,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("7", 147,430);
	         
	        gfx_color(255,255,255);				//button 8				
	        gfx_fillrectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(225,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("8", 247,430);
	         
	        gfx_color(255,255,255);				//button 9				
	        gfx_fillrectangle(325,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(325,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("9", 347,430);
	         
	        gfx_color(255,255,255);				//button 10				
	        gfx_fillrectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(525,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("10", 547,430);
	         
	        gfx_color(255,255,255);				//button 11				
	        gfx_fillrectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(625,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("11", 647,430);
	         
	        gfx_color(255,255,255);				//button 12				
	        gfx_fillrectangle(725,400,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(725,400,50,50);
	        gfx_color(0,0,0);
	        gfx_text("12", 747,430);
	        
	        gfx_color(255,255,255);				//button 13	
           gfx_fillrectangle(75,450,50,50);
           gfx_color(0,0,0);
	        gfx_rectangle(75,450,50,50);
	        gfx_text("13", 97,480);
				
	        gfx_color(255,255,255);				//button 14			
	        gfx_fillrectangle(175,450,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(175,450,50,50);
	        gfx_color(0,0,0);
	        gfx_text("14", 197,480);
		
	        gfx_color(255,255,255);				//button 15				
	        gfx_fillrectangle(275,450,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(275,450,50,50);
	        gfx_color(0,0,0);
	        gfx_text("15", 297,480);
				
	        gfx_color(255,255,255);				//button 16				
	        gfx_fillrectangle(475,450,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(475,450,50,50);
	        gfx_color(0,0,0);
	        gfx_text("16", 497,480);
				
	        gfx_color(255,255,255);				//button 17				
	        gfx_fillrectangle(575,450,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(575,450,50,50);
	        gfx_color(0,0,0);
	        gfx_text("17", 597,480);
			
	        gfx_color(255,255,255);				//button 18				
	        gfx_fillrectangle(675,450,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(675,450,50,50);
	        gfx_color(0,0,0);
	        gfx_text("18", 697,480);
	         
	        gfx_color(255,255,255);				//button 19				
	        gfx_fillrectangle(225,500,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(225,500,50,50);
	        gfx_color(0,0,0);
	        gfx_text("19", 247,530);
	         
	        gfx_color(255,255,255);				//button 20				
	        gfx_fillrectangle(625,500,50,50);
	        gfx_color(0,0,0);
	        gfx_rectangle(625,500,50,50);
	        gfx_color(0,0,0);
	        gfx_text("20", 647,530);
	         	
	         	while(1){
	         	c= gfx_wait();		
				if (c=0x01)
				{						
					x = gfx_xpos();
					y = gfx_ypos();
							
					if ((x>75 && x<125) && (y>350 && y<400))		
					{
						num3 = 1;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 1", 360,180);

					}									
					else if ((x>175 && x<225) && (y>350 && y<400))	
					{
						num3 = 2;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 2", 360,180);
						
					}								
					else if ((x>275 && x<325) && (y>350 && y<400))		
					{	
						num3 = 3;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 3", 360,180);
						
					}									
					else if ((x>475 && x<525) && (y>350 && y<400))		
					{
						num3 = 4; 
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 4", 360,180);
						
					}								
					else if ((x>575 && x<625) && (y>350 && y<400))		
					{
						num3 = 5;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 5", 360,180);
						
					}							
					else if ((x>675 && x<725) && (y>350 && y<400))		
					{
						num3 = 6;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 6", 360,180);
						
					}
					else if ((x>125 && x<175) && (y>400 && y<450))		
					{
						num3 = 7;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 7", 360,180);
						
					}
					else if ((x>225 && x<275) && (y>400 && y<450))	
					{
						num3 = 8;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 8", 360,180);
						
					}
					else if ((x>325 && x<375) && (y>400 && y<450))		
					{
						num3 = 9;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 9", 360,180);
						
					}
					else if ((x>525 && x<575) && (y>400 && y<450))		
					{
						num3 = 10;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 10", 360,180);
						
					}
					else if ((x>625 && x<675) && (y>400 && y<450))		
					{
						num3 = 11;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 11", 360,180);
						
					}
					else if ((x>725 && x<775) && (y>400 && y<450))		
					{
						num3 = 12;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 12", 360,180);
						
					}else if ((x>75 && x<125) && (y>450 && y<500))		
					{
						num3 = 13;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 13", 360,180);
						
					}else if ((x>725 && x<775) && (y>450 && y<500))	
					{
						num3 = 14;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 14", 360,180);
						
					}else if ((x>725 && x<775) && (y>450 && y<500))	
					{
						num3 = 15;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 15", 360,180);
						
					}else if ((x>725 && x<775) && (y>450 && y<500))		
					{
						num3 = 16;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 16", 360,180);
						
					}else if ((x>725 && x<775) && (y>450 && y<500))		
					{
						num3 = 17;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 17", 360,180);
						
					}else if ((x>725 && x<775) && (y>450 && y<500))		
					{
						num3 = 18;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 18", 360,180);
						
					}else if ((x>225 && x<275) && (y>500 && y<550))
					{
						num3 = 19;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 19", 360,180);
						
					}else if ((x>625 && x<675) && (y>500 && y<550))	
					{
						num3 = 20;
						gfx_clear();
						deco();
						gfx_color(255,255,255);				
						gfx_fillrectangle(0,150,800,50);
						gfx_color(0,0,0);
						gfx_text("Guess for sum was 20", 360,180);
						
					}
	            
	        }
	            
				gfx_color(255,255,255);					
				gfx_fillrectangle(275,250,250,40);
				gfx_color(0,0,0);
				gfx_text("LETS ROLL",340,275);
				
				gfx_color(255,255,255);					
				gfx_fillrectangle(275,300,250,40);
				gfx_color(0,0,0);
				gfx_text("LETS ALSO ROLL",340,325);
				
				while(1){
				   	if (c=0x01)
					{						
						x = gfx_xpos();
						y = gfx_ypos();
					
						if ((x>275 && x<525) && (y>250 && y<290))
						{
							srand(time(NULL));
							dice1 = rollDice3();
							
							if (dice1 == 1)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 1",140,275);
								dice1L();
							}				
							else if (dice1 == 2)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 2",140,275);
								dice2L();
							}			
							else if (dice1 == 3)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 3",140,275);
								dice3L();
							}				
							else if (dice1 == 4)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 4",140,275);
								dice4L();
							}				
							else if (dice1 == 5)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 5",140,275);
								dice5L();
							}					
							else if (dice1 == 6)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 6",140,275);
								dice6L();
							}
							else if (dice1 == 7)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 7",140,275);
								dice7L();
							}			
							else if (dice1 == 8)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 8",140,275);
								dice8L();
							}				
							else if (dice1 == 9)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 9",140,275);
								dice9L();
							}				
							else if (dice1 == 10)
							{
								gfx_color(0,0,0);
								gfx_text("Dice 1 = 10",140,275);
								dice10L();
							}	
						
						
						FILE *fredice1lvl2;
							
						fredice1lvl2 = fopen("fredice1lvl2.txt","w");
						fprintf(fredice1lvl2,"%d\n", dice1);
							
						fclose(fredice1lvl2);
					}
								if (c=0x01)
								{						
									x = gfx_xpos();
									y = gfx_ypos();
								
									if ((x>350 && x<650) && (y>300 && y<340))
									{
										srand(time(NULL));
										dice2 = rollDice4();
										
										if (dice2 == 1)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 1",660,275);
											dice1R();
										}					
										else if (dice2 == 2)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 2",660,275);
											dice2R();
										}				
										else if (dice2 == 3)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 3",660,275);
											dice3R();
										}					
										else if (dice2 == 4)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 4",660,275);
											dice4R();
										}					
										else if (dice2 == 5)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 5",660,275);
											dice5R();
										}					
										else if (dice2 == 6)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 6",660,275);
											dice6R();
										}
										else if (dice2 == 7)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 7",660,275);
											dice7R();
										}				
										else if (dice2 == 8)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 8",660,275);
											dice8R();
										}					
										else if (dice2 == 9)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 4",660,275);
											dice9R();
										}					
										else if (dice2 == 10)
										{
											gfx_color(0,0,0);
											gfx_text("Dice 2 = 10",660,275);
											dice10R();
										}					

									}
									
									FILE *fredice2lvl2;
							
									fredice2lvl2 = fopen("fredice2lvl2.txt","w");
									fprintf(fredice2lvl2,"%d\n", dice2);
							
									fclose(fredice2lvl2);		
								}
								
								sum = dice1 + dice2;
								
																						
										if (sum == 2)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 2",380,375);
										}
										else if (sum == 3)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 3",380,375);
										}
										else if (sum == 4)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 4",380,375);
										}
										else if (sum == 5)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 5",380,375);
										}
										else if (sum == 6)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 6",380,375);
										}
										else if (sum == 7)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 7",380,375);
										}
										else if (sum == 8)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 8",380,375);
										}
										else if (sum == 9)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 9",380,375);
										}
										else if (sum == 10)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 10",380,375);
										}
										else if (sum == 11)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 11",380,375);
										}
										else if (sum == 12)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 12",380,375);
										}
										else if (sum == 13)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 13",380,375);
										}
										else if (sum == 14)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 14",380,375);
										}
										else if (sum == 15)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 15",380,375);
										}
										else if (sum == 16)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 16",380,375);
										}
										else if (sum == 17)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 17",380,375);
										}
										else if (sum == 18)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 18",380,375);
										}
										else if (sum == 19)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 19",380,375);
										}
										else if (sum == 20)
										{
											gfx_color(0,0,0);
											gfx_text("Sum = 20",380,375);
										}
										
										
					
								if (dice1 == num){
		                        gfx_color(51,255,51);
		                        gfx_fillrectangle(100,470,100,40);
		                        gfx_color(0,0,0);
									   gfx_text("Correct",120,490);
									   result +=1;
									   gfx_color(255,0,0);
									   gfx_rectangle(101,471,100,40);
		                     }
		                     if(dice2 == num2){
		                        gfx_color(51,255,51);
		                        gfx_fillrectangle(665,470,100,40);
		                        gfx_color(0,0,0);
									   gfx_text("Correct",685,490);
									   result +=1;
									   gfx_color(255,0,0);
									   gfx_rectangle(666,471,100,40);
		                     }
		                     if(sum == num3){
		                        gfx_color(51,255,51);
		                        gfx_fillrectangle(360,405,100,40);
		                        gfx_color(0,0,0);
									   gfx_text("Correct",380,425);
									   result +=1;
									   gfx_color(255,0,0);
									   gfx_rectangle(361,406,100,40);
		                     }
		                     if(dice1 != num){
		                        gfx_color(255,0,0);
									   gfx_fillrectangle(100,470,100,40);
									   gfx_color(255,255,255);
									   gfx_text("Wrong",135,490);
									   gfx_color(51,255,51);
									   gfx_rectangle(101,471,100,40);
									   result += 0;
		                     }
		                     if(dice2 != num2){
		                        gfx_color(255,0,0);
									   gfx_fillrectangle(665,470,100,40);
									   gfx_color(255,255,255);
									   gfx_text("Wrong",700,490);
									   gfx_color(51,255,51);
									   gfx_rectangle(666,471,100,40);
									   result += 0;
		                     }
		                     if(sum != num3){
		                        gfx_color(255,0,0);
									   gfx_fillrectangle(360,405,100,40);
									   gfx_color(255,255,255);
									   gfx_text("Wrong",390,425);
									   gfx_color(51,255,51);
									   gfx_rectangle(361,406,100,40);
									   result += 0;
		                     }
								switch (result)
								{
									case 0:
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("No point for you!",365,475);
											gfx_text("0 point",390,515);
											gfx_text("Statistics",645,580);
											gfx_text("Exit",25,570);
											point2 = 0;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;
									case 1:	
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("Level 2 completed",365,475);
											gfx_text("1 point",390,515);
											gfx_text("Statistics",645,580);
											gfx_text("Exit",25,570);
											point2 = 1;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;
									case 2:	
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("Level 2 completed",365,475);
											gfx_text("2 point",390,515);
											gfx_text("Statistics",645,580);
											gfx_text("Exit",25,570);
											point2 = 1;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;
									case 3:	
											gfx_color(255,255,255);
											gfx_fillrectangle(355,460,120,25);
											gfx_fillrectangle(360,500,110,25);
											gfx_fillrectangle(630,560,70,30);
											gfx_fillrectangle(15,550,50,30);
											gfx_color(0,0,255);
											gfx_text("Level 2 completed",365,475);
											gfx_text("3 points",390,515);
											gfx_text("Statistics",645,580);
											gfx_text("Exit",65,730);
											point2 = 3;
											gfx_color(255,105,180);
											gfx_rectangle(355,460,120,25);
											gfx_rectangle(360,500,110,25);
											gfx_rectangle(630,560,70,30);
											gfx_rectangle(15,550,50,30);
											break;	
							
									default:	
											break;	
								}
									
									FILE *sumdice;
								
									sumdice = fopen("sumdice.txt","r");
									fscanf(sumdice, "%d\n", &totDice1);
								
									fclose(sumdice);

								
									cumulativedice = totDice1 + sum;
								
											
									FILE *cumudice;
								
									cumudice = fopen("cumudice.txt","w");
									fprintf(cumudice,"%d\n", cumulativedice);
								
									fclose(cumudice);
									
									FILE *score1;
								
									score1 = fopen("score1.txt","r");
									fscanf(score1,"%d\n", &score__1);
								
									fclose(score1);
								
									sum_score = score__1 + result;
								
									FILE *sumscore;
								
									sumscore = fopen("sumscore.txt","w");
									fprintf(sumscore,"%d\n",sum_score);
								
								fclose(sumscore);
									
									
									
									while (1)
										{	
									c = gfx_wait();
					
									if (c=0x01)
								{
									x = gfx_xpos();
								y = gfx_ypos();
						
							if ((x>630 && x<700) && (y>560 && y<590))
						{
									stats();
							}
						}	} 	}
							}				}
}
}	}

void stats()
{
	int x, y ;
	int score;
	int cumulativedice;
	int fqdice1lvl1, fqdice2lvl1;
	int fqdice1lvl2, fqdice2lvl2;
	char c;
	char scorestr[10] = " ";
	char cumulativedicestr[10] = " ";
	char dice1str[10] = " ";	
	char dice2str[10] = " ";	
	char dice3str[10] = " ";	
	char dice4str[10] = " ";	
	char dice5str[10] = " ";	
	char dice6str[10] = " ";	
	char dice7str[10] = " ";	
	char dice8str[10] = " ";
	char dice9str[10] = " ";	
	char dice10str[10] = " ";
	int statdice1=0;
 	int statdice2=0;
 	int statdice3=0;
 	int statdice4=0;
 	int statdice5=0;
 	int statdice6=0;
 	int statdice7=0;
	int statdice8=0;
 	int statdice9=0;
 	int statdice10=0;	

	
	gfx_clear();
	
	gfx_color(255,255,255);
	gfx_fillrectangle(360,10,280,50);
	gfx_color(0,0,0);
	gfx_text("--> Result <--",220,25);

	gfx_color(255,255,255);
	gfx_fillrectangle(100,50,00,600);
	gfx_color(60,250,250);
	gfx_color(0,0,0);
	gfx_text("Total points",215,100);
	gfx_text("Cumulative Dice Value",215,150);
	
	gfx_color(255,255,255);			// layout button exit
	gfx_fillrectangle(50,630,70,40);
	gfx_color(0,0,0);
	gfx_text("Exit",65,650);
	
	strncpy(scorestr," ",10);
	
	FILE *sumscore;
									
	sumscore = fopen("sumscore.txt","r");
	fscanf(sumscore,"%d\n", &score);
	gfx_flush;
	fflush(stdin);
									
	fclose(sumscore);
	sprintf(scorestr,"%d\n",score);
	
	gfx_text(scorestr,480,100);	
	
	FILE *cumudice;
									
	cumudice = fopen("cumudice.txt","r");
	fscanf(cumudice,"%d\n", &cumulativedice);
	gfx_flush;
	fflush(stdin);
										
	fclose(cumudice);
	sprintf(cumulativedicestr,"%d\n",cumulativedice);
	
	gfx_text(cumulativedicestr,680,150);
	
	
	
	FILE *fredice1lvl1;
	
	fredice1lvl1 = fopen("fredice1lvl1.txt","r");
	fscanf(fredice1lvl1,"%d", &fqdice1lvl1);
	gfx_flush;
	fflush(stdin);
	
	fclose(fredice1lvl1);
	
	switch (fqdice1lvl1)
					{
						
					case 1:	
							statdice1++;				
											
							break;	
						
					case 2:	
							statdice2++;				
											
							break;
						
					case 3:
							statdice3++;
							
							break;
						
					case 4:
							statdice4++; 
							
							break;
						
					case 5:
							statdice5++;
					
							break;
						
					case 6:	
							statdice6++;
					
							break;	
							
					default:	
											
							break;
					
					}
	
	FILE *fredice2lvl1;
	
	fredice2lvl1 = fopen("fredice2lvl1.txt","r");
	fscanf(fredice2lvl1,"%d", &fqdice2lvl1);
	gfx_flush;
	fflush(stdin);
	
	fclose(fredice2lvl1);
	
	switch (fqdice2lvl1)
					{
						
					case 1:	
							statdice1++;				
											
							break;	
						
					case 2:	
							statdice2++;				
											
							break;
						
					case 3:
							statdice3++;
							
							break;
						
					case 4:
							statdice4++; 
							
							break;
						
					case 5:
							statdice5++;
					
							break;
						
					case 6:	
							statdice6++;
					
							break;	
							
					default:	
											
							break;
					
					}
	
	FILE *fredice1lvl2;
	
	fredice1lvl2 = fopen("fredice1lvl2.txt","r");
	fscanf(fredice1lvl2,"%d", &fqdice1lvl2);
	gfx_flush;
	fflush(stdin);
	
	fclose(fredice1lvl2);
	
	switch (fqdice1lvl2)
					{
						
					case 1:	
							statdice1++;				
											
							break;	
						
					case 2:	
							statdice2++;				
											
							break;
						
					case 3:
							statdice3++;
							
							break;
						
					case 4:
							statdice4++; 
							
							break;
						
					case 5:
							statdice5++;
					
							break;
						
					case 6:	
							statdice6++;
					
							break;
							
					case 7:
							statdice7++;
							
							break;
						
					case 8:
							statdice8++; 
							
							break;
						
					case 9:
							statdice9++;
					
							break;
						
					case 10:	
							statdice10++;
					
							break;	
							
					default:	
											
							break;
					
					}
	
	FILE *fredice2lvl2;
	
	fredice2lvl2 = fopen("fredice2lvl2.txt","r");
	fscanf(fredice2lvl2,"%d", &fqdice2lvl2);
	gfx_flush;
	fflush(stdin);
	
	fclose(fredice2lvl2);
	
	switch (fqdice2lvl2)
					{
						
					case 1:	
							statdice1++;				
											
							break;	
						
					case 2:	
							statdice2++;				
											
							break;
						
					case 3:
							statdice3++;
							
							break;
						
					case 4:
							statdice4++; 
							
							break;
						
					case 5:
							statdice5++;
					
							break;
						
					case 6:	
							statdice6++;
					
							break;
							
					case 7:
							statdice7++;
							
							break;
						
					case 8:
							statdice8++; 
							
							break;
						
					case 9:
							statdice9++;
					
							break;
						
					case 10:	
							statdice10++;
					
							break;	
							
					default:	
											
							break;
					
					}
	
	sprintf(dice1str,"%d\n",statdice1);
	sprintf(dice2str,"%d\n",statdice2);
	sprintf(dice3str,"%d\n",statdice3);
	sprintf(dice4str,"%d\n",statdice4);
	sprintf(dice5str,"%d\n",statdice5);
	sprintf(dice6str,"%d\n",statdice6);
	sprintf(dice7str,"%d\n",statdice7);
	sprintf(dice8str,"%d\n",statdice8);
	sprintf(dice9str,"%d\n",statdice9);
	sprintf(dice10str,"%d\n",statdice10);
	
	
	
	gfx_text("Frequency rolled dice:",145,130);
	gfx_text("Number 1 : ",280,175);
	gfx_text("Number 2 : ",280,200);		
	gfx_text("Number 3 : ",280,225);	
	gfx_text("Number 4 : ",280,250);	
	gfx_text("Number 5 : ",280,275);	
	gfx_text("Number 6 : ",280,300);
	gfx_text("Number 7 : ",280,325);	
	gfx_text("Number 8 : ",280,350);	
	gfx_text("Number 9 : ",280,375);	
	gfx_text("Number 10: ",280,400);
	
	gfx_text(dice1str,480,175);
	gfx_text(dice2str,480,200);	
	gfx_text(dice3str,480,225);	
	gfx_text(dice4str,480,250);	
	gfx_text(dice5str,480,275);	
	gfx_text(dice6str,480,300);	
	gfx_text(dice7str,480,325);	
	gfx_text(dice8str,480,350);	
	gfx_text(dice9str,480,375);			
	gfx_text(dice10str,480,400);	
	
		
	while (1)
		{
			c = gfx_wait();		//wait for input from user
			
			if (c=0x01)			//input selepas result
			{
				x = gfx_xpos();
				y = gfx_ypos();
												
				if((x>50 && x<120) && (y>500 && y<570))	//tekan Menu button
				{
					mainmenu();	
				}
			}			
		}
}



int rollDice1()  
{
   //sleep(5);
   return ((rand() % 6) + 1);	
}

int rollDice2() 
{
   //sleep(5);
   return ((rand() % 6) + 1);
}

int rollDice3()  
{
   //sleep(5);
   return ((rand() % 10) + 1);	
}

int rollDice4() 
{
   //sleep(5);
   return ((rand() % 10) + 1);
}

void dice1L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(150,400,15);
}

void dice1R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(710,400,15);
}

void dice2L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(135,400,15);
	gfx_fillcircle(165,400,15);
}

void dice2R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(695,400,15);
	gfx_fillcircle(725,400,15);
}

void dice3L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,400,15);
	gfx_fillcircle(150,400,15);
	gfx_fillcircle(175,400,15);
}

void dice3R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,400,15);
	gfx_fillcircle(710,400,15);
	gfx_fillcircle(735,400,15);
}

void dice4L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,375,15);
	gfx_fillcircle(175,375,15);
	gfx_fillcircle(175,425,15);
	gfx_fillcircle(125,425,15);
}

void dice4R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,375,15);
	gfx_fillcircle(735,375,15);
	gfx_fillcircle(735,425,15);
	gfx_fillcircle(685,425,15);
}

void dice5L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,375,15);
	gfx_fillcircle(175,375,15);
	gfx_fillcircle(175,425,15);
	gfx_fillcircle(125,425,15);
	gfx_fillcircle(150,400,15);
}

void dice5R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,375,15);
	gfx_fillcircle(735,375,15);
	gfx_fillcircle(735,425,15);
	gfx_fillcircle(685,425,15);
	gfx_fillcircle(710,400,15);
}

void dice6L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,380,15);
	gfx_fillcircle(150,380,15);
	gfx_fillcircle(175,380,15);
	gfx_fillcircle(125,420,15);
	gfx_fillcircle(150,420,15);
	gfx_fillcircle(175,420,15);
}

void dice6R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,380,15);
	gfx_fillcircle(710,380,15);
	gfx_fillcircle(735,380,15);
	gfx_fillcircle(685,420,15);
	gfx_fillcircle(710,420,15);
	gfx_fillcircle(735,420,15);
}

void dice7L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,385,15);
	gfx_fillcircle(150,370,15);
	gfx_fillcircle(175,385,15);
	gfx_fillcircle(125,415,15);
	gfx_fillcircle(150,430,15);
	gfx_fillcircle(175,415,15);
	gfx_fillcircle(150,400,15);
}

void dice7R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,385,15);
	gfx_fillcircle(710,370,15);
	gfx_fillcircle(735,385,15);
	gfx_fillcircle(685,415,15);
	gfx_fillcircle(710,430,15);
	gfx_fillcircle(735,415,15);
	gfx_fillcircle(710,400,15);
}

void dice8L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,375,15);
	gfx_fillcircle(150,375,15);
	gfx_fillcircle(175,375,15);
	gfx_fillcircle(125,425,15);
	gfx_fillcircle(150,425,15);
	gfx_fillcircle(175,425,15);
	gfx_fillcircle(137.5,400,15);
	gfx_fillcircle(162.5,400,15);
}

void dice8R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,375,15);
	gfx_fillcircle(710,375,15);
	gfx_fillcircle(735,375,15);
	gfx_fillcircle(685,425,15);
	gfx_fillcircle(710,425,15);
	gfx_fillcircle(735,425,15);
	gfx_fillcircle(697.5,400,15);
	gfx_fillcircle(722.5,400,15);
}

void dice9L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,375,15);
	gfx_fillcircle(150,375,15);
	gfx_fillcircle(175,375,15);
	gfx_fillcircle(125,425,15);
	gfx_fillcircle(150,425,15);
	gfx_fillcircle(175,425,15);
	gfx_fillcircle(125,400,15);
	gfx_fillcircle(150,400,15);
	gfx_fillcircle(175,400,15);
}

void dice9R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,375,15);
	gfx_fillcircle(710,375,15);
	gfx_fillcircle(735,375,15);
	gfx_fillcircle(685,425,15);
	gfx_fillcircle(710,425,15);
	gfx_fillcircle(735,425,15);
	gfx_fillcircle(685,400,15);
	gfx_fillcircle(710,400,15);
	gfx_fillcircle(735,400,15);
}

void dice10L()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(100,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(100,350,100,100);
	gfx_fillcircle(125,375,15);
	gfx_fillcircle(150,375,15);
	gfx_fillcircle(175,375,15);
	gfx_fillcircle(125,425,15);
	gfx_fillcircle(150,425,15);
	gfx_fillcircle(175,425,15);
	gfx_fillcircle(115,400,15);
	gfx_fillcircle(137.5,400,15);
	gfx_fillcircle(163.5,400,15);
	gfx_fillcircle(185,400,15);
}

void dice10R()
{
	gfx_color(255,255,255);
	gfx_fillrectangle(660,350,100,100);
	gfx_color(0,0,0);
	gfx_rectangle(660,350,100,100);
	gfx_fillcircle(685,375,15);
	gfx_fillcircle(710,375,15);
	gfx_fillcircle(735,375,15);
	gfx_fillcircle(685,425,15);
	gfx_fillcircle(710,425,15);
	gfx_fillcircle(735,425,15);
	gfx_fillcircle(675,400,15);
	gfx_fillcircle(697.5,400,15);
	gfx_fillcircle(723.5,400,15);
	gfx_fillcircle(745,400,15);
}

void deco(){
   gfx_color(130,0,200);
	
	gfx_fillcircle(130,350,250);
	         gfx_fillcircle(400,275,350);
	         gfx_fillcircle(670,350,250);
	         gfx_fillrectangle(0,350,800,400);
	
	         gfx_color(225,155,150);
	
	         gfx_fillrectangle(0,0,800,20);
	
	         gfx_color(0,0,0);
	
         	gfx_text("Dicer",390,15);
}
