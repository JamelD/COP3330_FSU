/*
Name: Jamel Douglas
Date: 4/5/2019
Section: 6
Assignment: Homework 5

All work below has been performed by Jamel Douglas
*/
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>

using namespace std;


class Matrix{
public:
    //Constructor, Copy Constructor, Destructor.
    Matrix(unsigned int r=5, unsigned int c=5, unsigned int value=0);
    Matrix(const Matrix& m); //copy constructor
    ~Matrix();

    //accessor functions
    int numofrows() const;
    int numofcols() const;

    //Changing data functions
    int get(unsigned int r, unsigned int c) const;
    bool set(unsigned int r, unsigned int c, unsigned int value);

    //Functions for reformatting data.
    void torowmajor();
    void tocolumnmajor();
    void printinternal() const;
    Matrix transpose() const;

    //overloaded operators
    void operator=(Matrix& m);
    Matrix operator+(Matrix& m);
    //Matrix operator*(Matrix& m) const;

    friend ostream& operator<<(ostream &out, const Matrix& m);


private:
    int row, column;
    int major;
    int* mat; //pointer for dynamic array
};

#endif // MATRIX_H_INCLUDED