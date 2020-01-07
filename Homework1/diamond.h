/*
Name: Jamel Douglas
Date: 1/30/2019
Section: 6
Assignment: prog1 

All work below has been performed by Jamel Douglas
*/

#ifndef __DIAMOND_H
#define __DIAMOND_H


class Diamond{
	public:
		Diamond(int, char = 35, char = 42);
		//Diamond(int);
		
		
		int GetSize(); //Get user inputed size
		
		int Perimeter(); //Returns perimeter of diamond
		double Area(); //Returns area of diaomond
		
		void Grow(); //makes diamond increase by one
		void Shrink(); //makes diamond decrease by one
		void SetBorder(char); //changes border char
		void SetFill(char); //changes fill char
		
		void Draw(); //Draws diamond
		void Summary(); //summary of diamond info
	
	private:
		int size; //size of side for diamond
		char border, fill; //border and fill chars for diamond
};

#endif