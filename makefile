FLAGS = -c -g -std=c++11

#
# Specifiy the target
all:	fly

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
fly:	Program3.o Time.o Flight.o Trip.o DDFS.o DepartNode.o DestNode.o
	g++  Program3.o Time.o Flight.o Trip.o DDFS.o DepartNode.o DestNode.o -o fly

# Specify how the object files should be created from source files
Program3.o:	Program3.cpp 
	g++ $(FLAGS) Program3.cpp

Time.o:	Time.cpp
	g++ $(FLAGS) Time.cpp

Trip.o:	Trip.cpp Trip.h
	g++ $(FLAGS) Trip.cpp

Flight.o:	Flight.cpp Flight.h
	g++ $(FLAGS) Flight.cpp

DDFS.o:		DDFS.cpp DDFS.h
	g++ $(FLAGS) DDFS.cpp

DepartNode.o:	DepartNode.cpp DepartNode.h
	g++ $(FLAGS) DepartNode.cpp

DestNode.o:	DestNode.cpp DestNode.h
	g++ $(FLAGS) DestNode.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o fly *~

