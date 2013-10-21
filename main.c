/*******************************************
  * Author: C2C John Miller
  * Created: 16 Oct 2013
  * Description: Takes in a stream of integers
  * and takes a moving average of those numbers.
  * Supports any sample size, however, requires
  * that the user input the size of the stream
*******************************************/

#include <msp430.h> 
#include "moving_averages.h"

#define SAMPLE_SIZE_1 2
#define SAMPLE_SIZE_2 4

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	int stream1[] = { 45, 42, 41, 40, 43, 45, 46, 47, 49, 45 };
	int stream2[] = { 174, 162, 149, 85, 130, 149, 153, 164, 169, 173 };

	int stream1avg_1[10];
	int stream2avg_1[10];
	int stream1avg_2[10];
	int stream2avg_2[10];

	int i;
	int max_1=0;
	int min_1=0;
	int range_1=0;

	//initialized arrays for averaging
	int TwoSampleArray[] = { 0, 0 };
	int FourSampleArray[] = { 0, 0, 0, 0 };

	int TwoSampleArray2[] = { 0, 0 };
	int FourSampleArray2[] = { 0, 0, 0, 0 };

	//averaging the first stream
	for (i = 0; i < 10; i++) {
		addSample(stream1[i], TwoSampleArray, SAMPLE_SIZE_1);
		stream1avg_1[i] = getAverage(TwoSampleArray, SAMPLE_SIZE_1);

		addSample(stream1[i], FourSampleArray, SAMPLE_SIZE_2);
		stream1avg_2[i] = getAverage(FourSampleArray, SAMPLE_SIZE_2);

	}

	//averaging the second stream
	for (i = 0; i < 10; i++) {
		addSample(stream2[i], TwoSampleArray2, SAMPLE_SIZE_1);
		stream2avg_1[i] = getAverage(TwoSampleArray2, SAMPLE_SIZE_1);

		addSample(stream2[i], FourSampleArray2, SAMPLE_SIZE_2);
		stream2avg_2[i] = getAverage(FourSampleArray2, SAMPLE_SIZE_2);

	}

	max_1 = max(stream1, 10);
	min_1 = min(stream1, 10);
	range_1 = range(stream1, 10);

	return 0;
}
