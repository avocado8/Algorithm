#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

typedef pair<int, int> frac;

frac fracSum(int u1, int d1, int u2, int d2) {
	frac res;
	int dres = d1 * d2;
	int ures = u1 * d2 + u2 * d1;
	int gcd = gcdIter(dres, ures);
	res.first = ures / gcd;
	res.second = dres / gcd;
	return res;
}

int main() {
	int u1, d1, u2, d2;
	cin >> u1 >> d1 >> u2 >> d2;
	frac res = fracSum(u1, d1, u2, d2);
	cout << res.first << ' ' << res.second;
	return 0;
}

