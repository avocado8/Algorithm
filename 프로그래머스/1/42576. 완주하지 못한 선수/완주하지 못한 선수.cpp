#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++){
        string tmp = completion[i];
        string cmp = participant[i];
        if (completion[i]!=participant[i]){
            answer = participant[i];
            break;
        }
    }
    if(answer==""){
        answer = participant[completion.size()];
    }
    return answer;
}