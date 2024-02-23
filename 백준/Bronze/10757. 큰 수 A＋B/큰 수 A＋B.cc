#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string sum(string a, string b) {
	int carry = 0;
	string result;
	int len = max(a.length(), b.length());
	a = string(len - a.length(), '0') + a;
	b = string(len - b.length(), '0') + b;
	for (int i = len - 1; i >= 0; i--) {
		int tmp_sum = (a[i] - '0') + b[i] - '0' + carry;
		carry = tmp_sum / 10;
		result += (tmp_sum % 10) + '0';
	}
	if (carry == 1) result += '1';
	reverse(result.begin(), result.end());
	return result;
}


int main() {
	string a, b;
	cin >> a >> b;
	cout << sum(a, b);
}

