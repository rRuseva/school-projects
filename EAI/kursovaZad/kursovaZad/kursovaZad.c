// kursovaZad.cpp : Defines the entry point for the console application.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//#include "stdafx.h"

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

struct element
{
	char a[255];
	float b;
	int c;
};

struct treeNode
{
	element root;
	treeNode *leftNode, *rightNode;
};

element currentElement;
element *elements=NULL;
int pos = 0;
treeNode * tree;
treeNode * newTree = NULL;

FILE *fs = NULL;

//Adding /creating/ Tree node
void AddTreeNode(treeNode * &current, element r)
{
	if (!current)
	{
		current = new treeNode;
		current->leftNode = NULL;
		current->rightNode = NULL;
		current->root = r;
	}
	else 
	{
		if (strcmp(current->root.a, r.a)>0)
		{
			AddTreeNode(current->leftNode, r);
		}
		else if (strcmp(current->root.a, r.a)<0)
		{
			AddTreeNode(current->rightNode, r);
		}
	}
}

//Print tree to the console by left - root - right traversal 
void printTree(treeNode *t)
{
	if (t)
	{
		printTree(t->leftNode);
		printf(t->root.a); printf(" ");
		printTree(t->rightNode);
	}
}
/* Compute the "height" of a tree */
int height(treeNode * node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lheight = height(node->leftNode);
		int rheight = height(node->rightNode);

		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}

/* Print nodes at a given level */
void printGivenLevel(treeNode * t, int level, int offset)
{
	if (t == NULL)
	{
		for (int j = 0; j < offset ; j++)
			printf(" ");
		printf(" ");
		return;
	}
	if (level == 1)
	{
		for (int j = 0; j < offset ; j++)
			printf(" ");
		if(t->leftNode)
			printf("/");
		printf("%s", t->root.a);
		if (t->rightNode)
		{
			printf("\\");
		}
	}
	else if (level > 1)
	{
		printGivenLevel(t->leftNode, level - 1, offset / 2 );
		printGivenLevel(t->rightNode, level - 1, offset / 2);
	}
}
/* Print empty rows */
void printGivenLevelEmptyRow(treeNode * t, int level, int offset)
{
	if (t == NULL)
	{
		for (int j = 0; j < offset-1; j++)
			printf(" ");
		printf("   ");
		return;
	}
	if (level == 1)
	{
		for (int j = 0; j < offset; j++)
			printf(" ");
		if (t->leftNode)
			printf("/");
		for (int j = 0; j < strlen(t->root.a)+2; j++)
			printf(" ");
		if (t->rightNode)
		{
			printf("\\");
		}
	}
	else if (level > 1)
	{
		printGivenLevelEmptyRow(t->leftNode, level - 1, offset / 2);
		printGivenLevelEmptyRow(t->rightNode, level - 1, offset / 2);
	}
}
/* DFS - print level order traversal a tree*/
void printLevelOrder(treeNode * t)
{
	int h = height(t);
	int maxWidth = pow(2, h - 1);
	for (int i = 1; i <= h; i++)
	{
		printGivenLevel(t, i, (maxWidth));
		printf("\n");
		printGivenLevelEmptyRow(t, i, (maxWidth-1));
		printf("\n");
	}
}

void drawTree(treeNode * t)
{
	printLevelOrder(t);
	_getch();
}

//Printing the info of single element to the console
void writeElement( element cEl)
{
	printf("Element %s, float number = %f, int number = %d;\n", cEl.a, cEl.b, cEl.c);
	printf("-----------------\n");
	_getch();
}

//reading from console info about a single element
element readElement()
{
	element currentElement;

	printf("Please, enter string info: ");
	scanf("%s", currentElement.a);

	printf("Please, enter float info: "); 
	scanf("%f", &currentElement.b);

	printf("Please, enter integer info: ");
	scanf("%d", &currentElement.c);
	printf("\n");

	return currentElement;
}

//saves all entries into text file
void createInfoTextFile()
{
	//element currentElement;
	char fileName[120];

	//gives the user ability to choose file destination
	do
	{
		printf("choose file name:  ");
		gets_s(fileName);
	} while (!*fileName);
	printf("\n");

	printf("Creating new info text file...\n");

	char ch;
	fs = fopen(fileName, "w");
	if(fs != NULL)
	{
		do {
			//read info and create one element
			element cElement = readElement();
			//writes the element into .txt file
			fprintf(fs, "%s \t %.2f \t %d\n", cElement.a, cElement.b, cElement.c );
			printf("Add more?? (y/n)");
			printf("\n");
			ch = _getch();
		} while (ch == 'y' || ch == 'Y');
	}
	else
	{
		printf("Error opening file :( ..."); 
		return;
	}
	fclose(fs);
}
void createTreeFromTXTFile()
{
	char fileName[120];
	element currentElement;
	//gives the user ability to choose source file
	do
	{
		printf("choose source file name:  ");
		gets_s(fileName);
	} while (!*fileName);
	printf("\n");
	
	fs = fopen(fileName, "r");
	if (fs != NULL)
	{
		printf("Reading from file... \n");
		while (fscanf(fs, "%s\t%f\t%d\n", currentElement.a, &currentElement.b, &currentElement.c) !=-1)
		{
			AddTreeNode(tree, currentElement);
			writeElement(currentElement);
		} 
	}
	else
	{
		printf("Error opening file"); 
		return;
	}
	fclose(fs);

	printf("\n\nYour tree in Left - Root - Right traversal \n\n");
	printTree(tree);
	printf("\n\nYour tree is: \n\n");
	drawTree(tree);

	_getch();
}

