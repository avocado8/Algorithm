#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int printerQueue(int n, int m, vector<int>pri) {
	int result = 0;
	queue<int>printer;
	for (int i = 0; i < pri.size(); i++) {
		printer.push(pri[i]);
	}
	sort(pri.begin(), pri.end());
	while (1) {
		if (printer.front() == pri[pri.size() - 1]) {
			result++;
			printer.pop();
			pri.pop_back();
			if (m == 0) break;
		}
		else {
			printer.push(printer.front());
			printer.pop();
		}
		if (m == 0) {
			m = printer.size() - 1;
		}
		else {
			m -= 1;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;
		vector<int>pri(n);
		for (int j = 0; j < n; j++) {
			cin >> pri[j];
		}
		cout << printerQueue(n, m, pri) << '\n';
	}
	
	return 0;
}