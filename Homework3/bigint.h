/*
Name: Jamel Douglas
Date: 3/4/2019
Section: 6
Assignment: proj3 

All work below has been performed by Jamel Douglas
*/

#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;

class bigint{
	public:
		// I/O Operator Overload
		bigint();
		bigint(int x0);
		bigint(int x0, int x1);
		bigint(int x0, int x1, int x2);
		bigint(int x0, int x1, int x2, int x3);
		bigint(int x0, int x1, int x2, int x3, int x4);
		
		//Arithmetic Operator Overload
		friend bigint operator+(const bigint& b1, const bigint& b2);
		friend bigint operator+(const bigint& b1, int b2);
		friend bigint operator-(const bigint& b1, const bigint& b2);
		friend bigint operator-(const bigint& b1, int b2);
		
		// I/O Operator Overload
		friend istream& operator>>(istream &in, bigint& b1);
		friend ostream& operator<<(ostream &out, const bigint& b1);
		
		//Comparison Operator Overload
		friend bool operator<(const bigint& b1, const bigint& b2);
		friend bool operator>(const bigint& b1, const bigint& b2);
		friend bool operator<=(const bigint& b1, const bigint& b2);
		friend bool operator>=(const bigint& b1, const bigint& b2);
		friend bool operator==(const bigint& b1, const bigint& b2);
		friend bool operator!=(const bigint& b1, const bigint& b2);
		
		
		
		//
		
	private:
		int v[5];
};
#endif 