#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int cnt[10]; // 0~9까지 숫자 개수
int answer = 0;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void backtracking(string res, int idx, int len) {
    if (idx == len) {
        int tmp = stoi(res);
        if (isPrime(tmp)) {
            answer++;
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i] == 0 || (idx == 0 && i == 0)) continue;
        cnt[i]--;
        backtracking(res + to_string(i), idx + 1, len);
        cnt[i]++;
    }
}

int solution(string numbers) {
    for (int i = 0; i < numbers.size(); ++i) {
        cnt[numbers[i] - '0']++;
    }
    int len = numbers.length();
    for (int i = 1; i <= len; i++) {
        // 각 숫자를 이용하여 가능한 모든 조합을 생성
        backtracking("", 0, i);
    }
    return answer;
}