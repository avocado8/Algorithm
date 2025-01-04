#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

priority_queue<int, vector<int>, greater<>> min_pq;
priority_queue<int> max_pq;
map<int, int> cnt; // 요소(first)의 개수

void syncQueue(){
    while(!max_pq.empty() && cnt[max_pq.top()]==0) max_pq.pop();
    while(!min_pq.empty() && cnt[min_pq.top()]==0) min_pq.pop();
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i=0;i<operations.size();i++){
        char cmd = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if(cmd == 'I'){
            min_pq.push(num);
            max_pq.push(num);
            cnt[num]++;
        }
        else {
            if (num == -1){ // 최솟값 삭제
                if(!min_pq.empty()){
                    int target = min_pq.top();
                    min_pq.pop();
                    cnt[target]--;
                }
            } else {
                if(!max_pq.empty()){
                    int target = max_pq.top();
                    max_pq.pop();
                    cnt[target]--;
                }
            }
        }
        syncQueue();
        
    }
    
    // syncQueue();
    if(max_pq.empty() && min_pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    return answer;
}