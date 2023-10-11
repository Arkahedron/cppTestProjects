#include <iostream>
#include <string>
#include <sstream>

using namespace std; //using declaration for cout, cin, endl and string


string globalInput = ""; //User inputed string

int userPointX = 2; //Current user map x coordinate 
int userPointY = 2; //Current user map y coordinate
int userLocationData; //Value from user's current position on map
bool didWrap; //Did the user's location wrap around the map that move


//Number map 2d spatial array
int numbMap[5][5] = {
	{-4,-3,-2,-1, 0},
	{-3,-2,-1, 0, 1},
	{-2,-1, 0, 1, 2},
	{-1, 0, 1, 2, 3},
	{ 0, 1, 2, 3, 4}
};

//Define map border as length of 2d array
int mapEdgeMax = sizeof numbMap / sizeof numbMap[0];


//Check if user location hits edge of array map and send them to other end
int checkMapEdge(){
	didWrap = 0;
	if (userPointX == mapEdgeMax) { userPointX = 0; didWrap = 1;}
	else if (userPointX == -1) { userPointX = mapEdgeMax - 1; didWrap = 1;}
	if (userPointY == mapEdgeMax) { userPointY = 0; didWrap = 1;}
	else if (userPointY == -1) { userPointY = mapEdgeMax - 1; didWrap = 1;}
	
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
	cout << "---------{ Welcome to Numbspace }---------" << endl;
	cout << "Press anything to generate the Numbspace Map" << endl;
	getline(cin, globalInput);


	while (true)
	{
		cout << endl << " Coordinates: " << userPointX+1 << "," << userPointY+1 << endl;
		cout << " Your Location: " << userLocationData << endl;
		cout << " Enter W,A,S,D to move around the map." << endl;
		cout << " (type x to exit program)" << endl << "> ";

		
		switch (cinputMenu())
		{
		//Exit Case
		case 'x': case 'X':
			cout << "exiting program...";
			return 0;

		//Move Up
		case 'w': case 'W':
			cout << endl << " moving UP" << endl;
			userPointY -= 1;
			break;
		//Move Left
		case 'a': case 'A':
			cout << endl << " moving LEFT" << endl;
			userPointX -= 1;
			break;
		//Move Down
		case 's': case 'S':
			cout << endl << " moving DOWN" << endl;
			userPointY += 1;
			break;
		//Move Right
		case 'd': case 'D':
			cout << endl << " moving RIGHT" << endl;
			userPointX += 1;
			break;

		//Else Case, ask for valid input
		default:
			cout << endl << "(please type a valid input): " << endl;
			break;
		}

		checkMapEdge();
		userLocationData = numbMap[userPointX][userPointY];

	}

	return 0;
}