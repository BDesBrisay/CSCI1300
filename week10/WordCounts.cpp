/*
Author: Bryce DesBrisay
Recitation: 210 Arcadia
Assignment 7 - WordCounts.cpp
*/

#include "WordCounts.h"

//constructor
WordCounts::WordCounts() {
}

//destructor
WordCounts::~WordCounts() {
}

// counts word in sentence
void WordCounts::tallyWords(string sentence) {
    string normalized = stripPunct(sentence);
    string token;
    stringstream ss(normalized);
    while (ss >> token) {
      int index = search(token, words, 9999);
      if (index != -1) {
        counts[index] += 1;
      }
      for (int i = 0; i < 9999; i++) {
        if (words[i].empty()) {
          words[i] = token;
          counts[i] = 1;
          i = 9999;
        }
      }
    }
}


// gets tallies for given word
int WordCounts::getTally(string word) {
  for (int i = 0; i < 9999; i++) {
    if (word == words[i]) {
      return counts[i];
    }
  }
  return 0;
}


// Resets all word counts to 0
void WordCounts::resetTally() {
  for (int i = 0; i < 1000; i++) {
    counts[i] = 0;
  }
}


// sorts arrays and finds which word has the highest countand returns the count
int WordCounts::mostTimes(string newWords[], int newCounts[], int n) {
    sort(counts, words, 1000);
    for (int i = 0; i < n; i++) {
        newWords[i] = words[i];
        newCounts[i] = counts[i];
    }
    return counts[0];
}

// bubble sort to sort through array
void WordCounts::sort(int newCounts[], string newWords[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size - 1; j++) {
      if(newCounts[j] < newCounts[j + 1]) {
        int tempCount = newCounts[j];
        string tempWord = newWords[j];

        newCounts[j] = newCounts[j + 1];
        newWords[j] = newWords[j + 1];

        newCounts[j + 1] = tempCount;
        newWords[j + 1] = tempWord;
      }
    }
  }
}


// strips punctuation and case from a string
string WordCounts::stripPunct(string sentence) {
  string noPunctStr = "";

  for (int i = 0; i < sentence.length(); i++) {
    if (isupper(sentence[i])) {
      noPunctStr += tolower(sentence[i]);
    } else {
      bool isPunct = false;
      if (ispunct(sentence[i]) && (i == 0 || i + 1 == sentence.length() || sentence[i + 1] == ' ' || sentence[i - 1] == ' ')) {
        isPunct = true;
      }
      if (!isPunct) {
        noPunctStr += sentence[i];
      }
    }
  }

  return noPunctStr;
}

//finds target value in array and returns index
int WordCounts::search(string target, string array[], int size) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      return i;
      break;
    }
  }
  return -1;
}
