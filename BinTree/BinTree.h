// CS2420 Programming Project #05
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: Sept 2016
// Header file for main - constants and function prologues
// =================================================

/*I Matthew Vaughan have not used any code other than my own(or that in the textbook)
for this project.I also have not used any function or data - structure from
the Standard - Template Library.I understand that any violation of this
disclaimer will result in a 0 for the project.*/

#include "Node.h"
#include <iostream>

using namespace std;

#pragma once

class BinTree
{
private:
	Node* root;
	void PreOrderTravH(Node* temp);
	void PostOrderTravH(Node* temp);
	void InOrderTravH(Node* temp);
	void PrintH(Node* temp, int depth);
	string tab(int depth);
	void InsertHelper(Node* temp, int value);
	int GetSizeHelper(Node* temp);

	void DestroyTree(Node* temp);
	Node* FindElement(Node* temp, int value);
	Node* FindParent(Node* root, int value);
	void DeleteNC(Node* temp, Node* parent);
	void Delete1C(Node* temp, Node* parent);
	void Delete2C(Node* d);
	void swap(int &a, int &b);
public:
	BinTree();
	BinTree(int val);
	~BinTree();
	void PreOrderTrav();
	void PostOrderTrav();
	void InOrderTrav();
	void Print();
	void Insert(int value);
	int GetSize();
	void DeleteElement(int value);

};

