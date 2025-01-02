#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<string> name;
    map<string, int> cnt;
    
    for(int i=0;i<clothes.size();i++){
        vector<string> tmp = clothes[i];
        cnt[tmp[1]]++;
    }
    for(auto pair: cnt){
        answer *= (pair.second + 1);
    }
    return answer-1;
}