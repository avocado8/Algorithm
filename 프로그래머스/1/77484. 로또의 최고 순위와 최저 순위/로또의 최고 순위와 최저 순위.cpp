#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeros =0;
    int same = 0;
    for(auto lotto: lottos){
        if(lotto==0) {
            zeros++;
            continue;
        }
        for(auto num: win_nums){
            if(lotto==num){
                same++;
                break;
            }
        }
    }
        
    int first = 7 - (same+zeros);
    int last = 7 - same;
    
    if(first>6) first=6;
    if(last>6) last=6;
    
    answer.push_back(first);
    answer.push_back(last);
    return answer;
}