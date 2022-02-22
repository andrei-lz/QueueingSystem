/*
Customer Header File

Contains the data struct for the attributes that each Client posesses
*/

#ifndef __CUSTOMER_H
#define __CUSTOMER_H 1

#pragma once

#include <stdlib.h>
#include <stdio.h>

struct QueueNode
{
	int startingPatience;
	int patienceLevel;
	int servingTime;
	struct QueueNode* nextNode;
	struct QueueNode* previousNode;
};

typedef struct QueueNode Customer;

extern Customer* initCustomer(int, int);

#endif /* !__CUSTOMER_H */
