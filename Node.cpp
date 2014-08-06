#include "Node.h"

Node *Root = new Node;

Node::Node(){
	parent = NULL;
	brother = NULL;
	child = NULL;
	uct = 20000;
	level = 0;
	visit = 0;
	win = 0;
}
 