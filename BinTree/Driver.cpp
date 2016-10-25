// CS2420 Programming Project #05
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: Oct 2016
// Header file for main - constants and function prologues
// =================================================

/*I Matthew Vaughan have not used any code other than my own(or that in the textbook)
for this project.I also have not used any function or data - structure from
the Standard - Template Library.I understand that any violation of this
disclaimer will result in a 0 for the project.*/

#include "BinTree.h";
#include <iostream>;


using namespace std;

void print_menu_2();
void print_menu();
char get_user_command();
int get_number();

int main()
{
	BinTree test; // A list that we’ll perform tests on
	char choice;   // A command character entered by the user
	char choice2;
	int input;

	cout << "I have initialized an empty Binary Tree of real numbers." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{

		case 'S': cout << "Size is " << test.GetSize()<< '.' << endl;
			break;
		case 'I': test.Insert(get_number());
			break;
		case 'P': print_menu_2();
			choice2 = toupper(get_user_command());
			switch (choice2)
			{
			case '1': test.PreOrderTrav();
				break;
			case '2': test.InOrderTrav();
				break;
			case '3': test.PostOrderTrav();
				break;
			}
			break;
		case 'D': cout << "Type an integer you would like to delete: ";
			cin >> input;
			test.DeleteElement(input);
			cout << "The integer " << input << " has been deleted!" << endl;
			break;
		case 'X':test.~BinTree();
			cout << "The Tree has been erased!" << endl;
			break;
		case 'Q':
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu_2()
{
	cout << endl;
	cout << "The following choices are available: " << endl;
	cout << " 1   Print a copy of the entire Tree (Pre-Order)" << endl;
	cout << " 2   Print a copy of the entire Tree (In-Order)" << endl;
	cout << " 3   Print a copy of the entire Tree (Post-Order)" << endl;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " S   Print the result from the size( ) function" << endl;
	cout << " P   Print the tree" << endl;
	cout << " I   Insert a new number with the insert(...)" << endl;
	cout << " D   Delete an integer from the Tree" << endl;
	cout << " X   Erase the Tree" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}