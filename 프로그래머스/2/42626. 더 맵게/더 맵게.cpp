#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>>pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(pq.top() < K) {
        if(pq.size() <= 1){
            answer = -1;
            break;
        }
        // 앞에 두개를 pop하고 스코빌 지수 계산해 push
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int scov = first + (second*2);
        answer++;
        pq.push(scov);
        
    }
    
    return answer;
}