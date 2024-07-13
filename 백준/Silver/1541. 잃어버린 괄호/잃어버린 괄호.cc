/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int solution(string str){
    int answer=0;
    string tmp = ""; //피연산자 임시로 저장할 스트링
    bool flag = false; //마이너스가 등장했는지 여부
    
    for(int i=0;i<=str.length();i++){
        if(str[i] == '-' || str[i] == '+' || i==str.length()){ //연산자 or 식이 끝남(끝났다면 현재까지 저장되어있던 tmp값을 처리해줘야 하므로)
            if(flag){
                answer -= stoi(tmp);
            } else {
                answer += stoi(tmp);
            }
            tmp = ""; //임시 문자열 초기화
        }
        else { //숫자(피연산자)
            tmp += str[i];
        }
        if(str[i]=='-') flag=true; //첫번째는 무조건 숫자이므로 조건을 첫 시도 아래에 달아줌
    }
    return answer;
}

int main()
{
    string s;
    cin >> s;
    cout << solution(s);

    return 0;
}