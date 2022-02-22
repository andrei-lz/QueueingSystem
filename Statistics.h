#ifndef __STATISTICS_H
#define __STATISTICS_H 1

#pragma once

struct Statistics {
	
	int fulfilled;
	int unfulfilled;
	int timedOut;
	double timeSpentWaiting;
	int timeTakenAfterClosing;

};

typedef struct Statistics STATS;


#endif /* __STATISTICS_H */