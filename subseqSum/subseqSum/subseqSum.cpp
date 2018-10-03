#include <iostream>
#include <string>
#include <sstream>
#include <vector> 

using namespace std;
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

int subSeq(int n, int s, vector<int> seq) {
	int cS = seq[0], br = 0; //инициализиране на текущата сума със стойността на 1я ел. от редицата
	int start = 0; //индекс за начало на текущата подредица

 	for (int i = 1; i <= n; i++) {
		while (cS > s && start <=i - 1) {	//когато стекущата сума е по-голяма от търсената
			cS = cS - seq[start];			// премахваме елементи, докато текущата сума е по-малка от търсената
			start++;
		}

		if (cS == s) {
			br++;
			cS = cS - seq[start];		//премахваме 1и ел. от текущата редица, за дазапочнем
			start++;					//търсенето на новата подредица;
		}

		if (i < n ) {					//добавяне на нови елементи към текущата подредица
			cS = cS + seq[i];
		}
	}

	return br;
}


void main()
{

	int n, s = 0;
	string line; vector<string> vline;
	do {
		cout << "Enter the lenght of the sequence N and the desiered sum S: ";
		getline(std::cin, line);
		vline = Split(line, ' ');
		n = stoi(vline[0]);
		s = stoi(vline[1]);
	} while (!((n > 1 && n < 1000001) && (s > 0 && s < 10000000001)));
	vector<int> input;
	do {
	cout << "Enter the sequence: ";
	getline(std::cin, line);
	vline = Split(line, ' ');
		for (int i = 0; i < vline.size(); i++) {
			if (stoi(vline[i]) < 10000 && stoi(vline[i]) > 0) 	input.push_back(stoi(vline[i]));
			else {
				cout << "Error at " << i+1 << " element." << endl;
				input.clear();
				break;
			}
		}

	} while (input.size() != n);
	
	cout << endl;

	cout << subSeq(n, s, input) << endl;

	system("pause");

}

