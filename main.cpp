#include "header.h"
#include "MCTS.h"
#include "Node.h"

int main()
{
    //���{���X���üƪ�l��
	srand((unsigned)time(NULL));
	//
    int f_s;
    int cinx=0,ciny=0;
    Root=new Node;
    Play play_M;
    //    
    cout<<"���r�C��"<<endl<<endl;
    cout<<"��ܥ��� : 1  ��ܫ�� : 2"<<endl<<endl;

    cin>>f_s;

    if(f_s==2){
        int a;
        a = rand() % 9;
		play_M.status[a] = 1;
		play_M.show();
    }

	while (play_M.over(1) == 0){
        cout<<endl<<"�п�J�y��0~2,0~2 : ";
		cin >> cinx;
		cin >> ciny;
		play_M.put(cinx, ciny, f_s);
		play_M.show();
		if (play_M.over(1) != 0){ break; }
		if (f_s == 2){ Root->movement.player = 2; }
        MCTS mcts;
		mcts.mcts(play_M, 100000);
		play_M.show();
		killtree(Root);
		Root = new Node;

    }


    cout<<endl<<"end";







	system("pause");
    return 0;
}
