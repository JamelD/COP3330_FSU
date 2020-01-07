/*
Name: Jamel Douglas
Date: 4/19/2019
Section: 6
Assignment: Homework 6

All work below has been performed by Jamel Douglas
*/

#include "account.h"
#include <iostream>
#include <cstring>

using namespace std;
//***********************************************************************************
//      BASE CLASS: Account
//***********************************************************************************
Account::Account(){
    //fName = " ";
    //lName = " ";
}

Account::Account(string f_Name, string l_Name, Type t){
    fName = f_Name;
    lName = l_Name;
    typ = t;
}

Account::~Account(){

}

const string Account::ShowFName() const{
    return fName;
}
const string Account::ShowLName() const{
    return lName;
}
const Type Account::showType() const{
    return typ;
}

//***********************************************************************************
//      Derived CLASS: Checking
//***********************************************************************************
Checking::Checking(){
    currentBalance = 0;
}

Checking::Checking(string f_Name, string l_Name, Type t, double curBal):Account(f_Name, l_Name, t){
    currentBalance = curBal;
}

double Checking::CurrentBal(){
    return currentBalance;
}

double Checking::ProjectedBal(){
    double proj = currentBalance + 0.1;
    return proj;
}

//***********************************************************************************
//      Derived CLASS: Savings
//***********************************************************************************
Savings::Savings(){
    currentBalance = 0;
    interestRate = 0;
}

Savings::Savings(string f_Name, string l_Name, Type t, double curBal, double intRate):Account(f_Name, l_Name, t){
    currentBalance = curBal;
    interestRate = intRate;
}

double Savings::CurrentBal(){
    return currentBalance;
}

double Savings::ProjectedBal(){
    double proj = currentBalance * (1 + interestRate);
    return proj;
}

//***********************************************************************************
//      Derived CLASS: Investment
//***********************************************************************************
Investment::Investment(){
    for(int i = 0; i < 20; i++){
        ETF[i] = 0;
    }
}

Investment::Investment(string f_Name, string l_Name, Type t, double* e):Account(f_Name, l_Name, t){
    for(int i = 0; i < 20; i++){
        ETF[i] = e[i];
    }
}

double Investment::CurrentBal(){
    double curbal;
    curbal = ETF[0] + ETF[4] + ETF[8] + ETF[12] + ETF[16];
    return curbal;
}

double Investment::ProjectedBal(){
    //double a = 0.0, ivs = 0.0, cvs = 0.0, in = 0.0;
    double cv = 0.0, div = 0.0, pro = 0.0;

    double cv1 = ((ETF[0] / ETF[1]) * ETF[2]);
    double cv2 = ((ETF[4] / ETF[5]) * ETF[6]);
    double cv3 = ((ETF[8] / ETF[9]) * ETF[10]);
    double cv4 = ((ETF[12] / ETF[13]) * ETF[14]);
    double cv5 = ((ETF[16] / ETF[17]) * ETF[18]);

    double div1 = ETF[0] * ETF[3];
    double div2 = ETF[4] * ETF[7];
    double div3 = ETF[8] * ETF[11];
    double div4 = ETF[12] * ETF[15];
    double div5 = ETF[16] * ETF[19];

    cv = cv1 + cv2 + cv3 + cv4 + cv5;
    div = div1 + div2 + div3 + div4 + div5;
    pro = (cv + div);

    //cv += (a / ivs) * cvs;
    //div = i * a;

    return pro;
}