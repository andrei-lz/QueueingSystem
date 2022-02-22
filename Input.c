#include "Input.h"

extern Input* readFile(char* fileName, Input* input, FILE outputFile) {

	char buffer[150];
	FILE* inputFile = NULL;
	
	if ((inputFile = fopen(fileName, "r")) == NULL) {
		printf("Input File Not Found / Can't Be Accessed");
		exit(-1);
	}
	else {

		while (!feof(inputFile)) {
			fgets(buffer, 100, inputFile);

			if (buffer[0] != '#' && strlen(buffer) > 1) {
				sscanf(buffer, "maxQueueLength %d", &(input->maxQueueLength));
				sscanf(buffer, "numServicePoints %d", &(input->numServicePoints));
				sscanf(buffer, "closingTime %d", &(input->closingTime));
				sscanf(buffer, "averageNewCustomersPerInterval %d", &(input->averageNewCustomersPerInterval));
			}

		}

		if (input->maxQueueLength == 0) {
			printf("Parameter maxQueueLength not found");
		}
		if (input->numServicePoints == 0) {
			printf("Parameter numServicePoints not found");
		}
		if (input->closingTime == 0) {
			printf("Parameter closingTime not found");
		}
		if (input->averageNewCustomersPerInterval == 0) {
			printf("Parameter averageNewCustomersPerInterval not found");
		}

		fprintf("--------- Parameters read from %s ---------");
		fprintf("maxQueueLength: %d", input->maxQueueLength);
		fprintf("numServicePoints %d", input->numServicePoints);
		fprintf("closingTime %d", input->closingTime);
		fprintf("averageNewCustomersPerLine %d", input->averageNewCustomersPerInterval);

		fclose(inputFile);
		return input;
	}

}