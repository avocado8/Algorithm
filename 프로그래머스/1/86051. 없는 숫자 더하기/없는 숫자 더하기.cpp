#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> numlist(10,false);
    for(auto n: numbers){
        numlist[n] = true;
    }
    for(int i=0;i<10;i++){
        if(!numlist[i]){
            answer+=i;
        }
    }
    return answer;
}