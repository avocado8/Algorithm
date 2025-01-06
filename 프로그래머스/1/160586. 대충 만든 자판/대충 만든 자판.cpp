#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 특정 키에서, 목표 문자까지 필요한 press 수
map<char,int> countPress(vector<string>& keymap){
    map<char, int> press_count_map;
    for(auto &key: keymap){
        for(int i=0;i<key.size();i++){
            char ch = key[i];
            if(press_count_map.find(ch) == press_count_map.end() || i+1 < press_count_map[ch]){ // 횟수정보가 없음 or 기존것보다 누른횟수가 적음
                press_count_map[ch] = i+1;
            }
        }
    }
    return press_count_map;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> press_count_map = countPress(keymap);
    for(auto target: targets){
        int total_press = 0;
        bool valid = true;
        for(char t: target){
            if(press_count_map.find(t)==press_count_map.end()){
                // 찾을 수 없는 경우
                valid = false;
                break;
            }
            total_press += press_count_map[t];
        }
        if(!valid) answer.push_back(-1);
        else answer.push_back(total_press);
    }
    return answer;
}