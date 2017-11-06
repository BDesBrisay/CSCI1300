/*
Author: Bryce DesBrisay
Recitation: 210 Arcadia
Assignment 7 - WordCounts.h
*/

#ifndef WORD_COUNTS_H
#define WORD_COUNTS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

class WordCounts {
  public:
    WordCounts();
    ~WordCounts();

    void tallyWords(string);
    int getTally(string word);
    void resetTally();
    int mostTimes(string[], int[], int);

  private:
    string lowerNoPunctuation(string, string);
    void sort(int counts[], string words[], int size);
    int search(string target, string array[], int size);
    string stripPunct(string sentence);

    string words[10000];
    int counts[10000];
};
#endif // WORD_COUNTS_H
