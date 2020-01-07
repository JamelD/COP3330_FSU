#Name: Jamel Douglas
#Date: 3/4/2019
#Section: 6
#Assignment: proj4

#All work below has been performed by Jamel Douglas

proj4: menu.o Playlist.o Song.o
	g++ menu.o Playlist.o Song.o -o proj4
	rm -f *.o

menu.o: menu.cpp Playlist.h Song.h
	g++ -c menu.cpp

Playlist.o: Playlist.cpp Playlist.h Song.h
	g++ -c Playlist.cpp

entry.o: Song.cpp Song.h
	g++ -c Song.cpp

clean:
	rm -f proj4 *.o