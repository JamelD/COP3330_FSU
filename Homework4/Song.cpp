/*
Name: Jamel Douglas
Date: 3/4/2019
Section: 6
Assignment: proj4

All work below has been performed by Jamel Douglas
*/

#include "Song.h"
#include <iostream>
#include <iomanip>

using namespace std;

Song::Song(){
	duration = 0;
}

void Song::set(const char* t, const char* a, Genre g, int d){
	for(int i = 0; i < 41; i++){
		title[i] = t[i];
	}
	for(int i = 0; i < 26; i++){
		artist[i] = a[i];
	}
	type= g;
	duration = d;
}

const char* Song::getTitle() const{ // returns the title stored in the object
	const char* t = title;
	return t;
}

const char* Song::getArtist() const{ // returns the artist
	const char* a = artist;
	return a;
}

int Song::getDuration() const{ // returns the duration
	return duration;
}

Genre Song::getGenre() const{ // returns the genre
	return type;
}

void Song::display() const{
	//variables for calculation
	int hours = 0, minutes = 0;

	//calculation for time in minutes
	hours = duration / 60;
	minutes = duration % 60;

	//Printing to console
	cout << left << setw(43);
	cout << title << setw(28) ;
	cout << artist << right << setw(8);
	switch(type){//**Work by Jamel Douglas**
		case COUNTRY:   cout << "Country";  break;
		case EDM:       cout << "EDM";      break;
		case POP:       cout << "Pop";      break;
		case ROCK:      cout << "Rock";     break;
		case RB:        cout << "R&B";      break;
	}
	if(minutes < 10){
        cout << setw(6) << hours << ":0" << minutes;
        cout << setfill(' ') << endl;
	}else{
        cout << setw(6) << hours << ":" << minutes;
        cout << setfill(' ') << endl;
	}
}
