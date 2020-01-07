/*
Name: Jamel Douglas
Date: 3/4/2019
Section: 6
Assignment: proj3

All work below has been performed by Jamel Douglas
*/


#include "Playlist.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>


using namespace std;

//Function Prototypes
void Menu();        //Prints Menu
void GenreMenu();   //Print menu for Genre selection
void Program();     //general code for program
void print(const char* n); //Used to print playlist name

int main(){
	Program();
	return 0;
}

void Program(){
	char selection, select; //Selection vars
	int space = 0;
	char* dummy = 0;//null char pointer
	Playlist p;

	char plName[21];//for taking in playlist name
	memset(plName, '\0', 21);//set memory to null

	char title[41], artist[26], ty;//for taking in title, artist, or type selection
	memset(title, '\0', 41);//clear title and artist strings for later use
	memset(artist, '\0', 26);

	Genre type; //for conversion from selection to type
	int duration; //for taking in the duration in seconds

	int hours = 0, minutes = 0;//time conversion

	do{
        cout << endl << "Enter a Playlist Name: ";
        cin >> plName;//User Inputs playlist title

        space = 0;
        for(int i = 0; i < 21; i++){
            if(plName[i] == ' '){
                space++;
            }
        }
        if(space > 4){
            cout << "Invalid entry, Try again!";
        }
	}while(space > 4);
    p.Rename(plName); //used to insert playlist title into object
	cout << endl;

	memset(plName, '\0', 21); //clear string for later use

	Menu();
	do{
		cout << "Selection(Press M for Menu): ";
		cin >> selection;

		if(selection == 'A' || selection == 'a'){ //Add Song
			cout << "Title: ";
			cin >> title; //user enters title

			cout << "Artist: ";
			cin >> artist;//user enters artist

			GenreMenu();
			cout << "Genre(Select the letter): ";
			cin >> ty;//user selects title
			if(ty == 'C' || ty == 'c'){
				type = COUNTRY;
			}else if(ty == 'E' || ty == 'e'){
				type = EDM;
			}else if(ty == 'P' || ty == 'p'){
				type = POP;
			}else if(ty == 'R' || ty == 'r'){
				type = ROCK;
			}else if(ty == 'B' || ty == 'b'){
				type = RB;
			}
			while(ty != 'C' && ty != 'c' && ty != 'E' && ty != 'e' && ty != 'P'
				&& ty != 'p' && ty != 'R' && ty != 'r' && ty != 'B' && ty != 'b'){

				//Error Checking (Must select from genre menu)
				cout << "Invalid Entry. \n Try Again: ";
				cin >> ty;
			}

			cout << "Duration(in seconds): " ;
			cin >> duration; //user enters duration
			while(duration < 0){
				//Error Checlking (duration can only be negative)
				cout << "Duration must be positive! \nTry again: ";
				cin >> duration;
			}

			p.Add(title, artist, type, duration); //adding data to song object in playlist

			//clear title and artist strings for later use
			memset(title, '\0', 41);
			memset(artist, '\0', 26);
			cout << endl;

		}else if(selection == 'F' || selection == 'f'){//Find Song
			cout << "\nSearch by Title(T) or Artist(A)\nT or A: ";
			cin >> select;
			if(select == 't' || select == 'T'){
                cout << "Title: ";
                cin >> title;

                p.Find(select, title, dummy);

			}else if(select == 'a' || select == 'A'){
                cout << "Artist: ";
                cin >> artist;

                p.Find(select, dummy, artist);
			}

			//clear title and artist strings for later use
			memset(title, '\0', 41);
			memset(artist, '\0', 26);
            cout << endl;
		}else if(selection == 'R' || selection == 'r'){//Rename Playlist
            do{
                cout << endl << "Rename the Playlist: ";
                cin >> plName;
                space = 0;
                for(int i = 0; i < 21; i++){
                    if(plName[i] == ' '){
                        space++;
                    }
                }
                if(space > 4){
                    cout << "Invalid entry, Try again!";
                }
            }while(space > 4);
			p.Rename(plName);

			memset(plName, '\0', 21); //clear string for later use
            cout << endl;
		}else if(selection == 'S' || selection == 's'){// remove song
			memset(title, '\0', 41);

			cout << "Type the name of a song to remove\n";
			cout << "Title: ";
            cin >> title;
			p.Remove(title);

			memset(title, '\0', 41);
            cout << endl;
		}else if(selection == 'D' || selection == 'd'){ // Print playlist
			hours = p.GetDuration() / 60;
			minutes = p.GetDuration() % 60;
			cout << endl << "Playlist Name: " ;
			print(p.GetPlaylistName());
			cout << endl;
			if(p.GetTotalSongs() > 0){
                p.PrintPlaylist();
                cout << endl;
                cout << "Total Songs: " << p.GetTotalSongs();
                if(minutes < 10){
                    cout << "\nTotal Duration: " << hours << ":0" << minutes;
                    cout << endl << endl;
                }else{
                    cout << "\nTotal Duration: " << hours << ":" << minutes;
                    cout << endl << endl;
                }
			}else{
			    //**Work by Jamel Douglas**
                cout << endl;
                cout << "There are no songs in this playlist";
                cout << endl << endl;
			}

		}else if(selection == 'G' || selection == 'g'){ //prints genre summary
			cout << endl;
			GenreMenu();
			cout << "Select Genre to search: ";
			cin >> ty;
			if(ty == 'C' || ty == 'c'){
				type = COUNTRY;
			}else if(ty == 'E' || ty == 'e'){
				type = EDM;
			}else if(ty == 'P' || ty == 'p'){
				type = POP;
			}else if(ty == 'R' || ty == 'r'){
				type = ROCK;
			}else if(ty == 'B' || ty == 'b'){
				type = RB;
			}else{

			}
			while(ty != 'C' && ty != 'c' && ty != 'E' && ty != 'e' && ty != 'P'
				&& ty != 'p' && ty != 'R' && ty != 'r' && ty != 'B' && ty != 'b'){

				//Error Checking (Must select from genre menu)
				cout << "Invalid Entry. \n Try Again: ";
				cin >> ty;
				cout << endl;
			}
			if(p.G_GetTotalSongs() <= 0){
                p.GenreSum(type);
                cout << "\nTotal Songs: " << p.G_GetTotalSongs();
                cout << "\nTotal Duration: " <<p.G_TotalDuration();
			}else{
                cout << "There are no songs with this genre!\n";
			}

            cout << endl;

		}else if(selection == 'M' || selection == 'm'){//Show menu
			Menu();
			cout << endl;

		}else if(selection == 'Q' || selection == 'q'){ //quit
			cout << "\nShutting Down!" << endl << endl;
			if(minutes < 10){
                cout << "Your playlist was " << hours << ":0" << minutes << "long!\n\n";
			}else{
                cout << "Your playlist was " << hours << ":" << minutes << "long!\n\n";
			}
			cout << "Exiting Program!\n\n";
			exit(0);
		}else{
            cout << "Invalid Selection!\n";
		}
	}while(selection != 'Q' || selection != 'q');
}

void print(const char* n){
    for(int i = 0; i < 21; i++){
        if(n[i] > 32 && n[i] < 127){
                cout << n[i];
        }
    }
}

void Menu(){
	cout << "\nA: Add a song to the playlist" << endl;
	cout << "F: Find a song in the playlist" << endl;
	cout << "R: Rename playlist" << endl;
	cout << "S: Remove a song" << endl;
	cout << "D: Display the playlist" << endl;
	cout << "G: Genre summary" << endl;
	cout << "M: Show this Menu" << endl;
	cout << "Q: Quit/exit the program" << endl;
}

void GenreMenu(){
	cout << "Select music Genre" << endl;
	cout << "C. Country" << endl;
	cout << "E. EDM" << endl;
	cout << "P. Pop" << endl;
	cout << "R. Rock" << endl;
	cout << "B. R&B" << endl;
}
