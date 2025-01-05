#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt_x = 0;
    int cnt_not_x = 0;
    char x = s[0];
    for(int i=0;i<s.length();i++){
        if(s[i] == x) cnt_x++;
        else cnt_not_x++;
        if(cnt_x == cnt_not_x){
            answer++;
            if(i+1 < s.length()){
                x = s[i+1];
            }
            cnt_x=0;
            cnt_not_x=0;
        }
    }
    if(cnt_x!=0 || cnt_not_x!=0) answer++;
    return answer;
}