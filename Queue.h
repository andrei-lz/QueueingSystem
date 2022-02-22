/*
Queue Header File

*/

#ifndef __QUEUE_H
#define __QUEUE_H 1

#pragma once

#include <stdbool.h>
#include <malloc.h>
#include "Customer.h"

struct QueueStruct {
	int Count;
	Customer* Head;
	Customer* Tail;
};

typedef struct QueueStruct Queue;

/* Declaring function prototypes for linking*/

/*
Function: initQueue()
------------------------
 Declares a new queue, allocates memory for its contents and initialises the struct variables.
 Memory is initialised with zeroes as placeholders until data is stored (hence calloc)

 @returns: The newly created Queue
*/
extern Queue* initQueue();

/*
Function: peekNext(Customer*)
-------------------------
Parameters: Takes in a Customer with a "nextNode" pointer

@returns: The customer that the parameter points to, i.e. the next customer in the queue
without removing them from the data structure like dequeue()
*/
static Customer* peekNext(Customer*);
//Removes customers with patience level 0 from the queue

/*
* @return Returns customer to be disposed of later
*/
extern int removeNode(Queue*, Customer*);


extern int impatientPeopleLeave(Queue*);
//Checks if the queue is empty
extern bool isEmpty(Queue*);
//Add another customer to the queue
extern void enqueue(Queue*, Customer*);
//Removes the front customer from the queue
extern Customer* dequeue(Queue*);
//Prints queue to console
extern void printQueue(Queue*);

#endif /* !__QUEUE_H */