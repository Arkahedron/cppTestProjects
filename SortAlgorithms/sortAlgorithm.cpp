#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

bool doContinue = true;
string rawInput = "";
string dirtyOutput;
float cleanOutput;
float parsedFloatOutput = 0;
string cleanStringOutput = "";

//Cinput with check to only allow foat input
float parseCinput() {

	//Exit program if user inputs "x" key
	cout << " (x to exit) ";

	cout << endl << " > ";

	//Test first user input line stringstream data if float
	getline(cin, rawInput);

	if (rawInput == "x" || rawInput == "X")
	{ 
		cout << "exiting program..." << endl;
		doContinue = false;
		return -1;
	}

	stringstream ss(rawInput);
	if (ss >> parsedFloatOutput) { rawInput = ""; return parsedFloatOutput; }
	else { 
		dirtyOutput = rawInput;
		rawInput = "";
		cout << " (please enter a valid number)" << endl;
		return parseCinput();
	}

	/*
	//Refuse non-float user input and propmt number input
	while (true) {
		cout << " (please enter a valid number)" << endl;
		rawInput = "";		
		getline(cin, rawInput);
		stringstream ss(rawInput);
		if (ss >> parsedFloatOutput) { break; }
	}

	rawInput = "";
	return parsedFloatOutput;
	*/
}


int main() {
	

	while (doContinue == true) {
		//User prompt and input
		cout << endl << endl << "what number do you want to search for?" << endl;
		
		cleanOutput = parseCinput();

		cout << "your number is: " << "[" << cleanOutput << "]";



		
	}
		
}