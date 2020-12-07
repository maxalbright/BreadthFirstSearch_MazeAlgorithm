/* 
mazeio.cpp

Author: Max Albright

Short description of this file:
This file reads the maze of a given file, returns Null if the
first two numbers aren't valid, allocates an array for the maze
 and returns it. The second function prints the maze properly.
*/

#include <iostream>
#include <fstream>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Reads the maze from the given filename into a 
 *  2D dynamically  allocated array.
 * 
 * Returns the pointer to that array.
 * Returns NULL (a special address) if there is a problem
 * opening the file or reading in the integer sizes.
 *
 * The first argument is the filename of the maze input.
 *************************************************/

char** read_maze(char* filename, int* rows, int* cols) 
{
  ifstream inputfile(filename);
  if (inputfile.fail()) {
    return NULL;
  }
  inputfile >> (*rows);
  if (inputfile.fail()) {
    return NULL;
  }
  inputfile >> (*cols);
  if (inputfile.fail()) {
    return NULL;
  }

  //allocate memory
  char** inputmaze = new char* [*rows];
  for (int i =0; i < *rows; i++) {
    char* column = new char[*cols];
    inputmaze[i] = column;
  }
  //fill the 2D array
  for (int rindex=0; rindex < *rows; rindex++) {
    for (int cindex=0; cindex < *cols; cindex++) {
      inputfile >> inputmaze[rindex][cindex];
			if (inputmaze[rindex][cindex] != '.' && 
					inputmaze[rindex][cindex] != '#' && 
					inputmaze[rindex][cindex] != 'S' && 
					inputmaze[rindex][cindex] != 'F') {
				return NULL;
			}
    }
  }

  return inputmaze;
}

/*************************************************
 * Prints the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/

void print_maze(char** maze, int rows, int cols) 
{
	cout << rows << " " << cols << endl;
	for (int rindex=0; rindex < rows; rindex++) {
		for (int cindex=0; cindex < cols; cindex++){
			cout << maze[rindex][cindex];
		}
		cout << endl;
	}
}

