#include <iostream>

using namespace std;
const int MAX = 25;

int countOne(int n){
    int cnt = 0;
    for(int i=0;i<MAX;i++){
        if(n & (1 << i)){
            cnt++;
        }
    }
    return cnt;
}

int solution(int n, int k){
    int answer = 0;
    while(true){
        if(countOne(n+answer) <= k){
            return answer;
        }
        answer++;
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n >> k;
    
    cout << solution(n, k);
    
}