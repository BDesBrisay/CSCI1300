// Author: Bryce DesBrisay - CSCI 1300 Fall 2017
// Recitation: 210 - Arcadia
//
// Assignment 2

#include <iostream>

using namespace std;

// Calculating population change in a year

int howMany(int population) {
  int seconds = 60 * 60 * 24 * 365;
  population += seconds / 8;
  population -= seconds / 12;
  population += seconds / 33;
  return population;
}

// Sorting seconds into days, hours, minutes and seconds

void howLong(int seconds) {
  if(seconds < 0) {
    seconds = 0;
  }
  int dayCount = seconds / (60 * 60 * 24);
  seconds = seconds % (60 * 60 *24);
  int hourCount = seconds / (60 * 60);
  seconds = seconds % (60 * 60);
  int minuteCount = seconds / 60;
  seconds = seconds % 60;
  cout<<"Time is "<<dayCount<<" days, "<<hourCount<<" hours, "<<minuteCount<<" minutes, and "<<seconds<<" seconds."<<endl;
}

// Converting Celsius to Fahrenheit

int howHot(int celsius) {
  int fahrenheit = 1.8 * celsius + 32;
  return fahrenheit;
}

int main() {
  cout<<howMany(1000000)<<endl;
  howLong(70000);
  cout<<howHot(20)<<endl;
}
