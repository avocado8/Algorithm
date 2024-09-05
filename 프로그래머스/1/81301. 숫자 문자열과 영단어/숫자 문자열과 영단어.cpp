#include <string>
#include <vector>

using namespace std;

vector<string> letters = {
        "zero", "one", "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"
    };

int solution(string s) {
    int answer = 0;
    string tmp = "";
    for(auto c: s){
        if(isdigit(c)){
            answer = answer*10 + (c-'0');
        }
        else tmp += c;
        for(int i=0;i<=9;i++){
            if (letters[i]==tmp){
                answer = answer*10 + i;
                tmp="";
                break;
            }
        }
    }
    return answer;
}