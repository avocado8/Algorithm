#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX 1000000

using namespace std;

vector<bool> isPrime(int n) {
	vector<bool>is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i * i; j <= n; j += i) {
			if (!is_prime[j]) {
				continue;
			}
			is_prime[j] = false;
		}
	}
	return is_prime;
}

string goldbach(int n, vector<bool>& is_prime) {
	string s = "Goldbach's conjecture is wrong.";
	for (int i = 3; i <= n; i=i+2) {
		int tmp = n - i;
		if (is_prime[i] && is_prime[tmp] && tmp % 2 != 0) {
			s = to_string(n) + " = " + to_string(i) + " + " + to_string(tmp);
			break;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<bool>is_prime = isPrime(MAX);
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << goldbach(n, is_prime) << "\n";
	}
	return 0;
}

