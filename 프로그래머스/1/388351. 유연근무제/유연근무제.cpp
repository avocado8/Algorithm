#include <string>
#include <vector>
#include <iostream>
using namespace std;

int convertTime(int time){
    return (time / 100) * 60 + (time % 100);
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<timelogs.size();i++){
        int cur_sche = schedules[i];
        int cur_sche_time = convertTime(cur_sche);
        int last_time = cur_sche_time + 10;
        bool ok = true;
        for(int j=0;j<7;j++){
            int today = (startday + j - 1) % 7 + 1;
            cout << "today: " << today << "\n";
            if(today>=6) continue;
            int arrival_time = convertTime(timelogs[i][j]);
            if(arrival_time > last_time){
                ok = false;
                cout << "false" << "\n";
                break;
            }
        }
        if(ok) answer++;
    }
    return answer;
}