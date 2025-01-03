#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> remain; // 완성까지 필요한 일수
    for(int i=0;i<progresses.size();i++){
        int cur_prog = progresses[i];
        int cur_speed = speeds[i];
        int remain_prog = 100 - cur_prog;
        int remain_time = ceil((double)remain_prog / cur_speed); // 남은 일수
        remain.push(remain_time);
    }
    while(!remain.empty()){
        int cur = remain.front();
        remain.pop();
        int cnt = 1;
        // 다음 요소가 현재값보다 클 때까지?
        while (!remain.empty() && cur >= remain.front()){
            remain.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}