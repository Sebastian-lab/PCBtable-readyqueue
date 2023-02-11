#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code
//Andrew Orgas -Class Section 01-10:30-11:45 AM

/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
     //TODO: add your code here
   Size = 0; //sets the size of the readyqueue to 0 because no PCBs have been added yet.
   for(int i = 0; i < 201;i++){ //looping through the array to make sure that it is insilized
     queue[i] = NULL;
   } 
 }
/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
  pcbPtr->setState(ProcState::READY); //First we set the state of the PCB to READY because it is now part of the readyqueue
  queue[Size] = pcbPtr; //We add the PCB to the end of the queue because we will search for priority when we remove
  Size++; //increase size, because we just added a new PCB to the queue.
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
  if(Size == 0){
    return NULL;
  }
  PCB *temp; //where we are going to store the lowest PCB while we are over writting it in the array
  int lowest_pos = 0; //starting lowest position at 0 because that is the start of the queue 
  for(int i = 1; i < Size; i++){ //loop through to find the position with the lowest priority
    if(queue[lowest_pos]->getPriority() < queue[i]->getPriority()){ //compares the current positions priority to the lowest positions priority
      lowest_pos = i; //updates lowest position to the new location
    }
  }

  temp = queue[lowest_pos]; //storing the PCB that is being removed while over writting it in the array.

  for(int j = lowest_pos; j < Size-1;j++){ //looping through the overwritting the PCB we are removing.
    queue[j] = queue[j+1];
  }

  temp->setState(ProcState::RUNNING); //setting the state of the PCB that I am removing to running
  //temp->display();
  queue[Size-1] = NULL;
  Size--; //We have to decrease Size by one because we are taking out a PCB;
  return temp; //returns the PCB after its state has been changed to running
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    //TODO: add your code here
  return Size; //returns the size by using the premade variable that I defined in the class
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    //TODO: add your code here
  //loops through all of the PCBs in the array and calls the predifined display function on them.
  for(int i = 0; i < Size; i++){
    queue[i]->display();
  }
}
