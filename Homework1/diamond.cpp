/*
Name: Jamel Douglas
Date: 1/30/2019
Section: 6
Assignment: prog1 

All work below has been performed by Jamel Douglas
*/
#include <iostream>
#include "diamond.h"
using namespace std;

Diamond::Diamond(int s, char b, char f){
	size = s;
	if(s < 1){
		size = 1;
	}else if(size > 39){
		size = 39;
	}else{
		//size = s;
	}
	
	if(border >= 33 && border <= 126){
		border = '#';
	}else{
		border = b;
	}
	
	if(border >= 33 && border <= 126){
		fill = '*';
	}else{
		fill = f;
	}
}

int Diamond::GetSize(){
	int ss = size;
	return ss;
}

int Diamond::Perimeter(){
	int peri = size + size + size + size;
	return peri;
}

double Diamond::Area(){
	int ar = size * size;
	return ar;
}

void Diamond::Grow(){
	int ss = size;
	if(ss + 1 < 39 && ss + 1 > 1){
		size++;
	}
}

void Diamond::Shrink(){
	int ss = size;
	if(ss - 1 < 39 && ss - 1 > 1){
		size--;
	}
}

void Diamond::SetBorder(char b){
	border = b;
}

void Diamond::SetFill(char f){
	fill = f;
}

void Diamond::Draw(){
	int multiplier = 2;
    int base = 4;
	int ss = size;
	for(int i = 1; i <= ss; i++){
		for(int sp = 0; sp <= ss - i; sp++){
            cout << " ";
        }
		if(i > 1){
         cout << border;
		}
		if(i > 1){
			for(int b = base; b <= i * multiplier; b++){
				cout << fill;
			}
		}
		cout << border;
        cout << endl;
	}
	int space = 1;
	for(int i = 1; i <= ss; i++){
		for(int sp = 1; sp < space ; sp++){
            cout << " ";
        }
		space++;
		if(i <= ss){
         cout << border;
		}
		if(i < ss){
			for(int b = 1; b <= multiplier * (ss - i) - 1; b++){
				cout << fill;
			}
		}
		cout << border;
        cout << endl;
	}
	cout << endl;

}

void Diamond::Summary(){
	cout << "Side Length: " << GetSize() << endl;
	cout << "Perimeter: " << Perimeter() << endl;
	cout << "Area: " << Area() << endl << endl;
}
	