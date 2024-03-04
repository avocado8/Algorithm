#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;

int gcdIter(int a, int b) {
	if (a < b) swap(a, b);

	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

vector<int> factor(int a) {
	vector<int>res;
	for (int i = 2; i <= (a/2); i++) {
		if (a % i == 0) {
			res.push_back(i);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int>num(n, 0);
	vector<int>diff(n - 1);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		diff[i - 1] = abs(num[i] - num[i - 1]);
	}

	int gcd = diff[0];
	vector<int>res;
	if (diff.size() == 1) {
		gcd = diff[0];
	}
	else {
		for (int i = 1; i < diff.size(); i++) {
			gcd = gcdIter(gcd, diff[i]);
		}
	}

	for (int i = 2; i <= gcd/2; i++) {
		if (gcd % i == 0) {
			res.push_back(i);
		}
	}
	res.push_back(gcd);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}


	return 0;
}