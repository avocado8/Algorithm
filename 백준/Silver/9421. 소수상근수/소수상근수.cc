#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
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

bool isSgs(int n) {
	map<int, bool> is_visited;
	int tmp = n;
	while (1) {
		int res = 0;
		while (tmp) {
			res += (tmp % 10) * (tmp % 10);
			tmp /= 10;
		}
		if (res == 1) {
			return true;
		}
		if (!is_visited[res]) {
			is_visited[res] = true;
		}
		else {
			return false;
		}
		tmp = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool>is_prime = isPrime(MAX);
	for (int i = 0; i < n; i++) {
		if (is_prime[i] && isSgs(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}