#include"MCTS.h"
#include"Node.h"

float MCTS::uct(Node *in){
	float m; //勝率
	if(in->visit == 0){return 10000;} 
	else{ m = (float)in->win / (float)in->visit; } //勝率

	float C=1; //自訂係數

	float Q = log((float)in->parent->visit); //自身拜訪次數Log值

	float uct;
	uct = m + C*sqrt(Q / (float)in->visit);

	return uct;
}
/////////////////////////////////////////////////////////////////////////////////////////
void MCTS::selection(){

    now=Root;
	if (now->visit == 0){ now->visit = 1; }
    while(now->child != NULL){
        float temp=0;  //暫存UCT最大值
        Node *work;
        work = now->child;
		
        //temp = work->uct;
        while(work!=NULL){  //找出UCT最大值
			work->uct=uct(work);
            if(work->uct > temp){
                temp=work->uct;
            }
            work=work->brother;
        }
        work = now->child;
        while(work!=NULL){   //決定走哪
            if(work->uct == temp){
                now=work;
				now->visit = now->visit + 1; //讀到Node先把visit加1，方便平行
                play.put(now->movement.x ,now->movement.y ,now->movement.player);
                break;
            }
            work=work->brother;
        }
    }
	if (play.over(1) == 0){ expansion(); }

}
////////////////////////////////////////////////////////////////////////////////////////////
void MCTS::expansion(){  //
    Node *work= new Node;
	
    int temp_p;
    if(now->movement.player == 1){temp_p=2;}
    else if(now->movement.player == 2){temp_p=1;}

    for(int i=0;i<9;i++){
        if(play.status[i]==0){
            switch(i){
                case 0 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=0;
                    work->movement.y=0;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 1 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=1;
                    work->movement.y=0;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 2 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=2;
                    work->movement.y=0;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 3 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=0;
                    work->movement.y=1;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 4 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=1;
                    work->movement.y=1;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 5 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=2;
                    work->movement.y=1;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 6 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=0;
                    work->movement.y=2;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 7 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=1;
                    work->movement.y=2;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
                case 8 :
					if (now->child == NULL){
						now->child = new Node;
						work = now->child;
					}
					else{
						work->brother = new Node;
						work = work->brother;
					}
                    work->movement.x=2;
                    work->movement.y=2;
                    work->movement.player=temp_p;
                    work->parent=now;
                    work->level=now->level+1;
                    break;
            }
        }
    }



}

int MCTS::simulation(){
    int player_f,player_s,temp; //F 先手 S 後手
    player_s=now->movement.player;
    if(player_s==1){player_f=2;}
    else if(player_s==2){player_f=1;}

	if (play.over(1) != 0){ return now->movement.player; }

    int counter=0; //紀錄還有多少空格
    for(int i=0;i<9;i++){
        if(play.status[i]==0){counter++;}
    }
	if (counter == 0){ return 0; }/////////////////////////////////////////////
    while(1){
		
            temp=rand()%counter;

            for(int i=0;i<9;i++){
                if(play.status[i]==0){
                    if(temp==0){
                        play.status[i]=player_f;
                        counter--;
                        break;
                    }
                    else{temp--;}
                }
            }
			if (play.over(player_f) != 0){ return play.over(player_f); }
            if(counter==0){return 0;}
            /////////////////////////////
             temp=rand()%counter;

             for(int i=0;i<9;i++){
                if(play.status[i]==0){
                    if(temp==0){
                        play.status[i]=player_s;
                        counter--;
                        break;
                    }
                    else{temp--;}
                }
            }
			 if (play.over(player_s) != 0){ return play.over(player_s); }
            if(counter==0){return 0;}

    }

}

void MCTS::backpropagation(){
    int winer = simulation();
    Node *work;
    work=now;
    while(now!= Root){
        if(now->movement.player == winer){
            now->win++;
        }
		else if (winer == 0){ now->win = now->win + 0.5; }
        now=now->parent;
    }

	Root->visit++;
}



void MCTS::loadplay(Play input){

    for(int i=0 ;i<9 ;i++){
        play.status[i]=input.status[i];
    }

}


void killtree(Node *kill){

    if(kill->child != NULL){
        killtree(kill->child);
    }

    else if(kill->brother != NULL){
        killtree(kill->brother);
    }

    delete kill;
    Root=new Node;
}

void MCTS::mcts(Play &input,int time){

    while(time){
		loadplay(input);
        selection();
        backpropagation();
		time--;
    }

	float temp = 0;  //暫存勝率最大值
	float score = 0;
	Node *work;
	work = Root->child;
	while (work != NULL){  //找出UCT最大值
		score = (float)work->win / (float)work->visit;
		if (score > temp){
			temp = score;
		}
		work = work->brother;
	}
	work = Root->child;
	while (work != NULL){   //決定走哪
		if (((float)work->win / (float)work->visit) == temp){
			input.put(work->movement.x, work->movement.y, work->movement.player);
			break;
		}
		work = work->brother;
	}

  
}
