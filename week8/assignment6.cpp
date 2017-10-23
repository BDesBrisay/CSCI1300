#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/*
Splits a string by a deliminator and puts it in an array
*/

void split(string str, string del, string array[], int size) {
  size_t pos = 0;
  int index = 0;

  while ((pos = str.find(del)) != string::npos) {
    array[index] = str.substr(0, pos);
    str.erase(0, pos + del.length());
    index++;
  }

  array[index] = str;
}

/*
Searches each value in an array until it matches what you want it to
Returns the index of that value
*/

int search(string array[], int size, string value) {
  for (int i = 0; i < size; i++) {
    if (array[i] == value) {
      return i;
    }
  }

  return -1;
}

/*
Counts chars on each line from a file and adds them up then averages them
Returns the average
*/

float avgCharsPerLine(string filename) {
  string line;
  ifstream file (filename.c_str());
  float lineCount = 0;
  float total = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      total += line.length();
      lineCount++;
    }
    file.close();
  }

  return total / lineCount;
}

/*
Fills an array with values provided by a file
Splits string from file into floats and inserts them in the array
*/

int fillArray(string filename, float array[][5]) {
  string line;
  ifstream file (filename.c_str());
  int index = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      if (index > 0) {
        string tempArray[5];
        split(line, ",", tempArray, 5);
        for (int i = 0; i < 5; i++) {
          array[index - 1][i] = stof(tempArray[i]);
        }
      }
      index++;
    }
    file.close();
  }

  return index - 1;
}

/*
Feeds values from a file into an array
Adds up the numbers in the odd columns and rows of an array
Returns the sum of the averages for columns and rows
*/

float arrayStats(string filename, float numbers[][5]) {
  ifstream file (filename.c_str());
  string line;
  int lineCount = 0;
  float colSum = 0.0;
  float rowSum = 0.0;
  float rowMean = 0.0;
  float colMean = 0.0;
  float mean = 0.0;

  if(file.is_open()) {
    while(getline(file, line)) {
      if(lineCount > 0) {
        string tempArray[5];
        split(line, ",", tempArray, 5);
        colSum += stof(tempArray[1].c_str());
        colSum += stof(tempArray[3].c_str());
        if(lineCount % 2 == 0) {
          for(int i = 0; i < 5; i++) {
            rowSum += stof(tempArray[i].c_str());
          }
        }
      }
      lineCount++;
    }

    rowMean = rowSum / 5;
    colMean = colSum / ( lineCount - 1 );
    mean = colMean + rowMean;
  }

  return mean;
}

/*
Takes values from file and puts them in an array
Assigns the rating to the appropriate place in the ratings array
*/

void addBookRatings(string filename, string names[], int ratings[][50]) {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 50; j++) {
      ratings[i][j] = 0;
    }
  }

  ifstream file (filename);
  string line;
  int namesIndex = 0;
  int lines = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      if (lines > 0) {
        string tempArray[3];
        split(line, ",", tempArray, 3);
        int index = search(names, 100, tempArray[0]);
        int book = stoi(tempArray[1]);
        int rating = stoi(tempArray[2]);
        if (index == -1) {
          names[namesIndex] = tempArray[0];
          ratings[namesIndex][book] = rating;
          namesIndex++;
        }
        else {
          ratings[index][book] = rating;
        }
      }
      lines++;
    }
  }
}
