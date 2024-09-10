#include <iostream>
using namespace std;
const int MAX = 25;

int countOne(int n){
    //1 개수 세기
    int cnt = 0;
    for(int i=0;i<MAX;i++){
        if(n & (1 << i)){
            cnt++;
        }
    }
    return cnt;
}

int solution(int n, int k){
    
    // k개 안에 담을 수 있는지 확인
    // 없다면 물병수 늘려서 다시 확인...
    int answer = 0;
    while(true){
        if(countOne(n+answer) <= k) return answer;
        answer++;
    }
    
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << solution(n, k);
    return 0;
}