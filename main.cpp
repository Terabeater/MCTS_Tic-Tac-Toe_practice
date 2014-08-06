#include "header.h"
#include "MCTS.h"
#include "Node.h"

int main()
{
    //本程式碼的亂數初始值
	srand((unsigned)time(NULL));
	//
    int f_s;
    int cinx=0,ciny=0;
    Root=new Node;
    Play play_M;
    //    
    cout<<"井字遊戲"<<endl<<endl;
    cout<<"選擇先手 : 1  選擇後手 : 2"<<endl<<endl;

    cin>>f_s;

    if(f_s==2){
        int a;
        a = rand() % 9;
		play_M.status[a] = 1;
		play_M.show();
    }

	while (play_M.over(1) == 0){
        cout<<endl<<"請輸入座標0~2,0~2 : ";
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
