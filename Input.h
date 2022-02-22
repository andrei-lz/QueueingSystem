#ifndef __INPUT_H
#define __INPUT_H 1

#pragma once
#include <stdio.h>

struct InputStructure {

	int numSim;
	int maxQueueLength;
	int averageNewCustomersPerInterval;
	int closingTime;
	int numServicePoints;

};

typedef struct InputStructure Input;

extern Input* initInput();

extern Input* readParameters(char*);


#endif /* !__INPUT_H */
