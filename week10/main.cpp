/*
Author: Bryce DesBrisay
Recitation: 210 Arcadia
Assignment 7 - Main File
*/

#include <iostream>
#include "SpellChecker.h"
#include "WordCounts.h"

using namespace std;

int main() {

  SpellChecker spellCheck("English", "VALID_WORDS_3000.txt", "MISSPELLED.txt");

  spellCheck.setStartMarker('~');
  spellCheck.setEndMarker('~');

  cout << spellCheck.repair("todayy") << endl;
  cout << spellCheck.repair("one! two three bankrot") << endl;
  cout << spellCheck.repair("asdf asdf!asdf") << endl;
  cout << spellCheck.repair("teh world is basicly flat!") << endl;
  cout << spellCheck.repair("Teh brown asdhf jumped.") << endl;


  WordCounts wordCounts;

  wordCounts.tallyWords("The quick brown fox jumped over the lazy dog!");
  wordCounts.tallyWords("The dog then jumped over fourteen chickens.");

  cout << wordCounts.getTally("the") << endl;
  cout << wordCounts.getTally("quick") << endl;
  cout << wordCounts.getTally("dog") << endl;
  cout << wordCounts.getTally("over") << endl;
  cout << wordCounts.getTally("fourteen") << endl;

  string words[7];
  int counts[7];

  cout << "Most Times: " << wordCounts.mostTimes(words, counts, 7) << endl;

  for (int i = 0; i < 7; i++) {
      if (!words[i].empty()) cout << words[i] << ", " << counts[i] << endl;
  }

  wordCounts.resetTally();

  cout << wordCounts.getTally("fox") << endl;

  return 0;
}
