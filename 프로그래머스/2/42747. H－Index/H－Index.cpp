#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &citations, int h){
    // h보다 큰 숫자가 h개이상 있는지
    int num = 0;
    for(auto i: citations){
        if (i >= h){
            num++;
        }
    }
    if(num >= h) return true;
    return false;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int answer = 0;
    for(int i=0;i<citations[citations.size()-1];i++){
        if(check(citations, i)) {
            answer = i;
        }
        else {
            break;
        }
    }
    return answer;
}