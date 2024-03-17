#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>>pq;
int solution(int a) {
	int res = 0;
	if (a == 0) {
		if (pq.empty()) {
			res = -1;
		}
		else {
			res = pq.top();
			pq.pop();
		}
	}
	else {
		for (int i = 0; i < a; i++) {
			int gift;
			cin >> gift;
			pq.push(gift);
		}
		res = -2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		int res = solution(a);
		if (res != -2) {
			cout << res << "\n";
		}
		
	}
	return 0;
}