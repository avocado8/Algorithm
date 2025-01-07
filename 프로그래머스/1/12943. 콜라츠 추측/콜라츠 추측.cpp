#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    if(num==1) return 0;
    while(true){
        if(answer==400){
            return -1;
        }
        if(num==1) break;
        if(num%2==0) num/=2;
        else num = (num*3)+1;
        answer++;
        
    }
    return answer;
}