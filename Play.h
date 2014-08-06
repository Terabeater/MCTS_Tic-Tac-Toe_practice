#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "header.h"

class Play{
public:
	Play();
	int status[9];
	void put(int x,int y,int player);
	void pick(int x,int y);
	int over(int player);
	int over_compare(int a,int b,int c);
	void redo();
	void show();

	//Play operator=(const Play&);
};

//Play Play::operator=(const Play& play){
//    Play _play;
//
//    for(int i=0 ;i<9 ;i++){
//        _play.status[i]=play.status[i];
//    }
//}


#endif // PLAY_H_INCLUDED


/*
status[9] :

   0 1 2 x
0 �f�f�f
1 �f�f�f
2 �f�f�f
y

*/
