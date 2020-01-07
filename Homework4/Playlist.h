/*
Name: Jamel Douglas
Date: 3/4/2019
Section: 6
Assignment: proj4

All work below has been performed by Jamel Douglas
*/

#ifndef __PLAYLIST_H
#define __PLAYLIST_H

#include "Song.h"

class Playlist{
	public:
		//Constructors/Destructors
		Playlist();
		~Playlist();

		//data edititing member functions
		void Add(char* t, char* a, Genre g, int d);
		void Find(char choice, char* t, char* a) const;
		void Rename(char* n);
		void Remove(char* n);

		//data printing member functions
		void PrintPlaylist();
		void GenreSum(Genre g);

		//accessor functions
		int GetDuration() const;
		int GetTotalSongs() const;
		int GetMaxSongs() const;
		int G_GetTotalSongs() const;
		int G_TotalDuration() const;
		const char* GetPlaylistName() const;

	private: //**Work by Jamel Douglas**
		Song* list; //pointer for array of song objects
		char playlistName[21]; //name of playlist
		int numSongs, maxSongs, totalDuration;
		int gNumSongs, gTotal;
		void Grow();
		void Shrink();

};

#endif
