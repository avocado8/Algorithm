#include <string>
#include <vector>
#include <iostream>
using namespace std;

string deleteDot(string &answer){
    if(answer.length()!=0){
        if(answer[0] == '.'){
            answer = answer.substr(1);
        }
        if(answer[answer.length()-1]=='.'){
            answer = answer.substr(0, answer.length()-1);
        }
    }
    return answer;
}

string solution(string new_id) {
    string answer = "";
    
    for(auto s: new_id){
        if (!isalpha(s) && s!='-' && s!='.' && s!='_' && !isdigit(s)){
            continue;
        }
        answer += tolower(s);
    }
    
    string tmp = "";
    char prev;
    for(auto s: answer){
        if(s != '.' || prev!='.') tmp+=s;
        prev = s;
    }
    answer= tmp;
    deleteDot(answer);
    
    if(answer==""){
        answer = "a";
    }
    
    if(answer.length() >= 16){
        answer = answer.substr(0, 15);
        deleteDot(answer);
    }
    
    if(answer.length() <= 2){
        char last = answer[answer.length()-1];
        while(answer.length() <= 2){
            answer += last;
        }
    }
    
    return answer;
}