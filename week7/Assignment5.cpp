#include <iostream>
#include <math.h>
using namespace std;

float sumArray(float array[], int size) {
  float sum = 0;
  for(int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

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

float calculateDifference(int a[], int b[], int size) {
  float diffSquare[size];
  for(int i = 0; i < size; i++) {
    diffSquare[i] = pow(a[i] - b[i], 2);
  }
  return sumArray(diffSquare, size);
}

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

void copyArray(float source[], int size, float dest[]) {
  for(int i = 0; i < size; i++) {
    dest[i] = source[i];
  }
}

void convert(int rating[], string text[], int size) {
  for(int i = 0; i < size; i++) {
    if(rating[i] == 0) {
      text[i] = "Haven't read it";
    } else if(rating[i] == -5) {
      text[i] = "Hated it";
    } else if(rating[i] == -3) {
      text[i] = "Didn't like it";
    } else if(rating[i] == 1) {
      text[i] = "Ok, neither hot nor cold about it";
    } else if(rating[i] == 3) {
      text[i] = "Liked it!";
    } else if(rating[i] == 5) {
      text[i] = "Really liked it!";
    } else {
      text[i] = "INVALID";
    }
  }
}

float findMedian(float array[], int size) {
  float newArray[size];
  float median = 0;
  copyArray(array, size, newArray);
  sortArray(newArray, size);
  if(size % 2 == 1) {
    median = newArray[size / 2];
  } else {
    median = (newArray[size / 2] + newArray[size / 2 + 1]) / 2.0;
  }
  return median;
}

void simple2DMultiplication(int multiplier, int matrix[10][10]) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      matrix[i][j] = multiplier * matrix[i][j];
    }
  }
}
