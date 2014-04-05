// FileIO.h
// For reading and writing to various files from within the program.

#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <string>

// Function Declarations
// Write: for writing generic data into a file specified by name
int Write(std::string filename, void* data);

// Read: for reading generic data from a file specified by name
void* Read(std::string filename);

#endif //_FILEIO_H_
