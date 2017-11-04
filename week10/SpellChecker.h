#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <iostream>
#include <string>

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

  private:
    char start_marker;
    char end_marker;
}
