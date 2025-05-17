#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

pair<char, int> computeScore(string sur, int cho){
    pair<char, int> result;
    //문제와 답을 받아 어떤유형에 몇점 들어가는지 계산
    char disagree_type = sur[0];
    char agree_type = sur[1];
    int tmp_score = 4 - cho; //점수 (+면 동의, -면 비동의)
    if(tmp_score < 0){
        result.first = agree_type;
        result.second = tmp_score*(-1);
    }
    else{
        result.first = disagree_type;
        result.second = (tmp_score );
    }
    return result;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    map<char, int> score;
    for(int i=0;i<n;i++){
        string cur_survey = survey[i]; //현재 문제
        int cur_choice = choices[i]; //현재 문제의 선택
        pair<char, int> tmp_score = computeScore(cur_survey, cur_choice);
        cout << "type " << tmp_score.first << " score " << tmp_score.second << "\n";
        score[tmp_score.first] += tmp_score.second;
    }
    
    if(score['R'] < score['T']) answer += 'T';
    else answer+='R';
    
    if(score['C'] < score['F']) answer += 'F';
    else answer+='C';
    
    if(score['J'] < score['M']) answer += 'M';
    else answer+='J';
    
    if(score['A'] < score['N']) answer += 'N';
    else answer+='A';
    
    return answer;
}