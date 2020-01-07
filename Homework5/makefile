#Name: Jamel Douglas
#Date: 3/4/2019
#Section: 6
#Assignment: proj4

#All work below has been performed by Jamel Douglas

proj5: proj5.o matrix.o
	g++ proj5.o matrix.o -o proj5
	rm -f *.o

proj5.o: proj5.cpp matrix.h
	g++ -c proj5.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

clean:
	rm -f proj5 *.o