#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health; //현재체력
    int time = 0; //전체시간
    int seq_cnt = 0; //연속성공 횟수
    
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    for(int i=0;i<attacks.size();i++){
        int cur_att_time = attacks[i][0];
        int cur_att_amount = attacks[i][1];
        while(time<cur_att_time){
            time++;
            seq_cnt++;
            answer += x;
            if(answer > health) answer = health;
            if(seq_cnt == t){
                answer+=y;
                seq_cnt = 0; //연속성공 초기화
                if(answer > health) answer = health;
            }
        }
        //공격 처리
        time++;
        answer -= cur_att_amount;
        seq_cnt = 0;
        cout << i << "th try: " << time << " " << answer << "\n";
        if(answer <= 0) return -1;
    }
    
    return answer;
}