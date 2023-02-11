/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */
//Andrei Orgas - Class Section 01 - 10:30-11:45 AM
#include "pcbtable.h"
#include <vector>

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
   // TODO: add your code here
  //this->size = size; //setting my size variable to the size given for how many PCBs that are going to be in my array.
  this->table.resize(size); //we are setting the size of the vector to the size given in the parameter because that is the known number of PCBs that are going to be added.
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
   // TODO: add your code here
  //cout << "RUNNING TABLE DESTRUCTOR" << endl;
  for(auto PCB: table){ //This loop runs through all of the positions in the vector
    if(PCB)//This if statement checks if the current position contains a PCB so that we are only reallocating memory from spots that weren't empty.
      delete PCB; //reallocating the memory that the PCB is taking in the current position of the vector.
  }


  //for(int i = 0; i < 201; i++){
    //delete PCBtable[i];
    // }
  //delete[] this->PCBtable; //calling delete on an array in such a manner will go through the entire array and call the destructor for each of the PCBs.
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    // TODO: add your code here
  return table[idx]; //returns the PCB in my table at index: idx
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    // TODO: add your code here
  table[idx] = pcb; //adds a PCB to my table at the index: idx
}
