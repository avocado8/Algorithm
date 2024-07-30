#include <iostream>

using namespace std;

/*
1436 영화감독 숌
666이 연속으로 3번이상 들어가는 수 (1666 2666...)
-> 1000으로 나눴을 때 나머지가 666
해당 수를 10으로 나눠가면서 나머지가 666이 되는지 확인함
*/

//현재 수가 종말의 수인지 확인하는 함수
bool isValid(int cur){
    while(cur >= 666){
        if(cur % 1000 == 666){
            return true;
        }
        cur /= 10;
    }
    return false;
}


//n번째 종말의 수가 무엇인지 찾아내는 함수
int solution(int &n){
    int cur = 666; //현재 탐색하는 수
    int cnt = 0; //종말의 수 개수
    
    //첫번째 수인 666부터 1씩 늘려가며 조건을 충족하는지 검사
    while(true){
        if(isValid(cur)){
            cnt++;
        }
        if(cnt==n){
            return cur;
        }
        cur++;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n);
    return 0;
}