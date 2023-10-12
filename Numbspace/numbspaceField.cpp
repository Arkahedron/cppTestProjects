#include <iostream>
#include <string>
#include <sstream>

using namespace std; //using declaration for cout, cin, endl and string


string globalInput = ""; //User inputed string

int seedX = 89; //Default starting array value (will change array generation to noise based later)
int seedY = 83;
int rowMax = 7; //Default number map size
int colMax = rowMax;
int mapEdgeMax = rowMax;
int flattenVal = 23;

int userCoordX = 0; //Current user map x coordinate 
int userCoordY = 0; //Current user map y coordinate
int userLocationData = 1; //Value from user's current position on map
bool didWrap; //Did the user's location wrap around the map that move
int multiLoc = userLocationData; //Set combined array initial location

//Build the map arrayX from the defined size
int** nmArrayX = new int* [rowMax];
int buildMapArrayX() {
	for (int i = 0; i < rowMax; ++i) {
		nmArrayX[i] = new int[colMax];
	}
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//Establish X map dataset
			seedX += 1;
			nmArrayX[i][j] = seedX;
		}
	}
	return 0;
}

//Build the map arrayY from the defined size
int** nmArrayY = new int* [rowMax];
int buildMapArrayY() {
	for (int i = 0; i < rowMax; ++i) {
		nmArrayY[i] = new int[colMax];
	}
	for (int j = 0; j < colMax; j++) {
		for (int i = 0; i < rowMax; i++) {
			//Establish Y map dataset (adjust this to build from opposite corner of array)
			seedY += 1;
			nmArrayY[i][j] = seedY;
		}
	}
	return 0;
}


//Print a matrix of the numberspace map arrayX and show user location >UNUSED
int postMapArrayX() {
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			if (nmArrayX[i][j] == userLocationData) {
				cout << "{" << nmArrayX[i][j] << "}";
			}
			else {
				cout << " " << nmArrayX[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "-----------------------------------";
	return nmArrayX[userCoordX][userCoordY];
}

//Print a matrix of the numberspace map arrayY and show user location >UNUSED
int postMapArrayY() {
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			if (nmArrayY[i][j] == userLocationData) {
				cout << "{" << nmArrayY[i][j] << "}";
			}
			else {
				cout << " " << nmArrayY[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "-----------------------------------";
	return nmArrayY[userCoordX][userCoordY];
}


//Print a matrix of the numberspace map array combination and show user location
int postMapArrayMult() {
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			multiLoc = (nmArrayX[i][j] * nmArrayY[i][j]) / flattenVal;
			bool validateLoc = (multiLoc == userLocationData && i == userCoordX && j == userCoordY);
			cout << (validateLoc ? "[" : " " ) << multiLoc << (validateLoc ? "]" : " ");
		}
		cout << endl;
	}
	cout << "-----------------------------------";
	return multiLoc;
}


//Update user's array position to match internal reference
int updateUserLocation() {
	userLocationData = (nmArrayX[userCoordX][userCoordY] * nmArrayY[userCoordX][userCoordY]) / flattenVal;
	return userLocationData;}


//Check if user location hits edge of array map and send them to other end
int checkMapEdge() {
	didWrap = 0;
	if (userCoordX == mapEdgeMax) { userCoordX = 0; didWrap = 1; }
	else if (userCoordX == -1) { userCoordX = mapEdgeMax - 1; didWrap = 1; }
	if (userCoordY == mapEdgeMax) { userCoordY = 0; didWrap = 1; }
	else if (userCoordY == -1) { userCoordY = mapEdgeMax - 1; didWrap = 1; }

	return didWrap;
}


//Check menu input and find first character from string
char cinputMenu() {
	getline(cin, globalInput);
	globalInput += "p";
	size_t foundChar = globalInput.find_first_not_of(" 1234567890");
	char charMenuInput = (globalInput[foundChar]);
	return charMenuInput;
}


//Main code body
int main()
{
	//Introduction and initial input prompt
	cout << "---------{ Welcome to Numbspace }---------" << endl;
	cout << "Press anything to generate the Numbspace Map" << endl;
	cout << "> ";
	getline(cin, globalInput);

	//> cout << "What size of map do you want?: "; cin >> rowMax; colMax = rowMax; mapEdgeMax = rowMax;

	buildMapArrayX();
	buildMapArrayY();
	updateUserLocation();

	//Primary numbspace menu loop
	while (true)
	{

		//> postMapArrayX();
		//> postMapArrayY();
		postMapArrayMult();

		//Output info and input prompt
		cout << endl << " Coordinates: " << userCoordX+1 << "," << userCoordY+1 << endl;
		cout << " Your Location: " << userLocationData << endl;
		cout << " Enter W,A,S,D to move around the map." << endl;
		cout << " (type x to exit program)" << endl << "> ";

		//Switch menu
		switch (cinputMenu())
		{
		//Exit Case
		case 'x': case 'X':
			cout << "exiting program...";
			return 0;

		//Move Up
		case 'w': case 'W':
			cout << endl << " (moving UP)" << endl;
			userCoordX -= 1;
			break;
		//Move Left
		case 'a': case 'A':
			cout << endl << " (moving LEFT)" << endl;
			userCoordY -= 1;
			break;
		//Move Down
		case 's': case 'S':
			cout << endl << " (moving DOWN)" << endl;
			userCoordX += 1;
			break;
		//Move Right
		case 'd': case 'D':
			cout << endl << " (moving RIGHT)" << endl;
			userCoordY += 1;
			break;

		//Else Case, ask for valid input
		default:
			cout << endl << "(please type a valid input): " << endl;
			break;
		}

		checkMapEdge();
		updateUserLocation();

	}

	//Delete arrays from memory heap for cleanup
	for (int i = 0; i < rowMax; ++i) { delete[]nmArrayX[i]; delete[]nmArrayY[i];}
	delete[] nmArrayX, nmArrayY;

	return 0;
}