#pragma once

struct Node
{
	Node* left;
	Node* right;
	int data;
	Node();
	Node(int val);
	~Node();
};

