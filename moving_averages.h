/*******************************************
  * Author: C2C John Miller
  * Created: 16 Oct 2013
  * Description: Header file for the moving
  * averages program. Contains the functions
  * getAverage, addSample, min, max, and range
*******************************************/

#ifndef MOVING_AVERAGES_H_
#define MOVING_AVERAGES_H_

// Moving average functions
int getAverage(int array[], unsigned int arrayLength);
void addSample(int sample, int array[], unsigned int arrayLength);

// Array functions
int max(int array[], unsigned int arrayLength);
int min(int array[], unsigned int arrayLength);
unsigned int range(int array[], unsigned int arrayLength);

#endif /* MOVING_AVERAGES_H_ */
