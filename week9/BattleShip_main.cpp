#include <iostream>
#include "BattleShip.h"
#include "BattleShip.cpp"

using namespace std;

int main(){
	//TODO: Declare 3 instances of the battleship class: Destroyer Carrier Cruiser

	BattleShip BSOne("Destroyer");
	cout << BSOne.getShipName() << endl;
	BattleShip BSTwo("Carrier");
	cout << BSTwo.getShipName() << endl;
	BattleShip BSThree("Cruiser");
	cout << BSThree.getShipName() << endl;

	//TOD0: Give the ships a size: Destroyer-3 Carrier-5 Cruiser-2
	// you will need to call the appropriate methods

	BSOne.setSize(3);
	BSTwo.setSize(5);
	BSThree.setSize(2);
	cout << BSOne.getSize() << endl;
	cout << BSTwo.getSize() << endl;
	cout << BSThree.getSize() << endl;


	// Once you have this running for one, expand this while loop to include the other
	// two instances. Have the while loop end when all three ships have been sunk
	while(BSOne.isSunk() == false || BSTwo.isSunk() == false || BSThree.isSunk() == false){
		if(BSOne.isSunk() == false) {
			BSOne.recordHit();
		}
		if(BSTwo.isSunk() == false) {
			BSOne.recordHit();
		}
		if(BSThree.isSunk() == false) {
			BSOne.recordHit();
		}
	}
}
