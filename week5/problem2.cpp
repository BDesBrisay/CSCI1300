#include <iostream>
#include <math.h>

using namespace std;

// Author: Bryce DesBrisay
// Recitation: 210 Arcadia
//
// Assignment 3
// Problem 2

/*
Calculates wind chill by plugging parameters T and V in to this equation:
35.74 + (0.6215 * T) - (35.75 * V^0.16) + (0.4275 * T * V^0.16)
Then it returns this value.
*/

float windChillCalculator(float T, float V) {
  return 35.74 + (0.6215 * T) - (35.75 * pow(V, 0.16)) + (0.4275 * T * pow(V, 0.16));
}

/*
Takes air temperatire, low and high wind speeds, and a increment
Prints out a line with the calculated wind chill of these numbers
And the numbers that were used
*/

void printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step) {
  for(float i = low_wind_speed; i <= high_wind_speed; i = i + wind_speed_step) {
    cout << "The wind chill is " << windChillCalculator(T, i) << " degrees F for an airtemperature of " << T << " degrees F and a wind speed of "<< i << " mph."<<endl;
  }
}

int main() {
  float T;
  float V;
  cout<<"Enter an air temperature: "<<endl;
  cin >> T;
  cout<<"Enter a wind speed: "<<endl;
  cin >> V;
  cout<<"The wind chill is "<<windChillCalculator(T, V)<<" degrees F."<<endl;
  printWindChill(30.0, 5.0, 8.0, 1.0);
}
