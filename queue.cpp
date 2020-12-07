/* 
queue.cpp

Author: Max Albright

Short description of this file:
constructs the Queue class, with the methods
add_to_back to add things to queue,
remove_from_front to focus on the next Location in the queue,
and is_empty for the BFS algorithm to know when the entire
queue has been looked through.

*/

#include "queue.h"

// constructor. maxlen must be as large as the total number
// of Locations that will ever be entered into this Queue.
// this is complete, you don't need to change it.
Queue::Queue(int maxlen) {
   contents = new Location[maxlen];
   head = 0;
   tail = 0;
}

// destructor. releases resources. C++ will call it automatically.
Queue::~Queue() {
   delete[] contents;
}

// insert a new Location at the end/back of our list   
void Queue::add_to_back(Location loc) {
   // FILL THIS IN
  contents[tail] = loc;
  tail++;
}

// return and "remove" the oldest Location not already extracted
Location Queue::remove_from_front() {
  return contents[head++];
}

// is this Queue empty? (did we extract everything added?)
bool Queue::is_empty() {
   return head == tail;
}

