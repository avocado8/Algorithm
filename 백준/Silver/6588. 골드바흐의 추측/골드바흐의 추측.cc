#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 전역 변수
const int MAX_LIMIT = 1000000;
vector<bool> is_prime(MAX_LIMIT + 1, true);
vector<int> primes;

// 에라토스테네스의 체를 사용하여 전체 소수 목록 생성
void erato() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(MAX_LIMIT); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 소수 목록을 벡터에 추가
    for (int i = 3; i <= MAX_LIMIT; i += 2) { // 홀수 소수만 추가한다. 
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

// 두 소수의 합으로 n을 나타낼 수 있는지 확인
string find_goldbach(int n) {
    for (int prime : primes) {
        if (prime > n / 2) break; // a가 n/2보다 크면 끝낸다. 

        int b = n - prime;
        if (is_prime[b]) { // b가 소수인 경우에, 즉 찾았다. 
            return to_string(n) + " = " + to_string(prime) + " + " + to_string(b);
        }
    }

    return "Goldbach's conjecture is wrong.";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    erato(); // 소수 목록을 미리 계산

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        cout << find_goldbach(n) << "\n";
    }

    return 0;
}