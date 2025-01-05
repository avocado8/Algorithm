#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int loc[26];
    fill(begin(loc), end(loc), -1);
    for(int i=0;i<s.length();i++){
        int idx = s[i]-'a';
        if(loc[idx] == -1){
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - loc[idx]);
        }
        loc[idx] = i;
    }
    
    
    
    return answer;
}