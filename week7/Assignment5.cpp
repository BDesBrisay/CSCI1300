/*
Author: Bryce DesBrisay
Recitation: 210 Arcadia
Assignment 5 - Assignment5.cpp
*/

#include <iostream>
#include <math.h>
using namespace std;

/*
This functions adds the values of an array up by running through each element of
the array and adding it to the returned variable sum
*/

float sumArray(float array[], int size) {
  float sum = 0;
  for(int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

/*
This function finds the index where a target value in the array is by running
through each element in the array and comparing it to the target value
*/

int search(int array[], int size, int target) {
  int targetIndex = -1;
  for(int i = 0; i < size; i++) {
    if(array[i] == target) {
      targetIndex = i;
      break;
    }
  }
  return targetIndex;
}

/*
This function calculates the difference between the values of two arrays and
squares them. Then it sums all the squared values up ad returns it
*/

float calculateDifference(int a[], int b[], int size) {
  float diffSquare[size];
  for(int i = 0; i < size; i++) {
    diffSquare[i] = pow(a[i] - b[i], 2);
  }
  return sumArray(diffSquare, size);
}

/*
This function sorts an array by using the bubble sort method and comparing one
to the next and if the first value was larger, it switches the two. Then it moves
on to the next value and does the same until it has run through the array completely
*/

void sortArray(float unsortedArray[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size - 1; j++) {
      if(unsortedArray[j] > unsortedArray[j + 1]) {
        int temp = unsortedArray[j];
        unsortedArray[j] = unsortedArray[j + 1];
        unsortedArray[j + 1] = temp;
      }
    }
  }
}

/*
This function runs through each value of a given array and copies it to a
different array
*/

void copyArray(float source[], int size, float dest[]) {
  for(int i = 0; i < size; i++) {
    dest[i] = source[i];
  }
}

/*
This function takes in an array with ratings and converts the number rating to
a text rating
*/

void convert(int rating[], string text[], int size) {
  for(int i = 0; i < size; i++) {
    if(rating[i] == 0) {
      text[i] = "Not-read";
    } else if(rating[i] == -5) {
      text[i] = "Terrible";
    } else if(rating[i] == -3) {
      text[i] = "Disliked";
    } else if(rating[i] == 1) {
      text[i] = "Average";
    } else if(rating[i] == 3) {
      text[i] = "Good";
    } else if(rating[i] == 5) {
      text[i] = "Really liked it!";
    } else {
      text[i] = "INVALID";
    }
  }
}

/*
This function finds the median number of an array by copying it into another
array and sorting the copy so you dont modify the original array. Then it is
checking if the array is even or odd because for evens you just take the value at
the index of the middle of the array, while for odds you have to average the two
middle numbers to get the index.
*/

float findMedian(float array[], int size) {
  float newArray[size];
  float median = 0;
  copyArray(array, size, newArray);
  sortArray(newArray, size);
  if(size % 2) {
    median = newArray[(size / 2)];
  } else {
    median = (newArray[size / 2] + newArray[(size / 2) - 1]) / 2.0;
  }
  return median;
}

/*
This function multiplies each number of a multidimensional array by a supplied
multiplier.
*/

void simple2DMultiplication(int multiplier, int matrix[10][10]) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      matrix[i][j] = multiplier * matrix[i][j];
    }
  }
}
