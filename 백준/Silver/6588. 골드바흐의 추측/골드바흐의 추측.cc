#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;    //n의 최대 범위
vector<int> primes;         //소수 저장 벡터
vector<bool> is_prime(MAX + 1, true);   //소수 여부 판별


//최대범위 내의 소수 구하기
void getPrimes() {
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= MAX; i++) {
        if(is_prime[i]) {  //소수이면 벡터에 저장
            primes.push_back(i);

            for(int j = i * i; j <= MAX; j += i) {    //배수는 전부 제외
                is_prime[j] = false;
            }
        }
    }
}

//b-a가 가장 큰 쌍 구하기
int findMax(int n) {
    for(int i = 0; i < primes.size(); i++) {
        int a = primes[i];
        int b = n - a;
        if(is_prime[b]) {
            return a;
        }
    }
    return -1;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getPrimes();
    int n;

    while(true) {
        //입력
        cin >> n;
        if(n == 0) break;

        //출력
        int a = findMax(n);
        if(a != -1) {
            cout << n << " = " << a << " + " << n - a << '\n';
        }
        else {
            cout << "Goldbach's conjecture is wrong.\n";
        }

    }
    return 0;

}