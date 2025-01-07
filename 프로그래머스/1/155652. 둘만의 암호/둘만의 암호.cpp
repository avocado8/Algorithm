#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> alp(26, true);
    for(int i=0;i<skip.length();i++){
        alp[skip[i] - 'a'] = false;
    }
    for(int i=0;i<s.length();i++){
        char cur = s[i];
        int cnt = 0;
        while(cnt < index){
            if (cur == 'z') cur = 'a';
            else cur+=1;
            if (alp[cur - 'a']){
                cnt++;
            }
        }
        answer += cur;
    }
    return answer;
}