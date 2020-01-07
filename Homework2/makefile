#Name: Jamel Douglas
#Date: 1/30/2019
#Section: 6
#Assignment: prog2

#All work below has been performed by Jamel Douglas

appname := prog2

CXX := g++
CXXFLAGS := -Wall -g -O3 

srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	    $(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	    rm -f ./.depend
		    $(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	    rm -f $(objects) $(appname)

dist-clean: clean
	   rm -f *~ .depend *.o

include .depend
