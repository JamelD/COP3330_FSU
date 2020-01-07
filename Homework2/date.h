/*
Name: Jamel Douglas
Date: 1/30/2019
Section: 6
Assignment: prog2 

All work below has been performed by Jamel Douglas
*/

#ifndef __DATE_H
#define __DATE_H

class Date{
	public:
		//contructors
		Date();
		Date(int, int =1, int =2019);
		
		//Member function that alllows user input.
		void Input();
		
		//member functions that return private date from class
		int GetMonth();
		int GetDay();
		int GetYear();
		
		//member functions can change values of objects
		bool Set(int m, int d, int y);
		void Increment();
		
		//member functions that print/compare dates.
		int DayofWeek(int m, int d, int y);
		int Compare(const Date& d);
		void ShowByDay();
		void ShowByMonth();
		
	private:
		int month, day, year;
		
};

#endif 
