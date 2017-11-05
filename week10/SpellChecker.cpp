/*
Author: Bryce DesBrisay
Recitation: 210 Arcadia
Assignment 7 - SpellChecker.cpp
*/

#include "SpellChecker.h"

// Constructor
SpellChecker::SpellChecker() {
}

// Setting the language variable as the parameter
SpellChecker::SpellChecker(string newLanguage) {
  language = newLanguage;
}

// Sets variable language to the parameter
// Reads the files with correct and misspelled words supplied by the parameters
SpellChecker::SpellChecker(string newLanguage, string correctWords, string misspelledWords) {
  language = newLanguage;

  readValidWords(correctWords);
  readCorrectedWords(misspelledWords);
}

// Destructor
SpellChecker::~SpellChecker() {
}

// Reads file line by line and writes the word into the validWords array
bool SpellChecker::readValidWords(string fileName) {
  ifstream myFile (fileName);
  string line;
  int idx = 0;

  if (myFile.is_open()) {
    while (getline(myFile, line)) {
      validWords[idx] = line;
      idx++;
    }

    myFile.close();
    return true;
  } else {
    return false;
  }
}

// Reads the file and separates the line by a tab and puts it into a tempArray
// Them it assigns the misspelled word to the first value of the 2D array correctedWords
// Then it assigns the correctly spelled word to the second value of the same row
bool SpellChecker::readCorrectedWords(string fileName) {
  ifstream myFile (fileName);
  string line;
  int idx = 0;

  if (myFile.is_open()) {
    while (getline(myFile, line)) {
      string tempArray[2];
      split(line, '\t', tempArray);
      correctedWords[idx][0] = tempArray[0];
      correctedWords[idx][1] = tempArray[1];
      idx++;
    }

    myFile.close();
    return true;
  } else {
    return false;
  }
}

// Sets the variable start_marker to the parameter char
bool SpellChecker::setStartMarker(char begin) {
  start_marker = begin;
  return true;
}

// Sets the variable end_marker to the parameter char
bool SpellChecker::setEndMarker(char end) {
  end_marker = end;
  return true;
}

// Returns variable start_marker
char SpellChecker::getStartMarker() {
  return start_marker;
}

// Returns variable end_marker
char SpellChecker::getEndMarker() {
  return end_marker;
}

string SpellChecker::repair(string sentence) {
  string repaired;
  string word;

  stringstream ss(sentence);

  while (ss >> word) {
    if(search(validWords, word, 10000) != -1) {
      repaired += word;
    } else if (search2D(correctedWords, word, 10000) != -1) {
      repaired += correctedWords[search2D(correctedWords, word, 10000)][1];
    } else {
      repaired += start_marker + word + end_marker;
    }
    repaired += " ";
  }
  return repaired;
}

// Finds a char in a string and splits it into two values in an array
void SpellChecker::split(string str, string del, string array[]) {
  size_t pos = 0;
  int index = 0;

  while ((pos = str.find(del)) != string::npos) {
    array[index] = str.substr(0, pos);
    str.erase(0, pos + del.length());
    index++;
  }

  array[index] = str;
}

// Searches a given array for a given value and returns the index
int SpellChecker::search(string target, string array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int SpellChecker::search2D(string target, string array[][2], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i][0] == target) {
            return i;
        }
    }
    return -1;
}
