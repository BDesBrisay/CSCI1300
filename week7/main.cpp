#include <iostream>
#include "Assignment5.cpp"
using namespace std;

int main() {
  float a[] = {1.1, 1.8, 1.3, 1.4, 1.5};
  int b[] = {1,2,3,4};
  int c[] = {3,4,5,6};
  float d[5];
  int rating[] = { -5, -3, -1, 0, 1, 3, 5, 7};
  string text[8];
  int matrix[10][10] = {
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0},
    {1,2,3,4,5,6,7,8,9,0}
  };
  sumArray(a, 5);
  search(b, 4, 3);
  calculateDifference(b, c, 4);
  sortArray(a, 5);
  copyArray(a, 5, d);
  convert(rating, text, 8);
  findMedian(a, 5);
  simple2DMultiplication(2, matrix);
}
