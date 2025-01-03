#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q; //우선순위, 순서(location)
    queue<pair<int, int>> final_q;
    for(int i=0;i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
        // cout << priorities[i] << " " << i << "\n";
    }
    // 2 1 3 2
    // 3 2 2 1
    while(!q.empty()){
        pair<int, int> cur_front = q.front();
        cout << cur_front.first << " " << cur_front.second << "\n";
        q.pop();
        // 더 높은 게 있다면
        if (pq.top() > cur_front.first){
            q.push(cur_front);
            cout << "push number" << cur_front.second << "\n";
        }
        else { // 얘가 가장 높으면 ??
            pq.pop();
            final_q.push(cur_front);
        }
    }
    
    
    // 다하고 나면 q에 작업 순서대로 정렬
    cout << "finally q \n";
    for(int i=0;i<priorities.size();i++){
        cout << final_q.front().first << " " << final_q.front().second << "\n";
        pair<int,int> curr = final_q.front();
        final_q.pop();
        if (curr.second == location){
            answer = i;
        }
    }
    
    return answer+1;
}