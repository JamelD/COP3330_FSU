/*
Name: Jamel Douglas
Date: 4/5/2019
Section: 6
Assignment: Homework 5

All work below has been performed by Jamel Douglas
*/
#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Constructor, Copy Constructor, and Destructor
Matrix::Matrix(unsigned int r, unsigned int c, unsigned int value){
    major = 0; //set to row major, which is default for c++
    row = r;
    column = c;
    int sized = r * c;
    mat = new int[sized];
    for(int i = 0; i < sized; i++){ //for loop to input values
        mat[i]= value;
    }
}

Matrix::Matrix(const Matrix& m){
    row = m.row;
    column = m.column;
    major = m.major;
    int sized = row * column;
    mat = new int[sized]; //create new array
    for(int i = 0; i < sized; i++){
        mat[i] = m.mat[i]; //copy data from one array to another
    }
}

Matrix::~Matrix(){
    delete [] mat; //DATA CLEANUP
}

//accessor functions
int Matrix::numofrows() const{
    return row;
}

int Matrix::numofcols() const{
    return column;
}

//Functions to change or find values in the matrix
int Matrix::get(unsigned int r, unsigned int c) const{
    unsigned int rr = row, cc = column; //to remove  comparison error
    int search = 0;
    if(r <= rr){ //user input check
        if(c <= cc){ //user input check
            if(major == 0){
                if(row == 1){
                    search = ((column * r) - (column - c));
                    return mat[search];
                }else if(row > 1){
                    search = ((column * r) - (column - c + 1));
                    return mat[search];
                }else{
                    return -1;
                }
            }else if(major == 1){
                if(column == 1){
                    search = ((row * c) - (row - r));
                    return mat[search];
                }else if(column > 1){
                    search = ((row * c) - (row - r + 1));
                    return mat[search];
                }else{
                    return -1;
                }
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

bool Matrix::set(unsigned int r, unsigned int c, unsigned int value){
    int search = 0;
    unsigned int rr = row, cc = column; //to remove  comparison error
    if(r <= rr){//user input check
        if(c <= cc){//user input check
            if(major == 0){
                if(row == 1){
                    search = ((column * r) - (column - c));
                    mat[search] = value;
                    return true;
                }else if(row > 1){
                    search = ((column * r) - (column - c + 1));
                    mat[search] = value;
                    return true;
                }else{
                    return false;
                }
            }else if(major == 1){
                if(column == 1){
                    search = ((row * c) - (row - r));
                    mat[search] = value;
                    return true;
                }else if(column > 1){
                    search = ((row * c) - (row - r + 1));
                    mat[search] = value;
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

//Functions to change data layout
void Matrix::torowmajor(){
    int* tem; //pointer for temporary data storage array
    if(major == 0){
        //do nothing, matrix is already row majored
    }else if(major == 1){
        int sized = row * column;

        tem = new int[sized]; //create place for data after swap
        for (int i = 0; i < column; ++i){
            for (int j = 0; j < row; ++j){
                tem[j * column + i] = mat[i * row + j]; //SWAP
            }
        }

        delete [] mat;//CLEANUP old data
        mat = tem; //set class pointer equal to temp pointer
        major = 0; //change major
    }else{
        exit(-1);//error
    }
}

void Matrix::tocolumnmajor(){
    int* tem;//pointer for temporary data storage array
    if(major == 1){
        //do nothing, Matrix already column major.
    }else if(major == 0){
        int sized = row * column;

        tem = new int[sized];//create place for data after swap
        for (int i = 0; i < column; ++i){
            for (int j = 0; j < row; ++j){
                tem[i * row + j] = mat[j * column + i];//SWAP
            }
        }

        delete [] mat;//CLEANUP old data
        mat = tem;//set class pointer equal to temp pointer
        major = 1;//change major
    }else{
        exit(-1);//error
    }
}

//function prints internal data
void Matrix::printinternal() const{
    int mSize = column * row;
    for(int i = 0; i < mSize; i++){
        cout << mat[i] << " ";
    }
    cout << endl;
}

Matrix Matrix::transpose() const{
    Matrix a;
    a.column = row;
    a.row = column;
    a.major = major;

    if(major == 0){
        int sized = row * column;

        delete [] a.mat; //cleanup data from creating matrix
        a.mat = new int[sized]; //create space of correct size
        for(int i = 0; i < column; ++i){
            for(int j = 0; j < row; ++j){
                a.mat[i * row + j] = mat[j * column + i];//Swaps data by major but does not change major to get full effect
            }
        }
    }else if(major == 1){
        int sized = row * column;

        delete [] a.mat;
        a.mat = new int[sized];
        for(int i = 0; i < column; ++i){
            for(int j = 0; j < row; ++j){
                a.mat[j * column + i] = mat[i * row + j];
            }
        }
    }else{
        exit(-1);//error
    }
    return a;
}

//Operator overloads (to make work with class)
void Matrix::operator=(Matrix& m){
    row = m.row;
    column = m.column;
    major = m.major;
    int sized = row * column;
    delete [] mat; //cleanup old data
    mat = new int[sized];
    for(int i = 0; i < sized; i++){
        mat[i] = m.mat[i];//set values equal
    }

}

Matrix Matrix::operator+(Matrix& m){
    Matrix a;
    int size = row * column;
    if(row == m.row){
        if(column == m.column){
            if(major == 0 && m.major == 0){
                a.row = row;
                a.column = column;
                a.major = major;
                for(int i = 0; i < size; i++){
                    a.mat[i] = mat[i] + m.mat[i];
                }
            }else if(major == 1 && m.major == 1){
                a.row = row;
                a.column = column;
                a.major = major;
                for(int i = 0; i < size; i++){
                    a.mat[i] = mat[i] + m.mat[i];
                }
            }else{
                //convert data to same major to add
                if(major == 1 && m.major == 0){
                    this->torowmajor();
                    a.row = row;
                    a.column = column;
                    a.major = major;
                    for(int i = 0; i < size; i++){
                        a.mat[i] = mat[i] + m.mat[i];
                    }
                    this->tocolumnmajor();
                }else if(major == 0 && m.major == 1){
                    m.torowmajor();
                    a.row = row;
                    a.column = column;
                    a.major = major;
                    for(int i = 0; i < size; i++){
                        a.mat[i] = mat[i] + m.mat[i];
                    }
                    m.tocolumnmajor();
                }else{
                    exit(-1);//error
                }
            }
        }else{
            Matrix d(row, column, 0);
            a = d;
        }
    }else{
        Matrix d(row, column, 0);
        a = d;
    }
    return a;
}

//Matrix Matrix::operator*(Matrix& m) const{
//    Matrix a;
//    int size = row * column;
//    if(row == m.row){
//        if(column == m.column){
//            a.row = row;
//            a.column = column;
//            a.major = major;
//            for(int i = 0; i < size; i++){
//                a.mat[i] = mat[i] * m.mat[i];
//            }
//        }
//    }
//    return a;
//}

//Friend Function. Output operator overload.
ostream& operator<<(ostream &out, const Matrix& m){
    int counter = 0;
    if(m.major == 0){
        int mSize = m.column * m.row;
        counter = 0;
        for(int i = 0; i < mSize; i++){
            out << setw(2) << m.mat[i] << "    ";
            counter++;
            if(counter == m.column){
                out <<  endl;
                counter = 0;
            }
        }
    }else if(m.major == 1){
        int mSize = m.column * m.row;
        counter = 0;

        for(int i = 0; i < m.row; i++){
            for(int j = i; j < mSize; j += m.row){
                out << setw(2) << m.mat[j] << "    ";
                counter++;
                if(counter == m.column){
                    out <<  endl;
                    counter = 0;
                }
            }
        }
    }else{

    }
    return out;
}