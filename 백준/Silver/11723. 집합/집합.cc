#include <iostream>

using namespace std;

void set(int m){
    int x, s=0;

    for(int i=0; i<m; i++){
        string command;
        cin>>command;

        if(command=="add"){
            cin>>x;
            s |= (1<<x);
        }

        else if(command == "remove"){
            cin>>x;
            s &= ~(1<<x);
        }

        else if(command == "check"){
            cin>>x;
            if(s & (1<<x)){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }

        else if(command == "toggle"){
            cin>>x;
            if(s & (1<<x)){
                s &= ~(1<<x);
            }
            else{
                s |= (1<<x);
            }
        }

        else if(command == "all"){
            s = (1<<21)-1;
        }

        else if(command == "empty"){;
            s = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin>>m;

    set(m);

    return 0;
}