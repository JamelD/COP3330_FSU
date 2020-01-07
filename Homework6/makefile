#Name: Jamel Douglas
#Date: 4/19/2019
#Section: 6
#Assignment: proj6

#All work below has been performed by Jamel Douglas

proj6: main.o portfolio.o account.o
	g++ main.o portfolio.o account.o -o proj4
	rm -f *.o

main.o: main.cpp portfolio.h account.h
	g++ -c main.cpp

portfolio.o: portfolio.cpp portfolio.h account.h
	g++ -c portfolio.cpp

song.o: account.cpp account.h
	g++ -c account.cpp

clean:
	rm -f proj4 *.o