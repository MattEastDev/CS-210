/*	
	Matthew Pokorny
	11/13/21
	This program displays the current time in a 12 hour format and a 24 hour format. Additionally the program can take input from the user to add an hour, minute, or second to the clocks 
	running time. The clock will clear the screen every second to update the time accordingly.		

	This was a lot of fun! Figuring out the issue with the while loops was a bit tricky, but I am glad I figured it ou
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <windows.h>
#include "conio.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#ifdef _MSC_VER
#define getch() _getch()
#endif
#define clrscr(); system("cls");

// Most of these definitions are here for testing purposes.
using namespace std;
char userInput = '0';
int sec_prev = 0;
int addHour = 0;
int addMinute = 0;
int addSecond = 0;



void Show12Hour()	 //Note: The original while loop in the code caused a significant delay between updating. Glad I experimented with removing various parts of the program to see what worked.
{					//Additionally, I removed the double "inputTime" because I decided to go without it.

		int seconds, minutes, hours;
		string str;

		//storing total seconds
		time_t total_seconds = time(0);

		//getting values of seconds, minutes and hours
		struct tm* ct = localtime(&total_seconds);

		if (addHour == 24)
		{
			addHour = addHour - 24;
		}
		// This adds the total addition of addHour, addMinute, and addSecond to the total time
		seconds = ct->tm_sec + addSecond;
		minutes = ct->tm_min + addMinute;
		hours = ct->tm_hour + addHour;



		// Making sure seconds do not go over 60
		if (seconds >= 60)
		{
			seconds = seconds - 60;
			minutes = minutes + 1;
		}
		else
		{
			seconds = seconds;
		}
		// Making sure minutes do no go over 60
		if (minutes >= 60) 
		{
			minutes = minutes - 60;
			hours = hours + 1;
		}
		else
		{
			minutes = minutes;
		}

		int finalHours = hours;

		if (hours > 12)
		{
			hours = hours - 12;
		}
		else
		{
			hours = hours;
		}
		
		//converting it into 12 hour format
		if (finalHours >= 12 && finalHours < 24) 
		{
			str = "PM";
		}
			
		else if (finalHours >= 24 || finalHours <= 11) 
		{ 
			str = "AM"; 
		}
			
		hours = hours > 12 ? hours - 12 : hours;
		
	
		cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str;

	return;
}

void Show24Hour()
{
		int seconds, minutes, hours;
		string str;

		//storing total seconds
		time_t total_seconds = time(0);

		//getting values of seconds, minutes and hours
		struct tm* ct = localtime(&total_seconds);


		if (addHour == 24)
		{
			addHour = addHour - 24;
		}
		// This adds the total addition of addHour, addMinute, and addSecond to the total time
		seconds = ct->tm_sec + addSecond;
		minutes = ct->tm_min + addMinute;
		hours = ct->tm_hour + addHour;

		// Making sure seconds do not go over 60
		if (seconds >= 60)
		{
			seconds = seconds - 60;
			minutes = minutes + 1;
		}
		else
		{
			seconds = seconds;
		}

		// Making sure minutes do no go over 60
		if (minutes >= 60)
		{
			minutes = minutes - 60;
			hours = hours + 1;
		}
		else
		{
			minutes = minutes;
		}
		if (hours >= 24)
		{
			hours = hours - 24;
		}
	
		//printing the result	
		
		cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str;
	
	return;
}

void DisplayMenu(){
	
	clrscr(); // Clears the screen every second

	cout << endl;
	cout << "    *************************     *************************\n";
	cout << "    *     12-Hour Clock     *     *      24-Hour Clock    *\n";
	cout << "    *      ";

	Show12Hour(); // Prints the 12 hour format

	cout << "      *     *        ";

	Show24Hour(); // Prints the 24 hour format

	cout << "      * \n";
	cout << "    *************************     *************************\n";
	
	string center = "                   ";
	string border = "**************************";

	cout << center << border << endl;
	cout << center << "* 1 - Add One Hour       * \n";
	cout << center << "* 2 - Add One Minute     * \n";
	cout << center << "* 3 - Add One Second     * \n";
	cout << center << "* 4 - Exit Program       * \n";
	cout << center << border << endl;
}

void ClosingMessage() // Honestly made this for fun so the closing out has an animation of a sort
{
	cout << endl;
	cout << endl;
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << "C";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "s";
	Sleep(150);
	cout << "i";
	Sleep(150);
	cout << "n";
	Sleep(150);
	cout << "g";
	Sleep(150);
	cout << " ";
	Sleep(150);
	cout << "P";
	Sleep(150);
	cout << "r";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "g";
	Sleep(150);
	cout << "r";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "m";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	clrscr();
	cout << "Goodbye!";
	Sleep(350);
}

int main()
{
	while (userInput != 4)
	{	
		DisplayMenu();
		
		if (kbhit()) // This was a godsend. I could not get anything to work. kbhit() simply checks to see if the keyboard has a press, if there is, it passes it on to getch(); which assigns the  
		{            // pressed key to userInput.
			userInput = getch();
		}

		if (userInput == '1')
		{
			addHour = addHour + 1;
		}
		if (userInput == '2')
		{
			addMinute = addMinute + 1;
		}
		if (userInput == '3')
		{
			addSecond = addSecond + 1;
		}
		if (userInput == '4')
		{
			clrscr();
			ClosingMessage();
			return 0;
		}

		if (userInput != '0')
		{
			userInput = '0';
		}
		Sleep(1000); // Our one second delay for relooping
	}	
	
}


