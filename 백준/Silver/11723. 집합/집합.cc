#include <iostream>

using namespace std;

/*
11723 집합
1~20의 정수를 중복 없이 저장할 수 있는 집합
비트의 위치로 해당 수가 집합에 있는지 여부를 판단
*/

void all(int &s){
    //모든 비트를 1로 만듦 (2^21 - 1)
    s = (1 << 21) - 1;
}

void empty(int &s){
    s = 0;
}

void add(int &s, int x){
    s |= (1 << x); //x에 해당하는 비트를 1로 바꿈
}

void remove(int &s, int x){
    s &= ~(1 << x); //x에 해당하는 비트를 0으로 바꿈
}

int check(int &s, int x){
    if (s & (1 << x)){
        return 1;
    }
    else {
        return 0;
    }
}

void toggle(int &s, int x){
    s ^= (1 << x); //1이면 0으로, 0이면 1로 -> xor
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, x, s = 0;
    string op;
    cin >> m;
    
    while(m--){
        cin >> op;
        
        //피연산자가 입력되지 않는 연산: all, empty 
        if(op=="all") {
            all(s);
        }
        else if(op=="empty"){
            empty(s);
        }
        
        //피연산자가 입력되는 연산: add, remove, check, toggle
        else {
            cin >> x;
            if(op=="add"){
                add(s, x);
            }
            else if(op=="remove"){
                remove(s, x);
            }
            else if(op=="check"){
                cout << check(s, x) << '\n';
            }
            else if(op=="toggle"){
                toggle(s, x);
            }
        }
    }
    
    return 0;
}