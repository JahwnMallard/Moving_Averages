/*******************************************
  * Author: C2C John Miller
  * Created: 16 Oct 2013
  * Description: Header file for the moving
  * averages program. Contains the functions
  * getAverage, addSample, min, max, and range
*******************************************/

#include "moving_averages.h";

//returns the average of the array
int getAverage(int array[], unsigned int arrayLength) {
	int sum = 0;
	int i;

	for ( i = 0; i < arrayLength; i++) {
		sum += array[i];
	}

	return sum / arrayLength;
}

//shifts out the value at index 0, moves everything down 1 index. It then moves in the sample value at the last index
void addSample(int sample, int array[], unsigned int arrayLength) {
	int i;

	for ( i = 1; i < arrayLength; i++) {
		array[i - 1] = array[i];
	}

	array[arrayLength - 1] = sample;
}

//compares the values in the array against each other and returns the largest value
int max(int array[], unsigned int arrayLength) {
	int i;
	int max = 0;

	for ( i = 0; i < arrayLength; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	return max;
}

//compares the values in the array against each other and returns the smallest value
int min(int array[], unsigned int arrayLength) {
	//initial value for comparison
	int min = array[0];
	int i;

	for ( i = 1; i < arrayLength; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}

	return min;
}

//Essentially runs the min and max functions and returns the difference.
unsigned int range(int array[], unsigned int arrayLength) {
	int max = 0;
	int min = array[0];
	int i;

	for ( i = 0; i < arrayLength; i++) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}

	return max-min;
}
