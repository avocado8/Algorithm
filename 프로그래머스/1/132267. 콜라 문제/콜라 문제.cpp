#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        int bottle = (n / a) * b;
        answer += bottle;
        n = (n % a) + bottle;
    }
    return answer;
}