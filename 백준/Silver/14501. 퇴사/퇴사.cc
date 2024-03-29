#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>>li;
//dp - 첫째날 상담이 3일 걸리고 이익이 10이라면, 10을 배열의 4,5,6,7에 저장

int dpBottomup(vector<int> dp, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + li[i].first; j <= n; j++) { //n+1일에 퇴사할거니까 n까지 반복
			dp[j] = max(dp[j], dp[i] + li[i].second);
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int duration, cost;
		cin >> duration >> cost;
		li.push_back(make_pair(duration, cost));
	}
	int answer = dpBottomup(dp, n);
	cout << answer;
	return 0;
}
