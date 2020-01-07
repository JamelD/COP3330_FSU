/*
Name: Jamel Douglas
Date: 4/19/2019
Section: 6
Assignment: Homework 6

All work below has been performed by Jamel Douglas
*/
#ifndef PORTFOLIO_H_INCLUDED
#define PORTFOLIO_H_INCLUDED
#include "account.h"

class Portfolio{
public:
    Portfolio();
    ~Portfolio();

    bool importFile(const char* filename);
    bool createReportFile(const char* filename);
    void showAccounts();
    void Grow(int tSize);
private:
    Account** acc;
    int size;
    int si;
};


#endif // PORTFOLIO_H_INCLUDED
