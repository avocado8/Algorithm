#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isBlocked(int r, int c, vector<pair<int,int>> &blocked){
    // 이동 범위 내에 X가 있으면 blocked
    for(int i=0;i<blocked.size();i++){
        if(blocked[i].first == r && blocked[i].second == c) return true;
    }
    return false;
}

pair<int,int> next(int cur_r, int cur_c, string dir, int dist, int row, int col, vector<pair<int,int>> &blocked){
    // 현재 위치 r,c 에서 dir 방향으로 dist만큼 가는 다음위치
    int next_r=cur_r, next_c=cur_c;
    for(int i=0;i<dist;i++){
        if(dir=="E"){
            next_c += 1;
        } else if(dir=="W") next_c -= 1;
        else if (dir=="S") next_r += 1;
        else if (dir=="N") next_r -= 1;
        if(next_r < 0 || next_c <0 || next_r >= row || next_c >= col || isBlocked(next_r, next_c, blocked)){
            return {cur_r, cur_c};
        }
    }
    
    
    return {next_r, next_c};
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    // 못 가는 구간 체크
    vector<pair<int,int>> blocked;
    int row = park.size();
    int col = park[0].length();
    int start_r = 0, start_c = 0;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[0].length();j++){
            if (park[i][j] == 'S'){
                start_r = i;
                start_c = j;
            }
            if (park[i][j] == 'X'){
                blocked.push_back({i, j});
            }
        }
    }
    for(int i=0;i<blocked.size();i++){
        cout << blocked[i].first << " " << blocked[i].second << "\n";
    }
    pair<int,int> next_rc;
    for(int i=0;i<routes.size();i++){
        string dir = routes[i].substr(0,1);
        int dist = stoi(routes[i].substr(2));
        next_rc = next(start_r, start_c, dir, dist, row, col, blocked);
        start_r = next_rc.first;
        start_c = next_rc.second;
        cout << "next rc:" << start_r << " " << start_c << "\n";
    }
    answer.push_back(next_rc.first);
    answer.push_back(next_rc.second);
    return answer;
}