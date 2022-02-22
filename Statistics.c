#include "Statistics.h"
#pragma once

extern STATS* initStats() {
	STATS* s = (STATS*)calloc(1, sizeof(STATS));
	s->fulfilled = 0;
	s->unfulfilled = 0;
	s->timedOut = 0;
	s->timeSpentWaiting = 0;
	s->timeTakenAfterClosing = 0;
	return s;
}