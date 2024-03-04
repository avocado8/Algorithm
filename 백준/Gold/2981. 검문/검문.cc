#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;

int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

vector<int> makeDiffVec(vector<int>num) {
	int n = num.size();
	vector<int>diff(n - 1);
	for (int i = 1; i <= n - 1; i++) {
		diff[i - 1] = abs(num[i] - num[i - 1]);
	}
	return diff;
}

vector<int> findNums(vector<int>diff) {
	vector<int>res;
	int gcd = diff[0];
	for (int i = 1; i < diff.size(); i++) {
		gcd = gcdIter(gcd, diff[i]);
	}

	for (int i = 2; i <= gcd / 2; i++) {
		if (gcd % i == 0) {
			res.push_back(i);
		}
	}
	res.push_back(gcd);
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
	diff = makeDiffVec(num);
	
	vector<int>res = findNums(diff);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}


	return 0;
}