// help function for saving tree to dat file - saves the Rt-L-R traverse into array
void saveTreeToArrayRtLR(treeNode *t)
{
	if (t)
	{
		elements[pos] = t->root;
		pos++;

		saveTreeToArrayRtLR(t->leftNode);
		saveTreeToArrayRtLR(t->rightNode);
	}
	else
		return;
}

//Save tree to a dat file by root - left - right traversal 
void exportTreeToFile(treeNode *t)
{
	char fName[120];
	int h = height(t); //height of the tree
	int maxWidth = pow(2, h - 1); //the maximum number of nodes
	elements = new element[maxWidth];

	//gives the user ability to choose file destination
	do
	{
		printf("choose destination file:  ");
		gets_s(fName);
	} while (!*fName);
	printf("\n");

	saveTreeToArrayRtLR(t);

	//write into dat file
	fs = fopen(fName, "a+");
	if (fs != NULL)
	{
		printf("Saving tree to file... \n");
		for(int i = 0; i < pos; i++)
			fwrite(&elements[i], sizeof(element), 1, fs);
	}
	else
	{
		printf("Error opening file");
		return;
	}
	
	delete elements;
	fclose(fs);
	printf("\nThe file is ready :) ... \n");
	_getch();
}

//Create new tree from tree text file
void importTreeFromFile()
{
	char fName[120];
	element currentElement;

	//gives the user ability to choose source file
	do
	{
		printf("choose file name:  ");
		gets_s(fName);
	} while (!*fName); 
	printf("\n");

	int count = 0; //counts the number of nodes in the file 

	newTree = NULL;
	fs = fopen(fName, "r");
	if (fs != NULL)
	{
		printf("Reading 'tree' from file... \n");
		fread(&currentElement, sizeof(element), 1, fs);

		while (!feof(fs))
		{
			AddTreeNode(newTree, currentElement);
			fread(&currentElement, sizeof(element), 1, fs);
			count++;
		}
	}
	else
	{
		printf("Error opening file");
		return;
	}
	fclose(fs);

	//... show new tree 
	printf("\n\n Number of nodes is: %d \n", count);
	printf("\n\n Tree  from .dat file in Left - Root - Right traversal is \n\n");
	printTree(newTree);
	printf("\n\nTree  from .dat file is:  \n\n");
	drawTree(newTree);

	printf("\n\nTree  from .txt file is:  \n\n");
	drawTree(tree);

	_getch();
}

//Sums ASCII codes of a string 
int SumAscii(char* string)
{
	int sum = 0,
		lenght = strlen(string);
	for (int i = 0; i < lenght; i++)
	{
		sum = sum + string[i];
	}
	return sum;
}

//Process tree data // left - root - right traversal 
void processTree(treeNode *t)
{
	if (t)
	{
		processTree(t->leftNode);

		int sum = SumAscii(t->root.a);
		if (sum == t->root.c) 
		{ 
			//writeElement(t->root); 
			printf("Sum of ASCII codes of %s is %d;\n\n", t->root.a, sum);
		}
		processTree(t->rightNode);
	}
}

void main()
{
	char izb[7];
	do {
		system("CLS");
		printf("\n\t--- Menu ---\n");
		printf("a. Create new text file with elements\n");
		printf("b. Read elements from text file and create lexical binary tree\n");
		//printf("c. Sort lexical binary tree\n");
		printf("d. Print string elements which sum of ASCII codes is equal to the corresponding to its int element\n");
		printf("e. Export the tree to file (Root Left Right)\n");
		printf("f. Import tree from file\n");
		//printf("g. Print tree Left Root Right\n");
		//printf("h. Draw tree \n");
		printf("0. END\n\n");
		printf("Your choice: ");gets_s(izb); 
		printf("\n");
		switch (izb[0])
		{
			case 'a':createInfoTextFile();break;
			case 'b':createTreeFromTXTFile();break;
			case 'd': {processTree(tree); _getch(); }break;
			case 'e':exportTreeToFile(tree);break;
			case 'f':importTreeFromFile();break;
			//case 'g': {printTree(tree);_getch();break;}
			//case 'h':drawTree(newTree);break;
		}
	} while (izb[0] != '0');
}