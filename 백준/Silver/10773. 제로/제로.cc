/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int k, tmp;
    cin >> k;
    
    stack<int> st;
    
    while(k--){
        cin >> tmp;
        if(tmp){ //0이 아니면
            st.push(tmp);
        } else { //0이면
            st.pop();
        }
    }
    
    int answer = 0;
    while(!st.empty()){
        tmp = st.top();
        st.pop();
        answer+=tmp;
    }
    cout << answer;
    
    return 0;
}