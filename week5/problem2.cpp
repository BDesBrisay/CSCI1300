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

/*
[-10.0]
  Incorrect Answer. First difference near character 60.
  Expected Output: The wind chill is -37.94 degrees F for an airtemperature of -8.63 degrees F and a wind speed of 31.00 mph. ,
  Your Output: The wind chill is -37.94 degrees F for an airtemperature of -8.63 degreed F and a wind speed of 31.0 mph.
  The wind chill is -38.29 degrees F for an airtemperature of -8.63 degreed F and a wind speed of 32.0 mph.
[-10.0]
  Incorrect Answer. First difference near character 61.
  Expected Output: The wind chill is -36.39 degrees F for an airtemperature of -11.81 degrees F and a wind speed of 18.00 mph.
    The wind chill is -36.67 degrees F for an airtemperature of -11.81 degrees F and a wind speed of 18.50 mph.
    The wind chill is -36.95 degrees F for an airtemperature of -11.81 degrees F and a wind speed of 19.00 mph.
    The wind chill is -37.22 degrees F for an airtemperature of -11.81 degrees F and a wind speed of 19.50 mph.
    The wind chill is -37.49 degrees F for an airtemperature of -11.81 degrees F and a wind speed of 20.00 mph. ,
  Your Output: The wind chill is -36.39 degrees F for an airtemperature of -11.81 degreed F and a wind speed of 18.0 mph.
    The wind chill is -36.95 degrees F for an airtemperature of -11.81 degreed F and a wind speed of 19.0 mph.
    The wind chill is -37.49 degrees F for an airtemperature of -11.81 degreed F and a wind speed of 20.0 mph.
[-10.0]
  Incorrect Answer. First difference near character 18.
  Expected Output: The wind chill is -45.92 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 17.92 mph.
    The wind chill is -46.05 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 18.12 mph.
    The wind chill is -46.17 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 18.32 mph.
    The wind chill is -46.29 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 18.52 mph.
    The wind chill is -46.41 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 18.72 mph.
    The wind chill is -46.53 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 18.92 mph.
    The wind chill is -46.65 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 19.12 mph.
    The wind chill is -46.77 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 19.32 mph.
    The wind chill is -46.88 degrees F for an airtemperature of -19.18 degrees F and a wind speed of 19.52 mph. ,
  Your Output: The wind chill is -45.34 degrees F for an airtemperature of -19.18 degreed F and a wind speed of 17.0 mph.
    The wind chill is -45.97 degrees F for an airtemperature of -19.18 degreed F and a wind speed of 18.0 mph.
    The wind chill is -46.58 degrees F for an airtemperature of -19.18 degreed F and a wind speed of 19.0 mph.
*/
