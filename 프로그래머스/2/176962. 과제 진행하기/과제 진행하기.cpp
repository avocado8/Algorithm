#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int strToInt(string time){
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    int int_time = hour * 60 + min; //분 기준으로 변환
    return int_time;
}

bool compare(vector<string>a, vector<string>b){
    return strToInt(a[1]) < strToInt(b[1]);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    sort(plans.begin(), plans.end(), compare);
    for(auto p: plans){
        cout << p[0] << p[1] << p[2] << "\n";
    }
    stack<pair<string,int>> stopped_list;
    for(int i=0;i<plans.size();i++){
        vector<string> cur = plans[i];
        string cur_name = cur[0];
        int cur_start_time = strToInt(cur[1]);
        int cur_playing_time = stoi(cur[2]);
        
        if (i == plans.size()-1){ // 다음이 없을 경우
            answer.push_back(cur_name);
            while(!stopped_list.empty()){
                pair<string, int> remained = stopped_list.top();
                stopped_list.pop();
                answer.push_back(remained.first);
            }
            break;
        }
        
        vector<string> next = plans[i+1];
        int next_start_time = strToInt(next[1]);
        
        
        if(cur_start_time + cur_playing_time > next_start_time){
            pair<string, int> stop;
            int remain_time = cur_playing_time - (next_start_time - cur_start_time);
            stop = make_pair(cur_name, remain_time );
            stopped_list.push(stop);
        }
        else { // 다음 과제의 시작 시간이 현재과제를 끝낸 이후라면
            answer.push_back(cur_name);
            
            int free_time = next_start_time - (cur_playing_time + cur_start_time);
            while(free_time>0 && !stopped_list.empty()){
                // 남은 시간에 멈춰뒀던 과제 처리
                pair<string, int> pre_stopped = stopped_list.top();
                stopped_list.pop();
                if(free_time >= pre_stopped.second){
                    // 남은 시간이 멈춰뒀던 과제 처리에 충분하다면
                    answer.push_back(pre_stopped.first);
                    free_time -= pre_stopped.second;
                }
                else {
                    // 충분하지 않으면 그만큼만 처리하고 다시 push
                    int re_rem = pre_stopped.second - free_time;
                    stopped_list.push(make_pair(pre_stopped.first, re_rem));
                    free_time = 0;
                }
            }
        }
    }
    
    return answer;
}