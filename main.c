#include <stdio.h>
#include "Queue.h"
#include "Customer.h"

#define closingtime 20
#define numSim 10
#define maxQueueLength 10

int main(int argc, char** argv){

	/* Values to keep track of simulation results*/
	int fulfilled = 0;
	int unfulfilled = 0;
	int timedOut = 0;
	int timeSpentWaiting = 0;
	int timeTakenAfterClosing = 0;

	for (int i = 0; i < numSim; i++) {

		Queue* q = initQueue();
		Customer* servicepoints[5] = { NULL };

		enqueue(q, initCustomer(0, 1));
		enqueue(q, initCustomer(0, 2));
		enqueue(q, initCustomer(10, 3));
		enqueue(q, initCustomer(10, 4));
		enqueue(q, initCustomer(0, 5));
		enqueue(q, initCustomer(10, 6));
		printQueue(q);

		impatientPeopleLeave(q);

		printQueue(q);

		printf("%d left in queue", q->Count);
		exit(-1);

		/* Check for extreme inputs */
		if (sizeof(servicepoints) / sizeof(servicepoints[0]) < 1) {
			printf("Not enough service points for the simulation!");
			exit(-1);
		}

		for (int i = 0; i < closingtime; i++) {
			/*1. Zero or more fulfilled customers have finished being served and leave the system.
			2. A service point that is not serving a customer will start to serve the next available customer,
			and that customer will leave the queue.
			3. If a customer in the queue has reached their waiting tolerance limit, then they leave the queue
			and become a timed - out customer.
			4. Zero or more customers arrive into the system, and either join the back of the queue, or , if the
			queue is full, leave the system as an unfulfilled customer.*/

			printQueue(q);

			/*1*/
			for (int i = 0; i < sizeof(servicepoints) / sizeof(servicepoints[0]); i++) {
				if (servicepoints[i]) {

					servicepoints[i]->servingTime--;

					if (servicepoints[i]->servingTime == 0) {
						free(servicepoints[i]);
						servicepoints[i] = NULL;

						/* Record Statistics */
						fulfilled++;
					}
				}
				else {
					/*2*/
					if (q->Head) {
						Customer* nextInLine = dequeue(q);
						servicepoints[i] = nextInLine;
						/* Record Statistic */
						timeSpentWaiting += nextInLine->startingPatience - nextInLine->patienceLevel;
					}
				}
				if (servicepoints[i]) {
					printf("[ Patience: %d ServingTime: %d ]", servicepoints[i]->patienceLevel, servicepoints[i]->servingTime);
				}
				else {
					printf("[ TEMPORARILY EMPTY ]");
				}
			}
			printf("\n\n");

			/* 3 */
			if (q->Count > 0) {
				//unfulfilled += removeFromQueue(q); dEpRecAtEd
			}

			printQueue(q);

			/* 4 */
			int newCustomers = 1; /*Random Amount*/
			for (int i = 0; i < newCustomers; i++) {
				enqueue(q, initCustomer(30, 4));
			}

		}

		// After simulation is completed
		while (q->Count > 0) {

			printQueue(q);

			/*1*/
			for (int i = 0; i < sizeof(servicepoints) / sizeof(servicepoints[0]); i++) {
				if (servicepoints[i]) {

					servicepoints[i]->servingTime--;

					if (servicepoints[i]->servingTime == 0) {
						free(servicepoints[i]);
						servicepoints[i] = NULL;
					}
				}
				else {
					/*2*/
					if (q->Head) {
						Customer* nextInLine = dequeue(q);
						servicepoints[i] = nextInLine;
						/* Record Statistic */

						timeSpentWaiting += nextInLine->startingPatience - nextInLine->patienceLevel;
					}
				}
				if (servicepoints[i]) {
					printf("[ Patience: %d ServingTime: %d ]", servicepoints[i]->patienceLevel, servicepoints[i]->servingTime);
				}
				else {
					printf("[ TEMPORARILY EMPTY ]");
				}
			}
			printf("\n\n");

			/*3*/
			//unfulfilled += removeFromQueue(q);
		}
		printf("Stats: \n Time taken to service all after simulation: %d", timeTakenAfterClosing);

		/* Clean up the queue */
		free(q);
	}

	/* Calculating Averages */
	fulfilled /= numSim;
	unfulfilled /= numSim;
	timedOut /= numSim;
	timeTakenAfterClosing /= numSim;

	printf("\n-----\n\n Avg Fulfilled: %d | Avg Unfulfilled: %d | Avg Timed Out: %d | Avg. Time Taken After Closing: %d", fulfilled, unfulfilled, timedOut, timeTakenAfterClosing);

	return 0;
}