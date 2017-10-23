#include <iostream>
#include "assignment6.cpp"

using namespace std;

int main() {
  // avgCharsPerLine test
  cout << "Avg: " << endl;

  cout << avgCharsPerLine("part3.txt") << endl;

  cout << endl;

  // fillArray test
  cout << "Fill Array: " << endl;

  float testArray1[3][5];
  cout << fillArray("part2.txt", testArray1) << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << testArray1[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  // arrayStats test
  cout << "Array Stats" << endl;

  float testArray2[5][5];
  cout << arrayStats("part3.txt", testArray2) << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << testArray2[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  // addBookRatings test
  cout << "Ratings: " << endl;

  string names[100];
  int ratings[100][50];
  addBookRatings("part4.txt", names, ratings);
  for (int i = 0; i < 50; i++) {
    cout << names[i];
    for (int j = 0; j < 50; j++) {
      cout << ratings[i][j] << " ";
    }
    cout << endl;
  }
}
