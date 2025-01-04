#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_nums;
    for(auto i: numbers){
        str_nums.push_back(to_string(i));
    }
    sort(str_nums.begin(), str_nums.end(), compare);
    if(str_nums[0] == "0") return "0";
    for(auto i: str_nums){
        answer += i;
    }
    return answer;
}