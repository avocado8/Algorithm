#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> parseDate(string date){
    vector<int> result;
    stringstream ss(date);
    string tmp;
    while(getline(ss, tmp, '.')){
        result.push_back(stoi(tmp)); // 연 월 일 숫자로 저장
    }
    return result;
}

int dateToMonth(int year, int month, int day){
    return year*12*28 + month*28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> todayDate = parseDate(today);
    int todayInDays = dateToMonth(todayDate[0],todayDate[1],todayDate[2]);
    
    map<char, int> termMap;
    for(auto term: terms){
        stringstream ss(term);
        char type;
        int t;
        ss >> type >> t;
        termMap[type] = t * 28;
    }
    
    for(int i=0;i<privacies.size();i++){
        stringstream ss(privacies[i]);
        string date;
        char type;
        ss >> date >> type;
        vector<int> tmpDate = parseDate(date);
        int tmpInDays = dateToMonth(tmpDate[0], tmpDate[1], tmpDate[2]);
        int expireDate = tmpInDays + termMap[type];
        
        if(expireDate <= todayInDays){
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}