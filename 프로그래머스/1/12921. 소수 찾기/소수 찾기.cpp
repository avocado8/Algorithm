#include <string>
#include <vector>

using namespace std;

int cntPrime(int n){
    if(n<2) return 0;
    vector<bool> isPrime(n+1, true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    int cnt = 0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]) cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    answer = cntPrime(n);
    return answer;
}