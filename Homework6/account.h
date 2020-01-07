/*
Name: Jamel Douglas
Date: 4/19/2019
Section: 6
Assignment: Homework 6

All work below has been performed by Jamel Douglas
*/
#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <string>

using namespace std;
enum Type{CHECKING, SAVINGS, INVESTMENT};

class Account{
public:
    virtual ~Account();
    virtual double CurrentBal()=0;
    virtual double ProjectedBal()=0;

    const string ShowFName() const; //account owners name;
    const string ShowLName() const; //account owners name;
    const Type showType() const;
protected:
    Account();
    Account(string f_Name, string l_Name, Type t);

    string fName;
    string lName;
    Type typ;
private:

};

class Checking : public Account{
public:
    Checking();
    Checking(string f_Name, string l_Name, Type t, double curBal);

    double CurrentBal();
    double ProjectedBal();
private:
    double currentBalance;
};

class Savings : public Account{
public:
    Savings();
    Savings(string f_Name, string l_Name, Type t, double curBal, double intRate);

    double CurrentBal();
    double ProjectedBal();
private:
    double currentBalance;
    double interestRate;
};

class Investment : public Account{
public:
    Investment();
    Investment(string f_Name, string l_Name, Type t, double* e);

    double CurrentBal();
    double ProjectedBal();
private:
    double ETF[20];
};

#endif // ACCOUNT_H_INCLUDED