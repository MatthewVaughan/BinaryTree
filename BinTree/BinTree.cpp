#include <iostream>;
#include <string>;
#include "BinTree.h"

using namespace std;

BinTree::BinTree()
{
	root = nullptr;
}

BinTree::BinTree(int val)
{
	Node* temp = new Node(val);
	root = temp;
}

BinTree::~BinTree()
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		DestroyTree(root);
		root = nullptr;
	}
}

void BinTree::DestroyTree(Node* temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{
		DestroyTree(temp->left);
		DestroyTree(temp->right);
		delete temp;
		return;
	}
}

void BinTree::Print()
{
	if (root == nullptr)
	{
		cout << "The Tree is currently empty" << endl;
	}
	else
	{
		int depth = 0;
		PrintH(root, depth);
	}
}


void BinTree::PrintH(Node* temp, int depth)
{
	if (temp->left != nullptr)
	{
		PrintH(temp->left, depth + 1);
	}
	cout << tab(depth) << temp->data << endl;
	if (temp->right != nullptr)
	{
		PrintH(temp->right, depth + 1);
	}
}


string BinTree::tab(int depth)
{
	string arr[10] = { " ", "  ", "   ", "    ", "     ", "      ", "       ", "        ", "         ", "          " };
	return arr[depth];

}

void BinTree::PreOrderTrav()
{
	if (root == nullptr)
	{
		cout << "The Tree is currently empty" << endl;
	}
	else
	{
		PreOrderTravH(root);
	}
}

void BinTree::PreOrderTravH(Node* temp)
{
	cout << temp->data << endl;
	if (temp->left != nullptr)
	{
		PreOrderTravH(temp->left);
	}
	if (temp->right != nullptr)
	{
		PreOrderTravH(temp->right);
	}
}

void BinTree::PostOrderTrav()
{
	if (root == nullptr)
	{
		cout << "The Tree is currently empty" << endl;
	}
	else
	{
		PostOrderTravH(root);
	}
}

void BinTree::PostOrderTravH(Node* temp)
{
	if (temp->left != nullptr)
	{
		PostOrderTravH(temp->left);
	}
	if (temp->right != nullptr)
	{
		PostOrderTravH(temp->right);
	}
	cout << temp->data << endl;
}

void BinTree::InOrderTrav()
{
	if (root == nullptr)
	{
		cout << "The Tree is currently empty" << endl;
	}
	else
	{
		InOrderTravH(root);
	}
}

void BinTree::InOrderTravH(Node* temp)
{
	if (temp->left != nullptr)
	{
		InOrderTravH(temp->left);
	}
	cout << temp->data << endl;
	if (temp->right != nullptr)
	{
		InOrderTravH(temp->right);
	}
}

void BinTree::InsertHelper(Node *temp, int value)
{
	if (temp->data == value)
	{ return; }

	if (value <= temp->data)
	{
		if (temp->left == nullptr)
		{
			Node *NN = new Node(value);
			temp->left = NN;
			return;
		}
		else
		{ InsertHelper(temp->left, value); }
	}

	if (value >= temp->data)
	{
		if (temp->right == nullptr)
		{
			Node *NN = new Node(value);
			temp->right = NN;
			return;
		}
		else
		{ InsertHelper(temp->right, value); }
	}
}

void BinTree::Insert(int value)
{
	if (root == nullptr)
	{
		Node *NN = new Node(value);
		root = NN;
	}
	else
	{ InsertHelper(root, value); }
}

int BinTree::GetSizeHelper(Node *temp)
{

	if (temp->right == nullptr && temp->left != nullptr)
	{
		return GetSizeHelper(temp->left) + 1;
	}
	else if (temp->left == nullptr && temp->right != nullptr)
	{
		return GetSizeHelper(temp->right) + 1;
	}
	else if (temp->right == nullptr && temp->left == nullptr)
	{
		return 1;
	}
	else 
	{ 
		return GetSizeHelper(temp->left) + GetSizeHelper(temp->right) + 1;
	}
}

int BinTree::GetSize()
{
	int count = 0;
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		return GetSizeHelper(root);
	}
}
void BinTree::DeleteNC(Node* temp, Node* parent)
{
	if (parent->right != nullptr)
	{
		if (parent->right->data == temp->data)
		{
			parent->right = nullptr;
		}
	}
	
	if (parent->left != nullptr)
	{
		if (parent->left->data == temp->data)
		{
			parent->left = nullptr;
		}
	}
	delete temp;
}


void BinTree::Delete1C(Node* victim, Node* parent)
{
	Node* temp = new Node();

	if (parent->right != nullptr)
	{
		if (parent->right->data == victim->data)
		{
			if (victim->left != nullptr)
			{
				temp->left = victim->left;
				parent->right = temp->left;
			}
			if (victim->right != nullptr)
			{
				temp->right = victim->right;
				parent->right = temp->right;
			}
		}
	}

	if (parent->left != nullptr)
	{
		if (parent->left->data == victim->data)
		{
			if (victim->left != NULL)
			{
				temp->left = victim->left;
				parent->left = temp->left;
			}
			if (victim->right != NULL)
			{
				temp->left = victim->right;
				parent->left = temp->left;
			}
		}
	}
	
	delete victim;
	delete temp;
}

void BinTree::Delete2C(Node* d)
{
	Node* temp = new Node();
	Node* parent = new Node();
	temp = d->left;

	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	parent = FindParent(root, temp->data);

	if (temp->left == nullptr)
	{
		swap(temp->data, d->data);
		
		if (parent->right != nullptr)
		{
			if (parent->right->data == temp->data)
			{
				parent->right = nullptr;
			}
		}

		if (parent->left != nullptr)
		{
			if (parent->left->data == temp->data)
			{
				parent->left = nullptr;
			}
		}
		delete temp;
	}
	else
	{
		swap(temp->data, d->data);

		if (parent->left != nullptr)
		{
			if (parent->left->data == temp->data)
			{
				parent->left = temp->left;
			}
		}
		if (parent->right != nullptr)
		{
			if (parent->right->data == temp->data)
			{
				parent->right = temp->left;
			}
		}
		delete temp;
	}

}

void BinTree::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

Node* BinTree::FindElement(Node* temp, int value)
{
	if (temp != NULL)
	{
		if (temp->data == value)
		{
			return temp;
		}
		else if (temp->data > value)
		{
			FindElement(temp->left, value);
		}
		else if (temp->data < value)
		{
			FindElement(temp->right, value);
		}
	}
	else
	{
		Node *temp = new Node();
		cout << "There is no int of " << value << endl;
		return temp;
	}

}

Node*  BinTree::FindParent(Node* pRoot, int value)
{
	if (pRoot->left == NULL && pRoot->right == NULL)
	{
		return NULL;
	}

	if ((pRoot->left != NULL && pRoot->left->data == value) || (pRoot->right != NULL && pRoot->right->data == value))
	{
		return pRoot;
	}

	if (pRoot->data > value)
	{
		return FindParent(pRoot->left, value);
	}

	if (pRoot->data < value)
	{
		return FindParent(pRoot->right, value);
	}
}

void BinTree::DeleteElement(int value)
{
	Node* temp = new Node();
	Node* parent = new Node();

	temp = FindElement(root, value);
	parent = FindParent(root, value);


	if (temp->left == nullptr)
	{
		if (temp->right == nullptr)
		{
			DeleteNC(temp, parent);
		}
		else
		{
			Delete1C(temp, parent);
		}
	}
	else
	{
		if (temp->right == nullptr)
		{
			Delete1C(temp, parent);
		}
		else
		{
			Delete2C(temp);
		}
	}
}
