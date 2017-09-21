#include <iostream>

using namespace std;

// Author: Bryce DesBrisay
// Recitation: 210 Arcadia
//
// Assignment 3
// Problem 1


/*
The first story gets various words from the user with "cin >> [variable]"
Then it prints out the story with those variables in place
*/

void story1(void) {
  string noun;
  string occupation;
  string animal;
  string place;
  cout<<"Enter a plural noun: "<<endl;
  cin >> noun;
  cout<<"Enter an occupation: "<<endl;
  cin >> occupation;
  cout<<"Enter an animal name: "<<endl;
  cin >> animal;
  cout<<"Enter a place: "<<endl;
  cin >> place;
  cout<<"In the book War of the "+noun+", the main character is an anonymous "+occupation+" who records the arrival of the "+animal+"s in "+place+"."<<endl;
}

/*
The second story gets various words from the user with "cin >> [variable]"
Then it prints out the story with those variables in place
*/

void story2(void) {
  string name;
  string place;
  cout<<"Enter a name: "<<endl;
  cin >> name;
  cout<<"Enter a state/country: "<<endl;
  cin >> place;
  cout<<name+", I've got a feeling we're not in "+place+" anymore."<<endl;

}

/*
The third story gets various words from the user with "cin >> [variable]"
Then it prints out the story with those variables in place
*/

void story3(void) {
  string name;
  string relative;
  string verb;
  cout<<"Enter a first name: "<<endl;
  cin >> name;
  cout<<"Enter a relative: "<<endl;
  cin >> relative;
  cout<<"Enter a verb: "<<endl;
  cin >> verb;
  cout<<"Hello. My name is "+name+". You killed my "+relative+". Prepare to "+verb+"."<<endl;
}

/*
The menu function prompts the user which story they would like to choose.
While the following input is not a "q" it checks which story it should start.
If anything else is typed in and its not a q, this displays an error.
If the input is "q" it stops and says "good bye"
*/

void menu(void) {
  string input;
  while(input != "q") {
    cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
    cin >> input;
    if(input == "1") {
      story1();
    } else if(input == "2") {
      story2();
    } else if(input == "3") {
      story3();
    } else if(input != "q") {
      cout<<"Valid choice not selected."<<endl;
    }
  }
  cout<<"good bye"<<endl;
}

// main function starts the menu function

int main() {
  menu();
}
