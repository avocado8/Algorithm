#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;
    map<string, int>dict;
    dict.insert({"zero",0});
    dict.insert({"one", 1});
    dict.insert({"two",2});
    dict.insert({"three",3});
    dict.insert({"four",4});
    dict.insert({"five",5});
    dict.insert({"six",6});
    dict.insert({"seven",7});
    dict.insert({"eight",8});
    dict.insert({"nine",9});
    
    string answer_string="";
    string tmp="";
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) {
            answer_string += s[i];
            continue;
        }
        tmp += s[i];
        if(dict.find(tmp)!=dict.end()){
            answer_string += to_string(dict[tmp]);
            tmp = "";
        }
    }
    return stoi(answer_string);
}