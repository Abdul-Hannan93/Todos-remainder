#include "iGraphics.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

int x = 300, y = 300, r = 20;
int settings_mode = 0;
int mood = 0;
int dark_mood_on = 1;
int ringtone_mood = 0;
int uefa = 0, nokia = 0, random = 0, show_reminder = 0;
int musicOn = 1;
int hour, minute, day, month, year;
char str[1000] = {0};
char str1[1000] = {0};
int hours, minutes, days, months, years;
int music_on=0;

void diff_hr_min()
{

	char *token = strtok(str, "&/");
	token = strtok(NULL, "&/");
	day = atoi(token);
	token = strtok(NULL, "&/");
	month = atoi(token);
	token = strtok(NULL, "&/");
	year = atoi(token);
	token = strtok(NULL, "&:");
	hour = atoi(token);
	token = strtok(NULL, "&:");
	minute = atoi(token);
}
void add_task(void)
{
	FILE *fp;

	char filename[] = "My name is khan.txt";
	fp = fopen(filename, "a");
	fprintf(fp, str);
	fprintf(fp, "\n");
	fclose(fp);
}
void musicfunc(){
	if(uefa==1&&music_on==1){
		PlaySound("Sounds_begin.wav", NULL, SND_ASYNC);
	}
	

}
/*
	function iDraw() is called again and again by the system.

	*/
void iDraw()
{    
	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0&&show_reminder==0)
	{
		// iSetColor(255,255,255);
		iClear();
		if (dark_mood_on == 1)
		{
			iSetColor(0, 0, 0);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(255, 255, 255);
		}

		iFilledRectangle(0, 0, 700, 400);
		// iFilledCircle(x, y, r);
		iSetColor(20, 200, 0);
		iRectangle(50, 340, 600, 40);
		iSetColor(20, 200, 0);
		iText(160, 360, "Enter the time and date of your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		iSetColor(20, 200, 0);
		iText(230, 310, "Your activity you have to do", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iSetColor(20, 200, 0);
		iText(160, 260, "History about the activity of last month", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);
		iSetColor(20, 200, 0);
		iText(320, 210, "Settings", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (show_reminder == 1&& mood==0&&ringtone_mood==0&&settings_mode==0)
	{
		iClear();
		if (dark_mood_on == 1)
		{
			iSetColor(0, 0, 0);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(255, 255, 255);
		}

		iFilledRectangle(0, 0, 700, 400);
		iSetColor(20, 200, 0);
		iRectangle(50, 340, 600, 40);
		iSetColor(20, 200, 0);
		iText(160, 360, "add text", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		iSetColor(20, 200, 0);
		iText(200, 310, "reminder", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(230, 260, "nothing", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);
		iSetColor(20, 200, 0);
		iText(320, 210, "ready", GLUT_BITMAP_TIMES_ROMAN_24);
		// if(uefa==1) music_func();
	}
	
	if (settings_mode == 1 && mood == 0 && ringtone_mood == 0 &&show_reminder==0)
	{

		// iSetColor(255,255,255);
		iClear();
		if (dark_mood_on == 1)
		{
			iSetColor(0, 0, 0);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(255, 255, 255);
		}

		iFilledRectangle(0, 0, 700, 400);
		iSetColor(20, 200, 0);
		iRectangle(50, 340, 600, 40);
		iSetColor(20, 200, 0);
		iText(160, 360, "CHANGE THE MOOD", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		iSetColor(20, 200, 0);
		iText(200, 310, "SET RINGTONE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(230, 260, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	// place your drawing codes here
	

	if (ringtone_mood == 1 && mood == 0 && settings_mode == 1&&show_reminder==0)
	{

		// iSetColor(255,255,255);
		iClear();
		if (dark_mood_on == 1)
		{
			iSetColor(0, 0, 0);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(255, 255, 255);
		}

		iFilledRectangle(0, 0, 700, 400);
		iSetColor(20, 200, 0);
		iRectangle(50, 340, 600, 40);
		iSetColor(20, 200, 0);
		iText(160, 360, "UEFA FOOTBALL THEME", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		iSetColor(20, 200, 0);
		iText(200, 310, "NOKIA PHONE RINGTONE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(230, 260, "RANDOM MUSIC", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);
		iSetColor(20, 200, 0);
		iText(320, 210, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
		// if(uefa==1) music_func();
	}
	if (ringtone_mood == 0 && mood == 1 && settings_mode == 0&&show_reminder==0)
	{

		// iSetColor(255,255,255);
		iClear();
		if (dark_mood_on == 1)
		{
			iSetColor(0, 0, 0);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(255, 255, 255);
		}

		iFilledRectangle(0, 0, 700, 400);
		iSetColor(20, 200, 0);
		iRectangle(50, 340, 600, 40);
		iText(220, 360, "DARK MOOD", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		iSetColor(20, 200, 0);
		iText(230, 310, "WHITE MOOD", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iSetColor(20, 200, 0);
		iText(240, 260, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	struct tm *ptr;
	time_t t;
	t = time(NULL);
	ptr = localtime(&t);

	hours = ptr->tm_hour;
	minutes = ptr->tm_min;
	days = ptr->tm_mday;
	months = ptr->tm_mon;
	years = ptr->tm_year;

	if ((hours == hour) && (minutes == minute) && (days == day) && ((months + 1) == month) && ((years + 1900) == year))
	{

		iText(100, 300, "Hurry Up! Your Event is now!", GLUT_BITMAP_TIMES_ROMAN_24);

		// music_call++;

		// if (music_call == 1)
		// {
		// 	music_func();
		// }
	}
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	// 	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if ((button == GLUT_LEFT_BUTTON) && mood==0&&ringtone_mood==0&&settings_mode==0&& (mx >= 50) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		show_reminder = 1; // entering settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 650) && (my >= 190) && (my <= 230))
	{
		settings_mode = 1;
		show_reminder =0 ; // entering settings
	}
	
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (mood == 0) && (mx >= 50) && (mx <= 650) && (my >= 240) && (my <= 280))
	{
		settings_mode = 0; // coming back from settings
	}

	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) &&(show_reminder==0) && (mx >=50) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		mood = 1;
		dark_mood_on = 1; // entering the mood
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 1) && (mood == 1) && (mx >= 50) && (mx <= 650) && (my >= 240) && (my <= 280))
	{
		mood = 0;
		settings_mode = 1;
		ringtone_mood = 0; // back from mood change
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (mx >= 50) && (mx <= 650) && (my >= 290) && (my <= 330))
	{
		ringtone_mood = 1; // entering the set ringtone
	}
	
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 1) && (mood == 1) && (mx >= 50) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		dark_mood_on = 1; // back from rintone change
	}

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 1) && (mood == 1) && (mx >= 50) && (mx <= 650) && (my >= 290) && (my <= 330))
	{
		dark_mood_on = 0; // back from rintone change
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (ringtone_mood == 1) && (mx >= 50) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		uefa = 1;
		music_on=1; // entering the set ringtone
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 1) && (ringtone_mood == 1) && (mx >= 50) && (mx <= 650) && (my >= 190) && (my <= 230))
	{
		ringtone_mood = 0;
		music_on=0; // back from rintone change
	}

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	// if(musicOn){
	//PlaySound("sounds_begin.wav", NULL, SND_LOOP | SND_ASYNC);
	//  }
	iInitialize(700, 400, "Todos Reminder");
	return 0;
}
