#include <iostream>
#include <string>

//using declaration for cout, cin, endl and string
using namespace std;

int main()
{
	float aNum, bNum, cNum;


	string eKey;

	cout << "Please input three numbers and I will give you their sum and average." << endl;

	cout << "input first number: ";
	cin >> aNum;

	cout << "input second number: ";
	cin >> bNum;

	cout << "input third number: ";
	cin >> cNum;

	float sumVal = aNum + bNum + cNum;
	float aveVal = sumVal / 3;

	cout << "Sum calculation: " << aNum << "+" << bNum << "+" << cNum << " = " << sumVal << endl;
	cout << "Average calculation: " << aNum << "+" << bNum << "+" << cNum << " = " << sumVal << "/3 = " << aveVal << endl;
	cout << "Final Sum: " << sumVal << endl;
	cout << "Final Average: " << aveVal << endl;

	cout << "Type ENTER to exit program.";
	cin.ignore();
	if (cin.get() == '\n')

		return 0;
}