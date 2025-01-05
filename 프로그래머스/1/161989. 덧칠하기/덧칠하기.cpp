#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int cur = 0;
    for(int i=0;i<section.size();i++){
        if (cur > section[i]) {
            continue;
        }
        cur = section[i]; //2
        cur += m; //6
        answer++;
        if (cur > section[section.size()-1]) break;
        
    }
    return answer;
}