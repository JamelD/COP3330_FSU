/*
Name: Jamel Douglas
Date: 1/30/2019
Section: 6
Assignment: prog2

All work below has been performed by Jamel Douglas
*/
#include <iostream>
#include "date.h"
using namespace std;

//Default Constuctor, initializes to 1/1/2019
Date::Date(){
	month = 1;
	day = 1;
	year = 2019;
}

//Constructor, takes in 3 values to set date
Date::Date(int m, int d, int y){
	
	//add in leap year checking
	month = m;
	day = d;
	year = y;
}

//function allows user to enter date into system
void Date::Input(){
	int m, d, y;
	char dumbVAR;
	bool e = true;
	
	do{ //error checking for user input
		cout << "Please enter a date: ";
		cin >> m >> dumbVAR >> d >> dumbVAR >> y;
		//cout << m << " ; " << d << " ; " << y << endl;
		if(y >= 1900){
			if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
				if(d >= 1 && d <= 31){
					month = m;
					day = d;
					year = y;
					e = false;
				}else{
					cout << "Invalid date. Try again!" << endl;
				}
			}else if(m == 4 || m == 6 || m == 9 || m == 11){
				if(d >= 1 && d <= 30){
					month = m;
					day = d;
					year = y;
					e = false;
				}else{
					cout << "Invalid date. Try again!" << endl;
				}
			}else if(m == 2){
				if(y % 4 == 0 || y % 400 == 0){
					if(d >= 1 && d <= 29){
						month = m;
						day = d;
						year = y;
						e = false;
					}else{
						cout << "Invalid date. Try again!"  << endl;
					}
				}else{
					if(d >= 1 && d <= 28){
						month = m;
						day = d;
						year = y;
						e = false;
					}else{
						cout << "Invalid date. Try again!" << endl;
					}
				}
			}else{
				cout << "Invalid date. Try again!" << endl;
			}
			
		}else{
			cout << "Invalid date. Try again!" << endl;
		}
	}while(e == true);
}

//function returns month value
int Date::GetMonth(){
	int m;
	m = month;
	return m;
}

//function returns day value
int Date::GetDay(){
	int d;
	d = day;
	return d;
}

//function returns year value
int Date::GetYear(){
	int y;
	y = year;
	return y;
}

//Function used to set values of day after object is created
bool Date::Set(int m, int d, int y){
	if(m >= 1 && m <= 12){
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
			if(d >= 1 && d <= 31){
				if(y >= 1990){
					month = m;
					day = d;
					year = y;
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else if(m == 2){
			if(d >= 1 && d <= 29){ //factor in leap year factors
				if(y >= 1990){
					if(year % 4 == 0 || year % 400 == 0){
						month = m;
						day = d;
						year = y;
						return true;
					
					}else{
						if(d >= 1 && d <= 28){
							month = m;
							day = d;
							year = y;
							return true;
						
						}else{
							return false;
						}
					}
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else if(m == 4 || m == 6 || m == 9 || m == 11){
			if(d >= 1 && d <= 30){
				if(y >= 1990){
					month = m;
					day = d;
					year = y;
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

//function increments day by one while keepping month,day,and year values intact
void Date::Increment(){
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){/*month has 31 days and next day is after final day*/
		if(day == 31){
			month++;
			day = 1;
		}else{
			day++;
		}
		
	}else if(month == 4 || month == 6 || month == 9 || month == 11){/*month has 30 days a next day is after final day*/
		if(day == 30){
			month++;
			day = 1;
		}else{
			day++;
		}
		
	}else if(month == 2){/*Feburrary next day is after final day*/
		if(year % 4 == 0 || year % 400 == 0){
			if(day == 29){
				month++;
				day = 1;
			}else{
				day++;
			}
		}else{
			if(day == 28){
				month++;
				day = 1;
			}else{
				day++;
			}
		}
	}else if(month == 12 && day == 31){/*december 31st, next day has different year*/
		month = 1;
		day = 1;
		year++;
		
	}else{
		
	}
}

// Function returns day of week in values 0 - 6 (Su-Sa)
int Date::DayofWeek(int m, int d, int y){
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

//Function compares 2 dates
int Date::Compare(const Date& d){
	if(year > d.year){/*calling object first*/
		return -1;
		
	}else if(year == d.year){/*objects are equal*/
		if(month > d.month){/*calling object first*/
			return -1;
			
		}else if(month == d.month){/*objects are equal*/
			if(day > d.day){/*calling object first*/
				return -1;
				
			}else if(day == d.day){/*objects are equal*/
				return 0;
				
			}else if(day < d.day){/*paramater object first*/
				return 1;
			}
			
		}else if(month < d.month){/*paramater object first*/
			return 1;
			
		}
	}else if(year < d.year){ /*paramater object first*/
		return 1;
		
	}else{
		return 4;
	}
	return 4;
}

//function prints out date in terms of mm/dd/yyyy
void Date::ShowByDay(){
	int m, d, y;
	m = month;
	d = day;
	y = year;
	
	
	cout << m << "/" << d << "/" << y << endl;	
}

//Function prints out date in month form, like a calendar
void Date::ShowByMonth(){
	// brings in day of week in values 0 - 6 (Su-Sa)
	int firstDay = DayofWeek(month, 1, year);
	int DaysinMonth;
	
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		DaysinMonth = 31;
		
	}else if(month == 4 || month == 6 || month == 9 || month == 11){
		DaysinMonth = 30;
		
	}else{
		if(year % 4 == 0 || year % 400 == 0){
			DaysinMonth = 29;
			
		}else{
			DaysinMonth = 28;
			
		}
	}
	//finisb formating month name
	switch(month){
		case 1: cout << "****** January " << year << " ******" << endl; break;
		case 2: cout << "****** February " << year << " ******" << endl; break;
		case 3: cout << "******* March " << year << " *******" << endl; break;
		case 4: cout << "****** April " << year << " ******" << endl; break;
		case 5: cout << "****** May " << year << " ******" << endl; break;
		case 6: cout << "****** June " << year << " ******" << endl; break;
		case 7: cout << "****** July " << year << " ******" << endl; break;
		case 8: cout << "****** August " << year << " ******" << endl; break;
		case 9: cout << "****** September " << year << " ******" << endl; break;
		case 10: cout << "****** October " << year << " ******" << endl; break;
		case 11: cout << "****** November " << year << " ******" << endl; break;
		case 12: cout << "****** December " << year << " ******" << endl; break;
	}
	
	cout << "Su  Mo  Tu  We  Th  Fr  Sa" << endl;
	
	int i; 
    for(i = 0; i < firstDay; i++){
		cout << "    "; 
	}
    for (int j = 1; j <= DaysinMonth; j++) { 
        if(j > 9){
			cout << j << "  ";
		
		}else{
			cout << "0"  << j << "  ";
		}
  
        if (++i > 6) { 
            i = 0; 
            cout << "\n"; 
        } 
    } 
  
    if (i){
    cout << "\n";
	
	}
    firstDay = i; 
	
	cout << endl;
}