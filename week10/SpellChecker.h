/*
Author: Bryce DesBrisay
Recitation: 210 Arcadia
Assignment 7 - SpellChecker.h
*/

#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class SpellChecker {
  public:
    SpellChecker();
    SpellChecker(string language);
    SpellChecker(string language, string firstName, string secondName);
    ~SpellChecker();

    string language;

    bool readValidWords(string fileName);
    bool readCorrectedWords(string fileName);
    bool setStartMarker(char begin);
    bool setEndMarker(char end);
    char getStartMarker();
    char getEndMarker();
    string repair(string sentence);

    void split(string str, string del, string array[]);
    int search(string target, string array[], int size);
    int search2D(string target, string array[][2], int size);

  private:
    char start_marker;
    char end_marker;
    string validWords[10000];
    string correctedWords[10000][10000];
};
#endif // SPELL_CHECKER_H
