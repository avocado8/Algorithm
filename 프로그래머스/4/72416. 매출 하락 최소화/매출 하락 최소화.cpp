#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>dp;

vector<vector<int>> makeTree(int n, vector <vector<int>>& links) {
	//links 벡터를 기반으로 트리 생성
	vector<vector<int>>tree(n, vector<int>(0));
	for (int i = 0; i < links.size(); i++) {
		tree[links[i][0]].push_back(links[i][1]);
	}
	return tree;
}

int fillDp(vector<int>& sales, vector<vector<int>>& tree, int node, bool flag) {
	if (dp[node][flag] != -1) {
		return dp[node][flag];
	}
	if (tree[node].empty()) { //리프노드... 자식없음
		return dp[node][flag] = flag ? sales[node - 1] : 0;
	}
	dp[node][flag] = 0;
	bool attend_flag = false;
	int diff = INT32_MAX;	
	for (int i = 0; i < tree[node].size(); i++) { //자식 탐색
		int next_node = tree[node][i]; //부하직원
		int attend = fillDp(sales, tree, next_node, true);
		int absent = fillDp(sales, tree, next_node, false);
		dp[node][flag] += min(attend, absent);
		if (attend < absent) { //부하 한명이라도 참석했다면
			attend_flag = true;
		}
		diff = min(diff, attend - absent); //모두가 불참했을 때를 대비
	}
	if (flag) {
		return dp[node][flag] += sales[node - 1];
	}
	if (!attend_flag) { //팀장 팀원 모두 불참
		return dp[node][flag] += diff;
	}
	return dp[node][flag];
}

int solution(vector<int>sales, vector<vector<int>>links) {
	int v = sales.size();
	dp.assign(v + 1, vector<int>(2, -1));
	vector<vector<int>>tree = makeTree(v + 1, links);
	return min(fillDp(sales, tree, 1, true), fillDp(sales, tree, 1, false));
}