#include <iostream>
#include <string>
#include <sstream>

//using declaration for cout, cin, endl and string
using namespace std;


//Function for checking if user input is a valid float
float fUpIn() {

	string input = "";
	float myNumber = 0;

	getline(cin, input);
	stringstream ss(input);
	if (ss >> myNumber) { return myNumber; }

	while (true) {
		cout << "please enter a valid number: ";
		getline(cin, input);
		stringstream ss(input);
		if (ss >> myNumber) {break;}
	}
	return myNumber;
}


//Function for adding user defined amount of numbers together
pair<float, float> calcSum(bool solo) {

	float sumVal = 0;
	int inVal;
	int sumLength;
	float * sumArray;
		
	if (solo == 1) { cout << endl << " How many numbers do you want to add together?: "; } //only prints if func is run independently of average function


	inVal = fUpIn(); //Checks and cleans user input to only accept float values

	sumArray = new (nothrow) float[inVal];
	
	if (sumArray == nullptr) { cout << "(error lol)"; }
	else {
		for (sumLength = 0; sumLength < inVal; sumLength++) {
		cout << "  input number " << sumLength+1 << ": ";
		sumArray[sumLength] = fUpIn();
		//cin >> sumArray[sumLength];
		}
	}
	for (sumLength = 0; sumLength < inVal; sumLength++) {
		if (sumArray == nullptr) { cout << "(also error lol)"; }
		else { sumVal += sumArray[sumLength]; }
	}
	cout << " Calculation: ";
	
	for (sumLength = 0; sumLength < inVal; sumLength++) {
		if (sumArray == nullptr) { cout << "(also also error lol)"; }
		else {
			if (sumLength == 0) { cout << sumArray[sumLength]; }
			else { cout << "+" << sumArray[sumLength]; }
		}
	}

	float fSumLength = sumLength;
	float fSumVal = sumVal;

	cout << " = " << sumVal;

	if (solo == 1) { cout << endl << " Final Sum: " << sumVal << endl << endl; }


	delete[] sumArray;
		
	return { fSumVal, fSumLength };
}


//Function for finding the average of a user defined amount of numbers
float calcAvg() {
	
	cout << endl << " How many numbers do you want to find the average of?: ";

	pair<float, float> p = calcSum(0);

	float avgVal;
	avgVal = p.first / p.second;

	cout <<  "/" << p.second << " = " << avgVal;

	cout << endl << " Final Average: " << avgVal  << endl << endl;

	return avgVal;
}


int main()
{
	string eKey; //variable of user inputted key

	cout << "  -{ WELCOME TO MY NUMBER TOOL }-" << endl;

	while (true) {
	
		//Calculator menu selection prompt & user input check
		cout << "- To add three numbers, type SUM" << endl;
		cout << "- To find the average of three numbers, type AVG" << endl;
		cout <<" (type x to exit)" << endl;
		getline(cin, eKey);
		if (eKey == "x") { cout << "exiting program..."; break; }
		
		//Adds user inputted values
		if (eKey == "SUM") { calcSum(1); }

		//Averages three inputted values
		if (eKey == "AVG") { calcAvg(); } 

		cin.clear();
	}

		return 0;
}