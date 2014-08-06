#include"Play.h"

Play::Play(){
	for (int i = 0; i < 9; i++){
		status[i] = 0;
	}
}


	void Play::put(int x,int y,int player){
	    int a=0;
	    a=x+(3*y);
	    status[a]=player;
	};

	void Play::pick(int x,int y){
        int a=0;
	    a=x+(3*y);
	    status[a]=0;
	};

	int Play::over_compare(int a, int b, int c){
		if (a == b){
			if (b == c){
				if (a == c){
					if (a != 0 && b != 0 && c != 0){
						return 1;
					}
				}
			}
		}
		return 0;
	}

	int Play::over(int player){
		if (over_compare(status[0] ,status[1] ,status[2])
			|| over_compare(status[3] ,status[4] ,status[5])
			|| over_compare(status[6] ,status[7] ,status[8])
			|| over_compare(status[0] ,status[3] ,status[6])
			|| over_compare(status[1] ,status[4] ,status[7])
			|| over_compare(status[2] ,status[5] ,status[8])
			|| over_compare(status[0] ,status[4] ,status[8])
			|| over_compare(status[2] ,status[4] ,status[6])
        ){
            return player;
        }
        return 0;
	};

	void Play::redo(){
	    for (int i = 0; i < 9; i++){
		status[i] = 0;
	    }
	};

    void Play::show(){
       cout<<endl<<"¢@¢¯¢°¢±"<<endl;
       cout<<"¢¯";
       for (int i = 0; i < 3; i++){
		if(status[i] == 0){cout<<"¡@";}
		else if(status[i] == 1){cout<<"¢Ý";}
		else if(status[i] == 2){cout<<"¢æ";}
	    }
	    cout<<endl;
        cout<<"¢°";
       for (int i = 3; i < 6; i++){
		if(status[i] == 0){cout<<"¡@";}
		else if(status[i] == 1){cout<<"¢Ý";}
		else if(status[i] == 2){cout<<"¢æ";}
	    }
	    cout<<endl;
        cout<<"¢±";
       for (int i = 6; i < 9; i++){
		if(status[i] == 0){cout<<"¡@";}
		else if(status[i] == 1){cout<<"¢Ý";}
		else if(status[i] == 2){cout<<"¢æ";}
	    }
	    cout<<endl;
    }
