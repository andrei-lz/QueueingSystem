/*
Implements the prototype functions defined in Customer.h
*/

#include "Customer.h"

extern Customer* initCustomer(int patienceLevel, int servingTime) {
	Customer* newCustomer = (Customer*)calloc(1, sizeof(Customer));
	if (newCustomer == NULL)
	{
		printf("Could not allocate memory for the customer");
		exit(-1);
	}
	newCustomer->startingPatience = patienceLevel;
	newCustomer->patienceLevel = patienceLevel;
	newCustomer->servingTime = servingTime;
	newCustomer->nextNode = NULL;
	newCustomer->previousNode = NULL;
	return newCustomer;
}