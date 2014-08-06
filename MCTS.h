#ifndef MCTS_H_INCLUDED
#define MCTS_H_INCLUDED

#include "header.h"
#include "Play.h"
#include "Node.h"
class MCTS{
public:

	Play play;
	Node *now;

	float uct(Node *in);

	void selection();
	void expansion();
	int simulation();
	void backpropagation();
	void loadplay(Play input);
	void mcts(Play &input,int time);

};

void killtree(Node *kill);
#endif // MCTS_H_INCLUDED
