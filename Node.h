#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "header.h"
#include "Move.h"

class Node{

public:
	Node();
	Node *parent;
	Node *brother;
	Node *child;


	float uct;
	int level;
	int visit;
	float win;

	Move movement;
};

extern Node *Root; //全域變數 MCTS用的總Root

#endif // NODE_H_INCLUDED
