# for building and cleaning the project
	
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/Commands.cpp src/FileIO.cpp src/HelperFunctions.cpp src/Login.cpp src/main.cpp
SOURCEDIR=./src/
OBJECTS=$(SOURCES:.cpp=.o)
OBJECTDIR=./build/obj/
EXECUTABLE=run
EXECUTABLEDIR=./build/

all: $(SOURCES) $(EXECUTABLE)
	mv $(EXECUTABLE) $(EXECUTABLEDIR)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	mv $(SOURCEDIR)*.o $(OBJECTDIR)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -rf $(OBJECTDIR)*.o $(EXECUTABLEDIR)$(EXECUTABLE)
	