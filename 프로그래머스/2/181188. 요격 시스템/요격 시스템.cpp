#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int>a, vector<int>b){
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);
    
    
    int last_end = -1;
    for(auto target: targets){
        int cur_s = target[0], cur_e = target[1];
        if (last_end <= cur_s){
            answer++;
            last_end = cur_e;
        }
    }
    return answer;
}