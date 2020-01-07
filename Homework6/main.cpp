/*
Name: Jamel Douglas
Date: 4/19/2019
Section: 6
Assignment: Homework 6

All work below has been performed by Jamel Douglas
*/
#include "portfolio.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void Menu(){
    cout << "*** Portfolio Management menu ***\n";
    cout << "I Import accounts from a file\n";
    cout << "S Show accounts (brief)\n";
    cout << "E Export a banking report (to file)\n";
    cout << "M Show this menu\n";
    cout << "Q Quit program\n";

}

int main(){
    char select;
    Portfolio p;
    char f[30];

    Menu();
    cout << endl;
    do{
        cout << "Selection: ";
        cin >> select;

        if(select == 'I' || select == 'i'){
            bool fail;
            cout << "***Account Importing***\n";
            cout << "Enter file name: ";
            cin >> f;

            fail = p.importFile(f);
            if(fail == true){
                cout << "Import Successful!" << endl;
            }else if(fail == false){
                cout << "Import Failed." << endl;
            }
            cout << endl;
            memset(f, '\0', 30);
        }else if(select == 'S' || select == 's'){
            cout << "***Show accounts***\n";
            p.showAccounts();
            //show account
            cout << endl;
        }else if(select == 'E' || select == 'e'){
            bool fail;
            cout << "***Export banking report***\n";
            cout << "Enter file name: ";
            cin >> f;

            fail = p.createReportFile(f);
            if(fail == true){
                cout << "Export Successful!" << endl;
            }else if(fail == false){
                cout << "Export Failed." << endl;
            }
            cout << endl;
            memset(f, '\0', 30);
        }else if(select == 'M' || select == 'm'){
            Menu();
            cout << endl;
        }else if(select == 'Q' || select == 'q'){
            cout << "Quitting\n";
            exit(0);
        }else{
            cout << "Invalid Menu Selection! Try again\n";
        }
    }while(select != 'Q' || select != 'q');


    return 0;
}
