#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef pair<int, int>ci;

ci solution(int n) {
	if (n == 0) return { 1,0 };
	if (n == 1) return { 0,1 };
	vector<ci>dp(n+1, { 0,0 });
	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	for (int i = 2; i < n+1; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		ci res = solution(n);
		cout << res.first << ' ' << res.second << "\n";
	}
	
	return 0;
}