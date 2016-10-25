#include "Node.h"


Node::Node(int val)
{
	left = nullptr;
	right = nullptr;
	data = val;
}

Node::Node()
{
	left = nullptr;
	right = nullptr;
	data = 0;
}


Node::~Node()
{

}
