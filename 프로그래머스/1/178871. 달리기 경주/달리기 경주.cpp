#include <string>
#include <vector>
#include <map>
using namespace std;

void change(string called, vector<string>&players, map<string, int>&order){
    int idx = order[called]; // 불린 선수의 현재 순서
    // 순서 변경
    swap(players[idx], players[idx-1]);
    order[called] = idx - 1;
    order[players[idx]] = idx;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> order;
    for(int i=0;i<players.size();i++){
        order[players[i]] = i;
    }
    for(int i=0; i<callings.size();i++){
        string called = callings[i];
        change(called, players, order);
    }
    
    return players;
}