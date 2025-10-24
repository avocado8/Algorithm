#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    if(sqrt(n) == floor(sqrt(n))) return pow(sqrt(n)+1, 2);
    return -1;
}