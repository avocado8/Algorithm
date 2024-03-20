#include <string>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> makeTree(int n, vector<vector<int>>& links) {
	vector<vector<int>> tree(n, vector<int>(0));
	for (int i = 0; i < links.size(); i++) {
		tree[links[i][0]].push_back(links[i][1]);
	}
	return tree;
}

int fillDp(vector<int>& sales, vector<vector<int>>& tree, int node, bool flag) {
	if (dp[node][flag] != -1) return dp[node][flag];
	if (tree[node].empty()) { //리프노드
		return dp[node][flag] = flag ? sales[node - 1] : 0;
	}
	dp[node][flag] = 0;
	bool attend_flag = false; //부하직원 중 한명이라도 참석했는지
	int diff = INT32_MAX;
	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i];
		int attend = fillDp(sales, tree, next_node, true); //부하 참석
		int absent = fillDp(sales, tree, next_node, false); //부하 불참
		dp[node][flag] += min(attend, absent);
		if (attend < absent) { //부하가 참석했다면
			attend_flag = true;
		}
		diff = min(diff, attend - absent);
	}
	if (flag) return dp[node][flag] += sales[node - 1];
	if (!attend_flag) {
		//팀장, 부하 모두 불참
		return dp[node][flag] += diff;
	}
	return dp[node][flag];
}

int solution(vector<int>sales, vector<vector<int>>links) {
	int v = sales.size();
	dp.assign(v + 1, vector<int>(2, -1));
	vector <vector<int>> tree = makeTree(v + 1, links);
	return min(fillDp(sales, tree, 1, true), fillDp(sales, tree, 1, false));
}