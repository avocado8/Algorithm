/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

const int MAX = 26;

//n리터 물을 담는 데 필요한 최소 물병 개수
int bitCount(int n){
    int cnt = 0;
    for(int i=0;i<MAX;i++){
        if (n & (1 << i)){
            cnt++;
        }
    }
    return cnt;
}

//상점에서 사야하는 최소 물병 개수
int minCount(int n, int k){
    int answer = 0;
    while(true){
        if (bitCount(n + answer) <= k){ //k개 이하 물병에 담을 수 있으면
            return answer;
        }
        answer++; //담을 수 없다면 물병추가
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << minCount(n, k);

    return 0;
}