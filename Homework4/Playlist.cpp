/*
Name: Jamel Douglas
Date: 3/4/2019
Section: 6
Assignment: proj4

All work below has been performed by Jamel Douglas
*/

#include "Playlist.h"
#include <cstring>
#include <iostream>

using namespace std;

Playlist::Playlist(){ //creates an array of song objects


	totalDuration = 0;
	numSongs = 0;
	maxSongs = 5;
	list = new Song[maxSongs];
	memset(playlistName, '\0', 21);

}

Playlist::~Playlist(){
   delete [] list;
}

void Playlist::Add(char* t, char* a, Genre g, int d){ //add song
	list[numSongs].set(t, a,g ,d);
	numSongs++;
	totalDuration += d;
	if(numSongs == maxSongs){
        Grow();
	}
}

void Playlist::Find(char choice, char* t, char* a) const{ //find song
    if(choice == 't'){
        for(int i = 0; i < numSongs; i++){
            if(strncmp(list[i].getTitle(), t, 41) == 0){
                list[i].display();
            }
        }
    }else if(choice == 'a'){
        for(int i = 0; i < numSongs; i++){
            if(strncmp(list[i].getTitle(), a, 26) == 0){
                list[i].display();
            }
        }
    }
}

void Playlist::Rename(char* n){ //rename playlist
	memset(playlistName, '\0', 21);
	for(int i = 0; i < 21; i++){
        playlistName[i] = n[i];
	}
}

void Playlist::Remove(char* t){ //remove song
	for(int i = 0; i < numSongs; i++){
        if(strncmp(list[i].getTitle(), t, 41) == 0){
            totalDuration -= list[i].getDuration();
            for(int j = i + 1; j < numSongs; j++){
                list[j-1] = list[j];
            }
            numSongs--;
        }
    }
    if(maxSongs - numSongs > 5){
        Shrink();
    }
}

void Playlist::Grow(){
    maxSongs += 5;
    Song* nList = new Song[maxSongs];
    for(int i = 0; i < numSongs; i++){
        nList[i] = list[i];
    }
    delete [] list;
    list = nList;
    cout << "** Array resized to " << maxSongs << " allocated slots**";
}

void Playlist::Shrink(){
    maxSongs -= 5 ;
    Song* nList = new Song[maxSongs];
    for(int i = 0; i < numSongs; i++){
        nList[i] = list[i];
    }
    delete [] list;
    list = nList;
    cout << "** Array resized to " << maxSongs << " allocated slots**";
}

void Playlist::PrintPlaylist(){ //print playlist
	for(int i = 0; i < numSongs; i++){
		list[i].display();
	}
}

void Playlist::GenreSum(Genre g){ //prints a genre summary
	gTotal = 0;
	gNumSongs = 0;

	for(int i = 0; i < numSongs; i++){
		if(list[i].getGenre() == g){
           gNumSongs++;
           gTotal += list[i].getDuration();
           if(gNumSongs > 0){
                list[i].display();
                //**Work by Jamel Douglas**
           }
		}
	}
}

int Playlist::GetDuration() const{
	return totalDuration;
}

int Playlist::GetTotalSongs() const{
    return numSongs;
}

int Playlist::GetMaxSongs() const{
    return maxSongs;
}

int Playlist::G_GetTotalSongs() const{
    return gNumSongs;
}

int Playlist::G_TotalDuration() const{
    return gTotal;
}

const char* Playlist::GetPlaylistName() const{
	const char* n = playlistName;
	return n;
}