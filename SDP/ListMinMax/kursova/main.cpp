#include <string.h>
#include <iostream>
#include <list>
#include  <string>

using namespace std;
void fillListInts(list<int> &l)
{
	char ans; int x;
	do
	{
		cout << "Enter lists values: ";
		cin >> x;
		l.push_back(x);
		cout << "Other value? "; cin >> ans;
	} while (ans != 'n');

}
void print(list<int> l)
{
	for(list<int>::iterator it = l.begin(); it != l.end(); it++)
		printf("%d ", *it);
	printf("\n");
}
void printCh(list<char> l)
{
	for (list<char>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it << ' ';
	printf("\n");
}
template <typename T>
void printT(list<T> l)
{
	for (list<T>::iterator it = l.begin(); it != l.end(); it++)
		cout <<*it  << ", ";
	printf("\n");
}

int main()
{
	int myints[] = { -16, 2, 77, 29, 0, -3 };
	list<int> first(myints, myints +sizeof(myints) /sizeof(int));
	
	printT(first);

	int max = 0, min = 0;
	for (list<int>::iterator it = first.begin(); it != first.end(); it++)
	{
		if (*it > max) max = *it;
		if (*it < min) min = *it;
	}
	
	//
	
	list<char> second;
	second.push_back('h');
	second.push_back('e');
	second.push_back('l');
	second.push_back('0');
	//printT(second);

	list<string> strings;
	strings.push_back("hello");
	strings.push_back("hi");
	strings.push_back("why");
	strings.push_back("one");
	//printT(strings);
	cout << endl << "Task 4: " << endl;
	for (list<string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		string el = *it;
		int len = el.length();
		cout << el << " length is " << len << endl;

	}

	cout << endl << "Task 5: " << endl;
	list<string> str;
	for (list<string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		//string el = *it;
		int len = (*it).length();
		if (len >= 5)
		{
			str.push_back(*it);
		}
	}
	printT(str);
	cout << endl << "Task 6: " << endl;
	for (list<string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		string el = *it;
		cout << el[0] << endl;
	}
	cout << endl << "Task 6.1: " << endl;
	list<char*> chars;
	chars.push_back("five");
	chars.push_back("one");
	chars.push_back("two");
	for (list<char*>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		char* el = *it;
		cout << el[0] << endl;
	}


	cout << endl << "Task 7: " << endl;
	list<string> strs;
	strs.push_back("hi");
	strs.push_back("hello");
	strs.push_back("vello");
	strs.push_back("element");
	strs.push_back("dog");
	strs.push_back("Pesho");
	strs.push_back("high");
	strs.push_back("five");

	string sub = "el";

	list<string>::const_iterator it;
	int br=0;
	for(it = strs.begin(); it != strs.end(); it++)
	{
		string s1=*it;
		if(s1.find(sub)!= string::npos)
		{
			br++;
		}
	}
	if (br==0) cout << "Nqma takyv niz" << endl;
	else cout << br << endl;
	system("pause");
}