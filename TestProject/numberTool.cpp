#include <iostream>
#include <string>

//using declaration for cout, cin, endl and string
using namespace std;


//currently unused functions
float calcSum(float aNum, float bNum, float cNum) {
	cout << "Please input three numbers and I will give you their sum." << endl;

	cout << "input first number: ";
	cin >> aNum;

	cout << "input second number: ";
	cin >> bNum;

	cout << "input third number: ";
	cin >> cNum;

	float sumVal = aNum + bNum + cNum;

	cout << "Calculation: " << aNum << "+" << bNum << "+" << cNum << " = " << sumVal << endl;
	cout << "Final Sum: " << sumVal << endl;

	return sumVal;
}
float calcAvg(float aNum, float bNum, float cNum) {
	cout << "Please input three numbers and I will give you their average." << endl;

	cout << "input first number: ";
	cin >> aNum;

	cout << "input second number: ";
	cin >> bNum;

	cout << "input third number: ";
	cin >> cNum;

	float sumVal = aNum + bNum + cNum;
	float avgVal = sumVal / 3;

	cout << "Calculation: " << aNum << "+" << bNum << "+" << cNum << " = " << sumVal << "/3 = " << avgVal << endl;
	cout << "Final Average: " << avgVal << endl;

	return avgVal;
}


int main()
{
	string eKey; //variable of user inputted key
	float aNum, bNum, cNum;

	//enum calcMode {eFindSum, eFindAvg}; (unused variable of what current mode the number tool is in)


	cout << "  -{ WELCOME TO MY NUMBER TOOL }-" << endl;

	while (true) {
	
		//Calculator menu selection prompt & user input check
		cout << "- To add three numbers, type SUM" << endl;
		cout << "- To find the average of three numbers, type AVG" << endl;
		cout <<" (type x to exit)" << endl;
		getline(cin, eKey);
		if (eKey == "x") { cout << "exiting program..."; break; }


		//Adds three inputted values
		if (eKey == "SUM" or "AVG") {
			if (eKey == "SUM") {
				cout << endl << " Please input three numbers and I will give you their sum." << endl;

				cout << "  input first number: ";
				cin >> aNum;

				cout << "  input second number: ";
				cin >> bNum;

				cout << "  input third number: ";
				cin >> cNum;

				float sumVal = aNum + bNum + cNum;

				cout << "Calculation: " << aNum << "+" << bNum << "+" << cNum << " = " << sumVal << endl;
				cout << "Final Sum: " << sumVal << endl << endl;
			}

			//Averages three inputted values
			if (eKey == "AVG") {
				cout << endl << " Please input three numbers and I will give you their average." << endl;

				cout << "  input first number: ";
				cin >> aNum;

				cout << "  input second number: ";
				cin >> bNum;

				cout << "  input third number: ";
				cin >> cNum;

				float sumVal = aNum + bNum + cNum;
				float avgVal = sumVal / 3;

				cout << " Calculation: " << aNum << "+" << bNum << "+" << cNum << " = " << sumVal << "/3 = " << avgVal << endl;
				cout << " Final Average: " << avgVal << endl << endl;
			}
		}

		cout << " Type ENTER to return to menu (type x to exit)" << endl;
		cin.ignore();
		getline(cin, eKey);
		if (eKey == "x") { cout <<"exiting program..."; break; }
	}

		return 0;
}