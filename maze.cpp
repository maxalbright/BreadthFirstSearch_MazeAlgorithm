/* 
maze.cpp

Author: Max Albright

Short description of this file:
The main function ensures user input is valid, calls the read_maze function,
calls the BFS and backtracking algorithm (maze_search), prints the resulting 
maze, and deallocates memory.

*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"


using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);
void deallocate(bool**, Location**, int);


// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows;
   int cols;
   int result;
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
   mymaze = read_maze(argv[1], &rows,  &cols); // FILL THIS IN
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect." << endl;
      return 1;
   }

   result = maze_search(mymaze, rows, cols); 

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // delete all memory 
   // that read_maze allocated
   for (int i=0; i< rows; i++) {
      delete[] mymaze[i];

   }
   delete [] mymaze;
   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
  Queue q(rows * cols);
	bool** queue_attendance = new bool*[rows];
  Location** predecessor = new Location*[rows];
  int neighbor_array[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  
	Location start;
	int numSs = 0, numFs = 0;
  
  // This loop finds the start and adds it to the 
  // queue. if there is an invalid number of Ss and Fs, it returns -1
  for (int rindex=0; rindex < rows; rindex++) {
    queue_attendance[rindex] = new bool[cols];
    predecessor[rindex] = new Location[cols];
    for (int cindex=0; cindex < cols; cindex++) {
			queue_attendance[rindex][cindex] = false;
      if (maze[rindex][cindex] == 'S') {
				numSs++;
				if (numSs > 1) {
          deallocate(queue_attendance, predecessor, rows);
					return -1;
				}
        start.row = rindex;
        start.col = cindex;
        q.add_to_back(start);
				queue_attendance[start.row][start.col] = true;
      }
			else if (maze[rindex][cindex] == 'F') {
				numFs++;
				if (numFs > 1) {
          deallocate(queue_attendance, predecessor, rows);
					return -1;
				}
			}
    }
  }
	if (numSs == 0 || numFs == 0) {
    deallocate(queue_attendance, predecessor, rows);
		return -1;
	}
	
	
  // BFS and backtracking algorithm
  while (!q.is_empty()) {
    Location loc = q.remove_from_front();
    for (int i=0; i < 4; i++) {
      int nrindex = loc.row + neighbor_array[i][0];
      int ncindex = loc.col + neighbor_array[i][1];
      
      // does not analyze this neighbor if it's out of bounds
      if (ncindex < 0 || nrindex < 0 || ncindex >= cols ||
          nrindex >= rows) {
        continue;
      }
      // if the finish is reached, the route is backtracked with astericks
      // and the function returns 1
      if(maze[nrindex][ncindex] == 'F') {
        while (!(loc.row == start.row && loc.col == start.col)) {
          maze[loc.row][loc.col] = '*';
          loc = predecessor[loc.row][loc.col];
        }
        deallocate(queue_attendance, predecessor, rows);
        return 1;
      }
      // if a neighbor cell is unexplored and a viable path, it is added to 
      // the queue and the value of the cell by which this neighbor was found
      // becomes the value of this neighbor's cell in the predecessor array
      if (maze[nrindex][ncindex] == '.' 
          && !queue_attendance[nrindex][ncindex]) {
        Location neighbor;
        neighbor.row = nrindex;
        neighbor.col = ncindex;					
        q.add_to_back(neighbor);
        queue_attendance[nrindex][ncindex] = true;
        predecessor[nrindex][ncindex] = loc;
      }
    }
  }
  // if a value hasn't been returned by now, it means the finish wasn't reached

  deallocate(queue_attendance, predecessor, rows);
  return 0;
}

void deallocate(bool**queue_attendance, Location**predecessor, int rows) {
  for (int i=0; i< rows; i++) {
    delete[] predecessor[i];
    delete[] queue_attendance[i];
  }
  delete[] predecessor;
  delete[] queue_attendance;  
}