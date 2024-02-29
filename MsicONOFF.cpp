#include "iGraphics.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

int settings_mode = 0;
int nick = 0;
int follow = 0;
int search = 0;
int add_task = 0, guideline = 0;
int mood = 0;
int dark_mood_on = 1;
int ringtone_mood = 0;
int uefa = 1, nokia = 0, random = 0, show_reminder = 0;
int musicOn = 1;
int dailyA = 0;
int hour, minute, day, month, year;
int hr2, hr3, min2, min3;
char *lv1 = "Very", *lv2 = "Medium", *lv3 = "Less";
char *found;
char *tet;
int very = 0, medium = 0, less = 0, priority = 1;
char str[1000] = {0};
int str_Index = -1, str_Index1 = -1, str_Index2 = -1, str_Index3 = -1, str_Index4 = -1, str_Index5 = -1;
char str1[1000] = {0};
char str2[1000] = {0};
char str4[1000] = {0};
char str3[1000] = {0};
char str5[1000] = {0};
char red[100] = {0};
int isCalled = 1;
int time_count_down = 0;
int hours, minutes, days, months, years;
int music_on = 0;
int music_on1=0,music_on2=0;
int time_on = 0;
int key_Board = 0;
int key_Board2 = 0;
int key_Board3 = 0;
int key_Board4 = 0;
int key_Board5 = 0;
int next = 1;
int x = 1000, y = 300, r = 20;
char bc[1][20] = {"12.bmp"};
char back[1][20] = {"back.bmp"};
char bc1[1][20] = {"question.bmp"};

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
	if (key_Board3 == 1)
	{
		if (key == '\b')
		{
			if (str_Index3 >= 0)
			{
				str3[str_Index3] = '\0';
				str_Index3--;
			}
		}
		else
		{
			str_Index3++;
			str3[str_Index3] = key;
		}
	}
	if (key_Board4 == 1)
	{
		if (key == '\b')
		{
			if (str_Index4 >= 0)
			{
				str4[str_Index4] = '\0';
				str_Index4--;
			}
		}
		else
		{
			str_Index4++;
			str4[str_Index4] = key;
		}
	}
	if (key_Board5 == 1)
	{
		if (key == '\b')
		{
			if (str_Index5 >= 0)
			{
				str5[str_Index5] = '\0';
				str_Index5--;
			}
		}
		else
		{
			str_Index5++;
			str5[str_Index5] = key;
		}
	}
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
	if (key_Board5 == 1)
	{
		FILE *FileOpen1;

		char FileName1[] = "daily.txt";
		FileOpen1 = fopen(FileName1, "a");
		fprintf(FileOpen1, str5);
		fprintf(FileOpen1, "\n");
		fclose(FileOpen1);
	}
}
void musicfunc()
{
	if (uefa == 0 && random == 0 && nokia == 1)
	{
		if (nokia == 1 && music_on1 == 1)
		{
			PlaySound(TEXT("Sounds_begin.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (uefa == 0 && random == 1 && nokia == 0)
	{
		if (random == 1 && music_on1 == 1)
		{
			PlaySound(TEXT("greek.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (uefa == 1 && random == 0 && nokia == 0)
	{
		if (uefa == 1 && music_on1 == 1)
		{
			PlaySound(TEXT("uefa_anthem.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}

	if (music_on1 == 0)
	{
		PlaySound(0, 0, 0);
	}
}
void musicfunc3()
{
	if (uefa == 0 && random == 0 && nokia == 1)
	{
		if (nokia == 1 && music_on2 == 1)
		{
			PlaySound(TEXT("Sounds_begin.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (uefa == 0 && random == 1 && nokia == 0)
	{
		if (random == 1 && music_on2 == 1)
		{
			PlaySound(TEXT("greek.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (uefa == 1 && random == 0 && nokia == 0)
	{
		if (uefa == 1 && music_on2 == 1)
		{
			PlaySound(TEXT("uefa_anthem.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
	}

	if (music_on2 == 0)
	{
		PlaySound(0, 0, 0);
	}
}
void musicfunc2()
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

	if (music_on == 0)
	{
		PlaySound(0, 0, 0);
	}
}
void color()
{
	if (very == 1 && less == 0 && medium == 0 && priority == 1)
	{
		iSetColor(255, 0, 0);
	}
	if (very == 0 && less == 0 && medium == 1 && priority == 1)
	{
		iSetColor(0, 255, 0);
	}
	if (very == 0 && less == 1 && medium == 0 && priority == 1)
	{
		iSetColor(0, 0, 255);
	}
}
void diff_event_date_hr_min()
{

	char *ptr1 = strtok(str, "&&");
	for (int i = 0; i < strlen(ptr1); i++)
	{
		red[i] = *(ptr1 + i);
	}

	ptr1 = strtok(NULL, "&/");
	day = atoi(ptr1);
	ptr1 = strtok(NULL, "&/");
	month = atoi(ptr1);
	ptr1 = strtok(NULL, "&/");
	year = atoi(ptr1);
	ptr1 = strtok(NULL, "&:");
	hour = atoi(ptr1);
	ptr1 = strtok(NULL, "&/");
	minute = atoi(ptr1);
	char *ch = str2;
	found = ch;
}
void diff_hr_min()
{
	char *ptr5 = strtok(str5, "&:");
	hr2 = atoi(ptr5);
	ptr5 = strtok(NULL, "&/");
	min2 = atoi(ptr5);
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

		music_on1 = 1;
		musicfunc();
	}
	if ((hr2 == hours) && (min2 == minutes))
	{
		music_on2 = 1;
		follow = 1;
		musicfunc3();
	}
	if(minutes!=minute&&music_on1==1){
		music_on1=0;
		musicfunc();
	}
	if(minutes!=min2&&music_on2==1){
		music_on2=0;
		musicfunc3();
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

	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 0 && guideline == 0 && search == 0 && nick == 0 && dailyA == 0)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		iRectangle(50, 340, 600, 40);

		iText(160, 360, "Enter the time and date of your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);

		iText(280, 310, "Search activity ", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);

		iText(160, 260, "History about the activity your past activity", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);

		iText(310, 210, "Settings", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 140, 600, 40);

		iText(240, 160, "Set Your Daily Alarm", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 90, 600, 40);

		iText(180, 110, "Search your notes and description", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(50, 50, bc1[0], 0);

		if (isCalled == 1)
		{
			if ((hours == hour) && (minutes == minute) && (days == day) && ((months + 1) == month) && ((years + 1900) == year))
			{
				priority = 1;
				color();
				iText(200, 70, "IT IS TIME FOR YOUR EVENT", GLUT_BITMAP_HELVETICA_18);
				iText(310, 50, red, GLUT_BITMAP_HELVETICA_18);
				iText(200, 30, "GET READY FOR YOUR EVENT", GLUT_BITMAP_HELVETICA_18);
			}
			if ((hr2 == hours) && (min2 == minutes) && (follow == 1))
			{
				iText(200, 70, "IT IS TIME FOR YOUR DAILY EVENT", GLUT_BITMAP_HELVETICA_18);
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
		iText(250, 370, "Importance level", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(150, 150, 150);
		if (very == 1 && priority == 1)
		{
			iSetColor(255, 0, 0);
		}
		iFilledRectangle(160, 320, 90, 40);
		iSetColor(0, 0, 0);
		iText(180, 335, "VERY", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		if (medium == 1 && priority == 1)
		{
			iSetColor(0, 255, 0);
		}
		iFilledRectangle(280, 320, 115, 40);
		iSetColor(0, 0, 0);
		iText(285, 335, "MEDIUM", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		if (less == 1 && priority == 1)
		{
			iSetColor(0, 0, 255);
		}
		iFilledRectangle(420, 320, 90, 40);
		iSetColor(0, 0, 0);
		iText(440, 335, "LESS", GLUT_BITMAP_TIMES_ROMAN_24);

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

		iSetColor(150, 150, 150);

		iSetColor(0, 0, 0);
		iText(40, 150, "Enter note about event (i.e Ramadan & Start of holy month)", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		iFilledRectangle(130, 98, 450, 40);
		iSetColor(0, 0, 0);
		iText(150, 112, str1, GLUT_BITMAP_TIMES_ROMAN_24);

		iShowBMP2(285, 40, back[0], 0);
	}
	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 0 && search == 1)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}

		iText(200, 350, "Enter the name of your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		iFilledRectangle(130, 300, 450, 40);
		iSetColor(0, 0, 0);
		iText(150, 314, str3, GLUT_BITMAP_TIMES_ROMAN_24);
		FILE *fp4;

		fp4 = fopen("TodosReminder.txt", "r");

		char line[100];
		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}

		iText(50, 275, "Event Name", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 275, "Date", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550, 275, "Time", GLUT_BITMAP_TIMES_ROMAN_24);

		int y_axis = 240;
		char *token;
		int flag = 0;

		while (fscanf(fp4, "%s", line) != EOF)
		{

			token = strtok(line, "&&");

			if (strstr(token, str3) != NULL)
			{
				flag = 1;

				iText(70, y_axis, token, GLUT_BITMAP_HELVETICA_18);

				token = strtok(NULL, "&&");
				iText(305, y_axis, token, GLUT_BITMAP_HELVETICA_18);

				token = strtok(NULL, "&&");
				iText(550, y_axis, token, GLUT_BITMAP_HELVETICA_18);
				y_axis -= 40;
			}

			token = strtok(NULL, "&&");
			token = strtok(NULL, "&&");
		}
		if (flag == 0)
		{
			iText(60, y_axis, "No matching events found", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		fclose(fp4);
		iShowBMP2(285, 40, back[0], 0);
	}

	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 1 && add_task == 0)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		FILE *fp3;

		fp3 = fopen("TodosReminder.txt", "r");

		char line[100];
		int y = 0;

		iText(50, 380, "Event Name", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 380, "Date", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550, 380, "Time", GLUT_BITMAP_TIMES_ROMAN_24);

		int i = 1;
		int y_axis = 350;
		char *token;

		while (fscanf(fp3, "%s", line) != EOF)
		{

			char st_r[10];
			sprintf(st_r, "%d", i);
			iText(45, y_axis, st_r, GLUT_BITMAP_HELVETICA_18);
			iText(65, y_axis, ".", GLUT_BITMAP_HELVETICA_18);

			token = strtok(line, "&&");
			iText(70, y_axis, token, GLUT_BITMAP_HELVETICA_18);

			token = strtok(NULL, "&&");
			iText(305, y_axis, token, GLUT_BITMAP_HELVETICA_18);

			token = strtok(NULL, "&&");
			iText(550, y_axis, token, GLUT_BITMAP_HELVETICA_18);

			i++;
			y_axis -= 30;
		}

		fclose(fp3);
		iShowBMP2(285, 40, back[0], 0);
	}
	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 0 && search == 0 && nick == 1)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		iText(200, 350, "Enter the name of your event", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		iFilledRectangle(130, 300, 450, 40);
		iSetColor(150, 150, 150);
		iFilledRectangle(50, 150, 600, 100);
		iSetColor(0, 0, 0);
		iText(150, 314, str4, GLUT_BITMAP_TIMES_ROMAN_24);
		FILE *fp5;

		fp5 = fopen("my name is khan.txt", "r");
		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}

		char line[100];
		int y_axis = 200;
		char *token;

		iText(50, 275, "The note you entered is given below:", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0, 0, 0);
		while (fgets(line, 100, fp5) != NULL)
		{

			token = strtok(line, "&&");

			if (strcmp(str4, token) == 0)
			{

				token = strtok(NULL, "&.");
				iText(100, y_axis, token, GLUT_BITMAP_TIMES_ROMAN_24);

				y_axis -= 80;
			}

			token = strtok(NULL, "&.");
		}

		fclose(fp5);

		iShowBMP2(285, 80, back[0], 0);
	}
	if (settings_mode == 0 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && guideline == 0 && dailyA == 1)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}

		iText(180, 350, "Enter Time of your daily alarm (i.e hr:mm)", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(150, 150, 150);
		iFilledRectangle(130, 300, 450, 40);
		iSetColor(0, 0, 0);
		iText(150, 314, str5, GLUT_BITMAP_TIMES_ROMAN_24);

		iShowBMP2(300, 55, back[0], 0);
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		iText(280, 350, "Input Format", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(172, 310, "(Event Name)&(dd/mm/yr)&(hr:min)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(182, 270, "i.e.First Ramadan&25/3/2023&5:30", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 230, "(Event Name)&(description)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(182, 190, "i.e Ramadan & Start of holy month", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(175, 150, "Time must be in international format.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(215, 110, "You can set multiple events.", GLUT_BITMAP_TIMES_ROMAN_24);

		iShowBMP2(300, 55, back[0], 0);
	}

	if (settings_mode == 1 && mood == 0 && ringtone_mood == 0 && show_reminder == 0 && add_task == 0)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		iRectangle(50, 340, 600, 40);

		iText(230, 360, "CHANGE THE MODE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);

		iText(250, 310, "SET RINGTONE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(310, 260, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (ringtone_mood == 0 && mood == 1 && settings_mode == 0 && show_reminder == 0 && add_task == 0)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		iRectangle(50, 340, 600, 40);
		iText(260, 360, "WHITE MODE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);

		iText(260, 310, "DARK MODE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);

		iText(300, 260, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (ringtone_mood == 1 && mood == 0 && settings_mode == 0 && show_reminder == 0 && add_task == 0)
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

		if (dark_mood_on == 1)
		{
			iSetColor(255, 255, 255);
		}
		if (dark_mood_on == 0)
		{
			iSetColor(0, 0, 0);
		}
		iRectangle(50, 340, 600, 40);

		iText(205, 360, "UEFA FOOTBALL THEME", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 290, 600, 40);

		iText(200, 310, "NOKIA PHONE RINGTONE", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 240, 600, 40);
		iText(250, 260, "RANDOM MUSIC", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(50, 190, 600, 40);

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
		key_Board3 = 0;
		key_Board4 = 0;
		key_Board5 = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mx >= 250) && (mx <= 400) && (my >= 100) && (my <= 140))
	{
		key_Board2 = 1;
		key_Board = 0;
		key_Board3 = 0;
		key_Board4 = 0;
		key_Board5 = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mx >= 160) && (mx <= 250) && (my >= 320) && (my <= 360))
	{
		very = 1;
		less = 0;
		medium = 0;
		priority = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mx >= 280) && (mx <= 395) && (my >= 320) && (my <= 360))
	{
		very = 0;
		less = 0;
		medium = 1;
		priority = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mx >= 420) && (mx <= 510) && (my >= 320) && (my <= 360))
	{
		very = 0;
		less = 1;
		medium = 0;
		priority = 1;
	}

	if ((button == GLUT_LEFT_BUTTON) && (add_task == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		add_task = 0;
		priority = 0;
		key_Board2 = 0;
		key_Board = 0;
		// coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 190) && (my <= 230))
	{
		settings_mode = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 240) && (my <= 280))
	{
		show_reminder = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 290) && (my <= 330))
	{
		search = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (search == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		search = 0;
		key_Board3 = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 0) && (mx >= 250) && (mx <= 400) && (my >= 300) && (my <= 340) && (search == 1))
	{
		key_Board2 = 0;
		key_Board = 0;
		key_Board3 = 1;
		key_Board4 = 0;
		key_Board5 = 0;
	}

	if ((button == GLUT_LEFT_BUTTON) && (guideline == 0) && (show_reminder == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		show_reminder = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 1) && (mood == 0) && (mx >= 250) && (mx <= 400) && (my >= 240) && (my <= 280))
	{
		settings_mode = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 110) && (my >= 50) && (my <= 100))
	{
		guideline = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (guideline == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		guideline = 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 90) && (my <= 130))
	{
		nick = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (mx >= 50) && (mx <= 200) && (my >= 140) && (my <= 180))
	{
		dailyA = 1;
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 0) && (search == 0) && (nick == 0) && (dailyA == 1) && (mx >= 250) && (mx <= 400) && (my >= 300) && (my <= 340))
	{
		key_Board2 = 0;
		key_Board = 0;
		key_Board5 = 1;
		key_Board3 = 0;
		key_Board4 == 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (guideline == 0) && (dailyA == 1) && (mood == 0) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 40) && (my <= 80))
	{
		dailyA = 0;
		key_Board5 == 0; // coming back from settings
	}
	if ((button == GLUT_LEFT_BUTTON) && (add_task == 0) && (search == 0) && (nick == 1) && (mx >= 250) && (mx <= 400) && (my >= 300) && (my <= 340))
	{
		key_Board2 = 0;
		key_Board = 0;
		key_Board4 = 1;
		key_Board3 = 0;
		key_Board5 = 0;
	}
	if ((button == GLUT_LEFT_BUTTON) && (guideline == 0) && (mood == 0) && (nick == 1) && (settings_mode == 0) && (mx >= 285) && (mx <= 365) && (my >= 80) && (my <= 120))
	{
		nick = 0;
		key_Board4 = 0; // coming back from settings
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
		musicfunc2();

		// back from ringtone change
	}

	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 0) && (ringtone_mood == 1) && (show_reminder == 0) && (mx >= 450) && (mx <= 650) && (my >= 340) && (my <= 380))
	{
		uefa = 1;
		nokia = 0;
		random = 0;
		music_on = 1;

		musicfunc2();
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 0) && (ringtone_mood == 1) && (show_reminder == 0) && (mx >= 450) && (mx <= 650) && (my >= 290) && (my <= 330))
	{
		uefa = 0;
		nokia = 1;
		random = 0;
		music_on = 1;

		musicfunc2();
	}
	if ((button == GLUT_LEFT_BUTTON) && (settings_mode == 0) && (ringtone_mood == 1) && (show_reminder == 0) && (mx >= 450) && (mx <= 650) && (my >= 240) && (my <= 280))
	{
		uefa = 0;
		nokia = 0;
		random = 1;
		music_on = 1;

		musicfunc2();
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

			// time_count_down = 1;
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

			memset(str1, 0, sizeof(str1));
			str_Index1 = -1;
		}
	}
	if (key_Board3 == 1)
	{

		taking_input(key);
	}

	if (key_Board3 == 1)
	{
		if (key == '\r')
		{
			// add_task_to_text_file();

			memset(str3, 0, sizeof(str3));
			str_Index3 = -1;
		}
	}
	if (key_Board4 == 1)
	{

		taking_input(key);
	}

	if (key_Board4 == 1)
	{
		if (key == '\r')
		{
			// add_task_to_text_file();

			memset(str4, 0, sizeof(str4));
			str_Index4 = -1;
		}
	}
	if (key_Board5 == 1)
	{

		taking_input(key);
	}

	if (key_Board5 == 1)
	{
		if (key == '\r')
		{
			add_task_to_text_file();

			diff_hr_min();

			memset(str5, 0, sizeof(str5));
			str_Index5 = -1;
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