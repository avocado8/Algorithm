#include<string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(s[i]); //왼쪽 괄호면 push
        }
        else {
            // 오른쪽 괄호면
            if (st.empty()) {
                answer = false;
                break;
            }
            if (st.top() != '('){
                answer=false;
                break;
            }
            st.pop();
        }
    }
    if(!st.empty()){
        answer = false;
    }

    return answer;
}