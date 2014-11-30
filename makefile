#
# Specifiy the target
all:	fly

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
fly:	Program3.o Flight.o Trip.o
	g++  Program3.o Flight.o Trip.o -o fly

# Specify how the object files should be created from source files
Program3.o:	Program3.cpp 
	g++ -c -g Program3.cpp

Trip.o:	Trip.cpp Trip.h
	g++ -c -g Trip.cpp

Flight.o:	Flight.cpp Flight.h
	g++ -c -g Flight.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o fly *~

