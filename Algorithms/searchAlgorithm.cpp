#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

string mainInput;

int numberTarget = 9;
bool numberFound = 0;

//Cinput with check to only allow foat input
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
		if (ss >> parsedFloatOutput) { break; }
	}
	return parsedFloatOutput;
}


//Depth first search recursive function on adjacency vector node graph
void dfs(vector<int> adj[], int node, vector<bool>& visited)
{
	//Mark node visited
	visited[node] = true;

	//Check for and print if target number is found
	cout <<(node == numberTarget ? " [" : " ") << node;
	if (node == numberTarget) { numberFound = true; cout << "]:NUMBER FOUND "; }

	//Travelling over all adjacent nodes
	for (int i = 0; i < adj[node].size(); i++) {
		int adjacentNode = adj[node][i];

		//If adjacent node is unvisited do recursion to check children
		if (visited[adjacentNode] == false) {
			dfs(adj, adjacentNode, visited);
		}
	}
}



int main()
{

	//Set adjacency graph length
	const int length = 10;
	vector<int> adj[length];
	//Define adjacency graph
	adj[0] = {2,1,3};
	adj[1] = {6};
	adj[2] = {5};
	adj[3] = {4};
	adj[4] = {};
	adj[5] = {8};
	adj[6] = {9};
	adj[7] = {9};
	adj[8] = {7};
	adj[9] = {};

	

	while (true)
	{

		//Clear visited points
		vector<bool> visited(length, false);
		
		//User prompt and input
		cout << "what number do you want to search for?" << endl;
		numberTarget = cinputParseFloat();

		//Start depth first search at node 0
		cout << "DFS traversal for given graph: ";
		dfs(adj, 0, visited);
		


		//Exit program if user inputs "x" key
		cout << endl << "press x to exit program, enter to continue" << endl;
		getline(cin, mainInput);
		if (mainInput == "x" or mainInput == "X")
		{
			cout << "exiting program..."; break;
		}
	}

	return 0;
}
