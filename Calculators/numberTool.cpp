#include <iostream>
#include <string>
#include <sstream>

//using declaration for cout, cin, endl and string
using namespace std;


//Function for checking if user input is a valid float and only continuing if it exists
float cinputParseFloat() {

	string inputToParse = "";
	float parsedFloatOutput = 0;

	//Test first user input line stringstream data if float
	getline(cin, inputToParse);
	stringstream ss(inputToParse);
	if (ss >> parsedFloatOutput) { return parsedFloatOutput; }

	//Refuse non-float user input and propmt number input
	while (true) {
		cout << " (please enter a valid number): ";
		getline(cin, inputToParse);
		stringstream ss(inputToParse);
		if (ss >> parsedFloatOutput) {break;}
	}
	return parsedFloatOutput;
}


//Function for adding user defined amount of numbers together, also used for average func
pair<float, float> calcStateSum(bool solo) { 
	//sum intro only prints if func is run independently of AVG
	if (solo == 1) { cout << endl << " How many numbers do you want to ADD together?: "; }

	float sumActiveValue = 0;
	int sumInput;
	int sumLength;
	float * sumArray;
	
	//User input for calculation size and checks/cleans to only accept float values
	sumInput = cinputParseFloat(); 

	//Generate and validate array size
	sumArray = new (nothrow) float[sumInput];
	if (sumArray == nullptr) { cout << "(error lol)"; }
	else { 
		//Prompt for, accept, and clean user input to put in array
		for (sumLength = 0; sumLength < sumInput; sumLength++) {
		cout << "  input number " << sumLength+1 << ": ";
		sumArray[sumLength] = cinputParseFloat();
		}
	}
	//Validate and parse array content to add all values together
	for (sumLength = 0; sumLength < sumInput; sumLength++) {
		if (sumArray == nullptr) { cout << "(also error lol)"; }
		else { sumActiveValue += sumArray[sumLength]; }
	}
	//Validate and print listed array with calculation operators
	cout << " Calculation: ";	
	for (sumLength = 0; sumLength < sumInput; sumLength++) {
		if (sumArray == nullptr) { cout << "(also also error lol)"; }
		else {
			if (sumLength == 0) { cout << sumArray[sumLength]; }
			else { cout << "+" << sumArray[sumLength]; }
		}
	}
	cout << " = " << sumActiveValue;
	//Sum outro only prints if func is run independently of AVG
	if (solo == 1) { cout << endl << " Final Sum: " << sumActiveValue << endl << endl; }
	
	//Push array data into floats for return pair before array cleared
	float flSumLength = sumLength;
	float flSumVal = sumActiveValue;

	delete[] sumArray; //Delete sum array from memory heap

	return { flSumVal, flSumLength }; //Func returns final added value and number of inputs
}


//Function for finding the average of a user defined amount of numbers
float calcStateAverage() { cout << endl << " How many numbers do you want to find the AVERAGE of?: ";
	
	//Run and pull addition calculator to get user inputted sum and divisor
	pair<float, float> sumDivisorPair = calcStateSum(0);
	float avgActiveValue = sumDivisorPair.first / sumDivisorPair.second;

	//Print average calculation and outro
	cout <<  "/" << sumDivisorPair.second << " = " << avgActiveValue;
	cout << endl << " Final Average: " << avgActiveValue  << endl << endl;

	return avgActiveValue; //Func returns final averaged value of player inputs
}


//Function for listing a defined amount of multiples of inputted value
float calcStateMultiples() { 
	
	float multActiveValue;
	float multSelected;
	int multInput;
	int multLength;
	float* multArray;

	//User input for multiple number and checks/cleans to only accept float values
	cout << endl << " What number do you want to get MULTIPLES of?: ";
	multSelected = cinputParseFloat();
	
	//User input for how many multiples to get and check/clean to only accept float values
	cout << " How many MULTIPLES of your number do you want?: ";
	multInput = cinputParseFloat();
	
	//Generate and validate array size
	multArray = new (nothrow) float[multInput];
	if (multArray == nullptr) { cout << "(error lol)"; }
	else {
		//Run through array to multiply selected value by determined list and print output
		for (multLength = 0; multLength < multInput; multLength++) {
			multActiveValue = multSelected * (multLength+1);
			multArray[multLength] = multActiveValue;
			if (multLength == 0) { cout << " Multiples of " << multSelected << ": " << multActiveValue; }
			else { cout << ", " << multActiveValue; }
		}
	}
	delete[] multArray; //Delete multiply array from memory heap
	cout << endl << endl;

	return 0;
}


//function for outputting numerical information of inputted value
float calcStateInfo() {
	cout << endl << " What number would you like information on?: ";

	//User input for getting information of
	float infoInput = cinputParseFloat();
	float infoFloor = floor(infoInput);

	//Find if given number is a whole number or not, then print
	cout << "  The number " << infoInput << (infoInput == infoFloor ? " is a WHOLE number" : " is NOT a WHOLE number") << endl;

	//Find if given number is divisible by two, then print relevant polarity
	int infoRemain = remainder(infoFloor, 2);
	cout << "  The number " << infoFloor << (infoRemain == 0 ? " is EVEN" : " is ODD") << endl; //REFACTOR ALL BINARY OUTS TO USE TURNARY OPS

	//Find if given number might be prime, (might not be accurate on larger numbers)
	bool infoIsP = true;
	for (int i = 100; i > 2; i--) {
		int infoPrimer = remainder(infoFloor, i);
		bool equalToSelf = i != infoFloor;
		bool divisible = infoPrimer == 0;
		if (equalToSelf && divisible) { infoIsP = false; break; }
	}
	cout << "  The number " << infoFloor << (infoIsP == true ? " is (probably) PRIME" : "is NOT PRIME") << endl << endl;

	return 0;
}


int main()
{
	//Print program introduction 
	cout << "--------{ WELCOME TO MY NUMBER TOOL }--------" << endl;

	//Calculator loop body
	while (true) {
		
		//Calculator menu selection prompt
		cout << " - type SUM to add a group of numbers together" << endl;
		cout << " - type AVG to find the average of a group of numbers" << endl;
		cout << " - type MULT to find multiples of a given number" << endl;
		cout << " - type INFO to find numerical data of a given number" << endl;
		cout <<" (type X to exit)" << endl;
		cout << "> ";

		//Get user input and put into usable variable
		string mainInput;
		getline(cin, mainInput);
		
		//Exit program if user inputs "x" key
		if (mainInput == "x" or mainInput == "X") 
		{ cout << "exiting program..."; break; }
		
		//Call function for adding user inputted values
		if (mainInput == "SUM" or mainInput == "sum") 
		{ calcStateSum(1); }

		//Call function for averaging user inputted values
		if (mainInput == "AVG" or mainInput == "avg") 
		{ calcStateAverage(); }

		//Call function for finding multiples of inputted values
		if (mainInput == "MULT" or mainInput == "mult")
		{ calcStateMultiples(); }

		//Call function for finding information of an inputted value
		if (mainInput == "INFO" or mainInput == "info")
		{ calcStateInfo(); }

	}
	return 0;
}