#include "iGraphics.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

int settings_mode = 0;
int add_task = 0, guideline = 0;
int mood = 0;
int dark_mood_on = 0;
int ringtone_mood = 0;
int uefa = 1, nokia = 0, random = 0, show_reminder = 0;
int musicOn = 1;
int hour, minute, day, month, year;
char str[1000] = {0};
int str_Index = -1, str_Index1 = -1;
char str1[1000] = {0};
int isCalled = 1;
int time_count_down = 0;
int hours, minutes, days, months, years;
int music_on = 0;
int time_on = 0;
int key_Board = 0;
int key_Board2 = 0;
int x = 1000, y = 300, r = 20;
char bc[1][20] = {"12.bmp"};
char back[1][20] = {"back.bmp"};
char bc1[1][20] = {"peakpx.bmp"};

void musicfunc()
{
	if (uefa == 0 && random == 0 && nokia == 1)
	{
		if (nokia == 1 && music_on == 1)
		{
			PlaySound(TEXT("Sounds_begin.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (uefa == 0 && random == 1 && nokia == 0)
	{
		if (random == 1 && music_on == 1)
		{
			PlaySound(TEXT("greek.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (uefa == 1 && random == 0 && nokia == 0)
	{
		if (uefa == 1 && music_on == 1)
		{
			PlaySound(TEXT("uefa_anthem.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}

	if ((music_on == 0) && (minutes != minute))
	{
		PlaySound(0, 0, 0);
	}
}

void diff_event_date_hr_min()
{

	char *ptr1 = strtok(str, "&/");
	ptr1 = strtok(NULL, "&/");
	day = atoi(ptr1);
	ptr1 = strtok(NULL, "&/");
	month = atoi(ptr1);
	ptr1 = strtok(NULL, "&/");
	year = atoi(ptr1);
	ptr1 = strtok(NULL, "&:");
	hour = atoi(ptr1);
	ptr1 = strtok(NULL, "&:");
	minute = atoi(ptr1);
}
void add_task_to_text_file(void)
{
	if (key_Board == 1)
	{
		FILE *FileOpen;

		char FileName[] = "TodosReminder.txt";
		FileOpen = fopen(FileName, "a");
		fprintf(FileOpen, str);
		fprintf(FileOpen, "\n");
		fclose(FileOpen);
	}
	if (key_Board2 == 1)
	{
		FILE *FileOpen1;

		char FileName1[] = "my name is khan.txt";
		FileOpen1 = fopen(FileName1, "a");
		fprintf(FileOpen1, str1);
		fprintf(FileOpen1, "\n");
		fclose(FileOpen1);
	}
}

void taking_input(unsigned char key)
{
	if (key_Board == 1)
	{
		if (key == '\b')
		{
			if (str_Index >= 0)
			{
				str[str_Index] = '\0';
				str_Index--;
			}
		}
		else
		{
			str_Index++;
			str[str_Index] = key;
		}
	}
	if (key_Board2 == 1)
	{
		if (key == '\b')
		{
			if (str_Index1 >= 0)
			{
				str1[str_Index1] = '\0';
				str_Index1--;
			}
		}
		else
		{
			str_Index1++;
			str1[str_Index1] = key;
		}
	}
}
void CheckAlarm()
{
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

		iText(160, 100, "GET READY FOR YOUR EVENT", GLUT_BITMAP_TIMES_ROMAN_24);
		music_on = 1;
		musicfunc();
	}
}
void DoFast()
{
	if (isCalled)
	{
		isCalled = 0;
	}

	else
	{
		isCalled = 1;
	}
}

/*
	function iDraw() is called again and again by the system.

	*/

void iDraw()
{

	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 0 && guideline == 0)
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

		iSetColor(102, 0, 0);
		iRectangle(50, 340, 600, 40);

		iText(160, 360, "Enter the time and date of your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);

		iText(210, 310, "Your activity you have to do", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);

		iText(160, 260, "History about the activity of last month", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);

		iText(310, 210, "Settings", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 140, 600, 40);

		iText(280, 160, "User Guidline", GLUT_BITMAP_TIMES_ROMAN_24);

		if (isCalled == 1)
		{
			if ((hours == hour) && (minutes == minute) && (days == day) && ((months + 1) == month) && ((years + 1900) == year))
			{

				iText(160, 100, "GET READY FOR YOUR EVENT", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
	}

	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 1)
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
		iShowBMP(0, 0, bc[0]);
		iSetColor(0, 0, 0);
		iText(180, 300, "Enter the time and date of your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(280, 270, "Input Format", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(180, 240, "(i.e.First Ramadan&11/3/2024&21:30)", GLUT_BITMAP_TIMES_ROMAN_24);
		if (dark_mood_on == 1)
		{
			iSetColor(0, 0, 0);
		}

		if (dark_mood_on == 0)
		{

			iSetColor(255, 255, 255);
		}
		iSetColor(150, 150, 150);
		iFilledRectangle(130, 180, 450, 40);
		iSetColor(0, 0, 0);
		iText(150, 195, str, GLUT_BITMAP_TIMES_ROMAN_24);
		// iSetColor(102, 0, 0);
		iSetColor(150, 150, 150);
		// iFilledRectangle(122, 150, 450, 22);
		iSetColor(0, 0, 0);
		iText(180, 150, "Enter description about your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		iFilledRectangle(130, 98, 450, 40);
		iSetColor(0, 0, 0);
		iText(150, 112, str1, GLUT_BITMAP_TIMES_ROMAN_24);
		// iSetColor(59,122,87);
		// iRectangle(285, 40, 80, 40);
		// iText(300, 55, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(285, 40, back[0], 0);
	}
	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && guideline == 1)
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
		iShowBMP(0, 0, bc1[0]);
		iSetColor(102, 0, 0);
		iText(280, 300, "Input Format", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 270, "(Event Name)&(dd/mm/yr)&(hr:min)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 240, "i.e.First Ramadan&25/3/2023&5:30", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(140, 210, "Time must be in international format.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(180, 180, "You can set multiple events.", GLUT_BITMAP_TIMES_ROMAN_24);
		//  iText(110,150 , "But alarm will ring based on your last reminder." , GLUT_BITMAP_TIMES_ROMAN_24) ;

		// iRectangle(285, 40, 80, 40);
		// iText(300, 55, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(300, 55, back[0], 0);
	}

	if (settings_mode == 1 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 0)
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
		iSetColor(102, 0, 0);
		iRectangle(50, 340, 600, 40);
		// iSetColor(153, 255, 153);
		iText(230, 360, "CHANGE THE MODE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		iSetColor(102, 0, 0);
		iText(250, 310, "SET RINGTONE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(310, 260, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (ringtone_mood == 0 && mood == 1 && settings_mode == 0 && show_reminder == 0 && add_task == 0)
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
		iSetColor(102, 0, 0);
		iRectangle(50, 340, 600, 40);
		iText(260, 360, "WHITE MODE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		// iSetColor(20, 200, 0);
		iText(260, 310, "DARK MODE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		// iSetColor(20, 200, 0);
		iText(300, 260, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (ringtone_mood == 1 && mood == 0 && settings_mode == 0 && show_reminder == 0 && add_task == 0)
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
		iSetColor(102, 0, 0);
		iRectangle(50, 340, 600, 40);
		// iSetColor(20, 200, 0);
		iText(205, 360, "UEFA FOOTBALL THEME", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);
		// iSetColor(20, 200, 0);
		iText(200, 310, "NOKIA PHONE RINGTONE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(250, 260, "RANDOM MUSIC", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);
		// iSetColor(20, 200, 0);
		iText(300, 210, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 340) && (my <= 380))
	{
		add_task = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mx >= 250) && (mx <= 400) && (my >= 180) && (my <= 220))
	{
		key_Board = 1;
		key_Board2 = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mx >= 250) && (mx <= 400) && (my >= 100) && (my <= 140))
	{
		key_Board2 = 1;
		key_Board = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		add_task = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 190) && (my <= 230))
	{
		settings_mode = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (mood == 0) && (mx >= 250) && (mx <= 400) && (my >= 240) && (my <= 280))
	{
		settings_mode = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 140) && (my <= 180))
	{
		guideline = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (guideline == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		guideline = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (show_reminder == 0) && (mx >= 250) && (mx <= 400) && (my >= 340) && (my <= 380))
	{
		mood = 1;
		settings_mode = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 0) && (mood == 1) && (mx >= 450) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		dark_mood_on = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 0) && (mood == 1) && (mx >= 450) && (mx <= 650) && (my >= 290) && (my <= 330))
	{
		dark_mood_on = 1;
	}

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 0) && (mood == 1) && (mx >= 450) && (mx <= 650) && (my >= 240) && (my <= 280))
	{
		mood = 0;
		settings_mode = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (show_reminder == 0) && (mx >= 250) && (mx <= 400) && (my >= 290) && (my <= 330))
	{
		ringtone_mood = 1;
		settings_mode = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (settings_mode == 0) && (ringtone_mood == 1) && (mx >= 450) && (mx <= 650) && (my >= 190) && (my <= 230))
	{
		music_on = 0;
		ringtone_mood = 0;
		settings_mode = 1;
		musicfunc();

		// back from ringtone change
	}

	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 0) && (ringtone_mood == 1) && (show_reminder == 0) && (mx >= 450) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		uefa = 1;
		nokia = 0;
		random = 0;
		music_on = 1;

		musicfunc();
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 0) && (ringtone_mood == 1) && (show_reminder == 0) && (mx >= 450) && (mx <= 650) && (my >= 290) && (my <= 330))
	{
		uefa = 0;
		nokia = 1;
		random = 0;
		music_on = 1;

		musicfunc();
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 0) && (ringtone_mood == 1) && (show_reminder == 0) && (mx >= 450) && (mx <= 650) && (my >= 240) && (my <= 280))
	{
		uefa = 0;
		nokia = 0;
		random = 1;
		music_on = 1;

		musicfunc();
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key_Board == 1)
	{

		taking_input(key);
	}

	if (key_Board == 1)
	{
		if (key == '\r')
		{
			add_task_to_text_file();
			diff_event_date_hr_min();

			//time_count_down = 1;
			memset(str, 0, sizeof(str));
			str_Index = -1;
		}
	}
	if (key_Board2 == 1)
	{

		taking_input(key);
	}

	if (key_Board2 == 1)
	{
		if (key == '\r')
		{
			add_task_to_text_file();
			// diff_event_date_hr_min();

			// time_count_down = 1;
			memset(str1, 0, sizeof(str1));
			str_Index1 = -1;
		}
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
	iSetTimer(10000, CheckAlarm);
	iSetTimer(1000, DoFast);
	iInitialize(700, 400, "Todos Reminder");

	return 0;
}