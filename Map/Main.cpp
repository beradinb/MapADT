// Map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "map.h"
#include <iostream>
#include <string>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
using namespace std;

void StringKeyStringValueTest();
void IntKeyBoolValueTest();
void DoubleKeyFloatValueTest();
void ReadFromFileTest();

int main()
{
#ifdef _DEBUG
	_CrtMemState snap1, snap2, snap3;
	_CrtMemCheckpoint(&snap1);
#endif
	
	int choice;
	bool testOn = true;
	while (testOn != false) {
		cout << "***************TEST MENU*********************\n";
		cout << " 1 - String Key String Key Test and Write Map to a Text File" << endl;
		cout << " 2 - Int Key Bool Key Test" << endl;
		cout << " 3 - Double Key Float Key Test" << endl;
		cout << " 4 - Read From File" << endl;
		cout << " 5 - Exit.\n" << endl;
		cout << " Enter your test choice and press return: ";
		cin >> choice;
		cout <<  endl;
		cout << "**********************************************\n" << endl;

		switch (choice)
		{
		case 1:
			cout << " 1 - String Key String Key Test and Write Map to a Text File";
			StringKeyStringValueTest();
			break;
		case 2:
			cout << "2 - Int Key Bool Key Test\n";
			IntKeyBoolValueTest();
			break;
		case 3:
			cout << "3 - Double Key Float Key Test\n";
			DoubleKeyFloatValueTest();
			break;
		case 4:
			cout << " 4 - Read From File";
			ReadFromFileTest();
			break;
		case 5:
			cout << "End of Program.\n";
			testOn = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}

	}

	
#ifdef _DEBUG

	_CrtMemCheckpoint(&snap2);
	if (_CrtMemDifference(&snap3, &snap1, &snap2))
	{
		_CrtMemDumpStatistics(&snap3);
		
	}
	_CrtDumpMemoryLeaks();
#endif
	

	system("pause");
	return 0;
}

void StringKeyStringValueTest()
{

	cout << endl;

	Map<string, string>* myList = new Map<string, string>;
	myList->set("a", "ant");
	myList->set("b", "bat");
	myList->set("c", "cat");

	cout << "Current Key Value pairs:" << endl;
	cout << endl;
	myList->display();
	cout << endl;

	cout << "Getting the value of key 'b' : " << myList->getValue("b") << endl;
	cout << endl;


	cout << "Updating the value of key 'a' to 'updated': " << endl;
	cout << endl;
	myList->update("a", "updated");
	myList->display();
	cout << endl;

	cout << "Inserting a new key value pair: " << endl;
	cout << endl;
	myList->set("Test", "this is a test");
	myList->display();
	cout << "Map Size: " << myList->MapSize() << endl;
	cout << endl;

	cout << "Deleting a key value pair using a key (e.g. key c): " << endl;
	cout << endl;
	myList->deleteElement("c");
	myList->display();
	cout << "Map Size: " << myList->MapSize() << endl;
	cout << endl;

	cout << endl;
	cout << "Updating a non exisiting key e.g. c: ";
	try
	{
		cout << "Key updated: " << myList->update("c", "updated3") << endl;

	}
	catch (NonExistingKeyException e)
	{
		cout << e.what() << endl;
	}
	cout << endl;

	//myList->display();
	cout << "Getting the value of a key e.g. b:";
	cout << myList->getValue("b") << endl;
	cout << endl;
	cout << "Getting the value of a non existing key e.g. ab:";
	try
	{
		cout << "Value for key search: " << myList->getValue("ab") << endl;

	}
	catch (NonExistingKeyException e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
	cout << "Trying to insert a duplicate e.g. inserating key a: ";
	try
	{
		//cout << "Duplicate key insert for: "  << endl;
		myList->set("a", "gyasdgjas");
	}
	catch (DuplicateKeyException e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
	myList->display();
	cout << endl;
	cout << "Writing the current map to KeyValueMap.txt" << endl;
	myList->WriteToFile("KeyValueMap.txt");
	cout << endl;

}

void IntKeyBoolValueTest()
{
	cout << endl;

	/*Map<int, float>* readList = new Map<int, float>;
	readList->ReadFromFile("KeyValueMap.txt");
	cout << "read from file" << endl;
	readList->display();*/

	Map<int, bool>* myList = new Map<int, bool>;
	myList->set(5, true);
	myList->set(6, false);
	myList->set(7, false);

	cout << "Current Key Value pairs:" << endl;
	cout << endl;
	myList->display();
	cout << endl;

	cout << "Getting the value of key '5' : " << myList->getValue(5) << endl;
	cout << endl;


	cout << "Updating the value of key '7' to 'true': " << endl;
	cout << endl;
	myList->update(7, true);
	myList->display();
	cout << endl;

	cout << "Inserting a new key value pair: " << endl;
	cout << endl;
	myList->set(10, true);
	myList->display();
	cout << "Map Size: " << myList->MapSize() << endl;
	cout << endl;

	cout << "Deleting a key value pair using a key (e.g. key 7): " << endl;
	cout << endl;
	myList->deleteElement(7);
	myList->display();
	cout << "Map Size: " << myList->MapSize() << endl;
	cout << endl;

	cout << "Getting the value of a non existing key e.g. 89:";
	try
	{
		cout << "Value for key search: " << myList->getValue(89) << endl;

	}
	catch (NonExistingKeyException e)
	{
		cout << e.what() << endl;
	}
	cout << endl;

	myList->display();

}

void DoubleKeyFloatValueTest()
{
	cout << endl;

	Map<double, float>* myList = new Map<double, float>;
	myList->set(1.11, 1.00000001);
	myList->set(2.22, 35.0505);
	myList->set(3.45, 300.0004);

	cout << "Current Key Value pairs:" << endl;
	cout << endl;
	myList->display();
	cout << endl;

	cout << "Getting the value of key '2.22' : " << myList->getValue(2.22) << endl;
	cout << endl;


	cout << "Updating the value of key '3.45' to '300.01': " << endl;
	cout << endl;
	myList->update(3.45, 300.01);
	myList->display();
	cout << endl;

	cout << "Inserting a new key value pair: " << endl;
	cout << endl;
	myList->set(10.1, 0.05);
	myList->display();
	cout << "Map Size: " << myList->MapSize() << endl;
	cout << endl;

	cout << "Deleting a key value pair using a key (e.g. key 1.11): " << endl;
	cout << endl;
	myList->deleteElement(1.11);
	myList->display();
	cout << "Map Size: " << myList->MapSize() << endl;
	cout << endl;

	cout << "Getting the value of a non existing key e.g. 89.34:";
	try
	{
		cout << "Value for key search: " << myList->getValue(89.34) << endl;

	}
	catch (NonExistingKeyException e)
	{
		cout << e.what() << endl;
	}
	cout << endl;

	myList->display();

}

void ReadFromFileTest()
{
	Map<int, float>* readList = new Map<int, float>;
	readList->ReadFromFile("ReadMap.txt");
	cout << endl;
	cout << "Read from file: ReadMap.txt" << endl;
	readList->display();
}