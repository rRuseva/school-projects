// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stack> 
#include <queue> 
#include <vector> 
#include <list> 
#include <sstream>

using namespace std;

//secondary struct for Dijkstra algorithm
vector<int> parent;			// struct for storing the parents ofthe node
vector<int> visited;		// struct for storing info if the node is visited
vector<int> distance1;		//struct for storing the current shortest distance
int infinity = INT_MAX;		//the maximim available distance 
vector<string> nodeNames; //vector with names /sth like key-value: 0 - Sofia, 1 - Ruse..;
int nodeCount;  // number of nodes

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
vector<string> Split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}
int FindNodeIndex(string node, vector<string> names)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (node.compare(names[i]) == 0)
			return i;
	}
	return -1;
}

std::vector<std::vector<int>> CreateMatrix(string filePath)
{

	//-------------------------first step:read the date from file and store it------------------------------------------------
	string one_line, first_line;
	char type = 'd'; // directed or undirected
	char weights = 'u';
	int weight = 1;  // default weight is 1 , whe the matrix is without weights
	ifstream file1;
	file1.open(filePath, ios::in); //opens the file with  the information for nodes and edges

	getline(file1, first_line);			// reads first line of the text file
	if (first_line.compare("undirected") == 0) type = 'u'; //checks if the graph is directed or undirected
	else  type = 'd';									

	getline(file1, first_line);				// reads the second line 
	if (first_line.compare("weight") == 0) weights = 'w'; //checks if the graph's edges have costs
	else  weights = 'u';

	getline(file1, first_line); //gets the third line = names of the nodes
	nodeNames = Split(first_line, ' '); //vector with names /sth like key-value: 0 - Sofia, 1 - Ruse..;
	nodeCount = nodeNames.size();  // number of nodes

	vector<string> paths; //vector with edges - each edge is represented with begining and end exp Sofia-Ruse
	int edgeCount = 0; //number of paths

	while (!file1.eof())		//while loop that reads each line untill end of file
	{
		getline(file1, one_line); //reads one line: exp.  Sofia-Ruse-20
		if (one_line.compare("") != 0)
		{
			paths.push_back(one_line);
			edgeCount++;
		}
	}
	if (paths.back() == " ")
		paths.pop_back();  // removes empty lines if there're any
	file1.close(); //close the file with tha data

	//------------------------------------------next step: create adjacency matrix-------------------------------------------------
	std::vector<std::vector<int>> matrix(nodeCount, std::vector<int>(nodeCount));  // cretes empty matrix with dimensions nodeCount

	for (int k = 0; k < edgeCount; k++)
	{
		vector<string> edge = Split(paths[k], '-'); //puts start node, end node and cost into vector
		int i = FindNodeIndex(edge[0], nodeNames);
		int j = FindNodeIndex(edge[1], nodeNames);
		if (i >= 0 && j >= 0) {
			
			if (weights == 'w')							//if the graph'sedges have costs the cost is int the third column of the edge vector
				weight = std::stoi(edge[2]);
			matrix[i][j] = weight;
			if (type == 'u')							//if the graph is undirected then the matrix is symmetrical about main diogonal
				matrix[j][i] = weight;
		}
		else
		{
			if (i < 0) cout << "There is no such city " << edge[0] << endl;
			if (j < 0) cout << "There is no such city " << edge[1] << endl;
		}
	}
	return matrix;
}

void PrintMatrix(std::vector<std::vector<int>> matrix) // print's adjency matrix
{
	int size = matrix[0].size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}


void PrintPath(int start, int end, vector<int> parent)
{
	if (parent[end] != start) PrintPath(start, parent[end], parent);
	cout << nodeNames[end] << " ";
}
void PrintPaths(int startNode)//printing Dijkstra's paths
{
	for (int i = 0; i < nodeCount; i++) 
	{
		if (i != startNode)
		{
			if (distance1[i] == infinity) cout << "There is no way between " << nodeNames[startNode] << " and " << nodeNames[i] << endl << endl;
			else {
				cout << "The shortest path from capital city - " << nodeNames[startNode] << " to city " << nodeNames[i] << " is: ";
				cout << nodeNames[startNode] << " ";  PrintPath(startNode, i, parent); cout << endl;
				cout << "The number of passengers is " << distance1[i] << "."<< endl << endl;
			}
		}
	}
}

vector<int> FindNeighbours(std::vector<std::vector<int>> matrix, int node)
{	//reads the node line of matrix and if there is element diferrent from 0 then its neighbour and itssaved in the result
	vector<int> result;
	for (int i = 0; i < matrix[node].size(); i++)
	{
		if (matrix[node][i] != 0)
			result.push_back(i);
	}
	return result;
}
void Dijkstra(std::vector<std::vector<int>> matrix, int startNode)
{
	
	for (int i = 0; i < nodeCount; i++) // initialize secondary structs
	{
		visited.push_back(0);				//all node are not visited
		distance1.push_back(infinity);		//all distance are equal to infinity
		parent.push_back(-1);				//no node has a parent
	}
	int currNode = startNode;				// current node; at the begginig it is the start node
	distance1[startNode] = 0;				//the distance of start node to the start node is 0
	for (int i = 0; i < nodeCount; i++)		//for loop for processing of all nodes
	{	//finding the node with minimum current distance in all unvisited nodes = finds the new current node;
		int minDist = infinity-1;			
		for (int i = 0; i < nodeCount; i++)
		{
			if (distance1[i] < minDist && visited[i] == 0)
				currNode = i;
		}
		vector<int> neighbours = FindNeighbours(matrix, currNode);	//finds the neighbours of current node
		//for loop for processing all neighbours of the current node
		for (int j = 0; j < neighbours.size(); j++)
		{
			int nextNode = neighbours[j], nextD = matrix[currNode][nextNode];	
			if (distance1[nextNode] >= distance1[currNode] + nextD) //if the next node distance is longer than the new one 
			{														
				distance1[nextNode] = distance1[currNode] + nextD;	//saves the new current distance
				parent[nextNode] = currNode;						//and the new parent node is the current node
			}
		}
		visited[currNode] = 1;										// the current node is now visited
	}
	
}


int main()
{
	cout << "************* * * * Wellcome to the BEST Airline company * * * *************" << endl;
	string filePath;
	cout << "Please Choose county's map: (type the filepath) " << endl;
	getline(std::cin, filePath);
	std::vector<std::vector<int>> matrix4 = CreateMatrix(filePath);
	
	//calls CreateMatrix with given filepath to create a matrix of adjency
	/*std::vector<std::vector<int>> matrix4 = CreateMatrix("Graph06.txt");
	cout << endl;*/
	//cout << "The city's matrix of adjacency  is: " << endl;
	//PrintMatrix(matrix4);

	string capitalCity;
	int startNode;
	do {
		cout << "Please enter the capital city: " << endl;
		getline(std::cin, capitalCity); //reads user input for start node (=capital city) for Dijkstra algorithm
		startNode = FindNodeIndex(capitalCity, nodeNames); // find the index ofstart node according to vector with all names
		
	} while (startNode < 0 && startNode > nodeNames.size()); // while loop for correct input 

	cout << endl << "The shortest paths from " << nodeNames[startNode] << " to other cities are: " << endl << endl;
	Dijkstra(matrix4, startNode);
	PrintPaths(startNode);

	system("pause");
	return 0;
}