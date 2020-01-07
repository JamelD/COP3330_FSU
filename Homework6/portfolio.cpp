/*
Name: Jamel Douglas
Date: 4/19/2019
Section: 6
Assignment: Homework 6

All work below has been performed by Jamel Douglas
*/
#include "portfolio.h"
#include "account.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

Portfolio::Portfolio(){
    size = 0;
	si = 10;
    acc = new Account*[si];
}

Portfolio::~Portfolio(){
    if(acc != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            delete acc[i];
            acc[i] = NULL;
        }
        delete[] acc;
        acc = NULL;
    }
}

bool Portfolio::importFile(const char* filename){
    ifstream file;
    int tSize;
    string FName, LName;
    char TYPE[10];
    double curBal, intrate, ET[20];
    double* ETF = ET;
    file.open(filename);
    if(file){
        file >> tSize;
        file.ignore();//cleanup for getline
        if(si == size + tSize){
                Grow(tSize);
            }
        for(int i = 0; i < tSize; i++){
            FName.clear();
            LName.clear();
            memset(TYPE, '\0', 10);

            getline(file, LName, ',');
            file.ignore();
            getline(file, FName);

            file >> TYPE;
            if(strncmp(TYPE, "Savings", 10) == 0){
                file >> curBal >> intrate;
                acc[size] = new Savings(FName, LName, SAVINGS, curBal, intrate);
                size++;
            }else if(strncmp(TYPE, "Checking", 10) == 0){
                file >> curBal;
                acc[size] = new Checking(FName, LName, CHECKING, curBal);
                size++;
            }else if(strncmp(TYPE, "Investment", 10) == 0){
                for(int j = 0; j < 20; j++){
                    file >> ETF[j];
                }
                acc[size] = new Investment(FName, LName, INVESTMENT, ETF);
                size++;
            }else{
                exit(-1); //error
            }
            file.ignore();
        }
        file.close();
        return true;
    }else if(!file){
        file.close();
        return false;
    }else{
        return false;
        exit(-1);//error
    }
}

bool Portfolio::createReportFile(const char* filename){
    ofstream fout;
    string name;
    double savT = 0.0, cheT = 0.0, invT = 0.0;
    int sav = 0, che = 0, inv = 0;

    fout.open(filename);
    if(fout){
        fout << "Banking Summary\n";
        fout << "-------------------\n";

        fout << "Savings Accounts\n";
        fout << "----------------------------------------------------------------------------\n";
        fout << setw(40) << left << "Holder";
        fout << setw(17) << right <<"Current Balance";
        fout << setw(20) << right << "Projected Balance\n";
        for(int i = 0; i < size; i++){
            if(acc[i]->showType() == SAVINGS){
                name = acc[i]->ShowFName() + " " + acc[i]->ShowLName();
                fout << left << setw(40) << name << right;
                fout << right << setw(17) << fixed << showpoint << setprecision(2) << acc[i]->CurrentBal();
                fout << right << setw(19) << fixed << showpoint << setprecision(2) << acc[i]->ProjectedBal();
                fout << endl;
                sav++;
                savT += acc[i]->ProjectedBal();
            }
        }
        fout << endl;

        fout << "Checking Accounts\n";
        fout << "----------------------------------------------------------------------------\n";
        fout << setw(40) << left << "Holder";
        fout << setw(17) << right <<"Current Balance";
        fout << setw(20) << right << "Projected Balance\n";
        for(int i = 0; i < size; i++){
            if(acc[i]->showType() == CHECKING){
                //if(i != 0){cout << " ";}
                name = acc[i]->ShowFName() + " " + acc[i]->ShowLName();
                fout << left << setw(40) << name << right;
                fout << right << setw(17) << fixed << showpoint << setprecision(2) << acc[i]->CurrentBal();
                fout << right << setw(19) << fixed << showpoint << setprecision(2) << acc[i]->ProjectedBal();
                fout << endl;
                che++;
                cheT += acc[i]->ProjectedBal();
            }
        }
        fout << endl;

        fout << "Investment Accounts\n";
        fout << "----------------------------------------------------------------------------\n";
        fout << setw(40) << left << "Holder";
        fout << setw(17) << right <<"Current Balance";
        fout << setw(20) << right << "Projected Balance\n";
        for(int i = 0; i < size; i++){
            if(acc[i]->showType() == INVESTMENT){
                name = acc[i]->ShowFName() + " " + acc[i]->ShowLName();
                fout << left << setw(40) << name << right;
                fout << right << setw(17) << fixed << showpoint << setprecision(2) << acc[i]->CurrentBal();
                fout << right << setw(19) << fixed << showpoint << setprecision(2) << acc[i]->ProjectedBal();
                fout << endl;
                inv++;
                invT += acc[i]->ProjectedBal();
            }
        }
        fout << endl;

        fout << "Overall Account distribution\n\n";
        fout << left << setw(15) << "Savings:" << setw(5) << sav << "-   " << right << setw(5) << savT/sav << endl;
        fout << left << setw(15) << "Checking:" << setw(5) << che << "-   " << right << setw(5) << cheT/che << endl;
        fout << left << setw(15) << "Investment:" << setw(5) << inv << "-   " << right << setw(5) << invT/inv << endl;

        fout.close();
        return true;
    }else if(!fout){
        fout.close();
        return false;
    }else{
        return false;
        exit(-1);//error
    }
}

void Portfolio::showAccounts(){

    cout << setw(22) << left <<  "Last Name";
    cout << setw(22) << "First Name";
    cout << setw(16) << "Type";
    cout << setw(10) << right << "Balance\n\n";
    for(int i = 0; i < size; i++){
        //if(i != 0){cout << " ";}
        cout << setw(22) << left << acc[i]->ShowLName();
        cout << setw(22) << acc[i]->ShowFName();
        cout << setw(15) << left;
        if(acc[i]->showType() == 0){
            cout << "Checking";
        }else if(acc[i]->showType() == 1){
            cout << "Savings";
        }else if(acc[i]->showType() == 2){
            cout << "Investment";
        }else{
            exit(-1); //error
        }
        cout << fixed << showpoint << setprecision(2);
        cout << setw(9) << right << acc[i]->CurrentBal() << endl;
    }
    cout << endl;
}

void Portfolio::Grow(int tSize){
    int grow = tSize + size;
    Account** newn = new Account*[grow];
    for(int i = 0; i < grow; i++){
        newn[i] = acc[i];
    }
    if(acc != NULL){
        for (int i = 0; i < size; i++){
            delete acc[i];
            acc[i] = NULL;
        }
        delete[] acc;
        acc = newn;
    }
}
