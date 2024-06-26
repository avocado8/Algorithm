#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> cost;

int friendCost(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] < 0) { //루트정점 친구비 더해줌
			sum += cost[i];
		}
	}
	return sum;
}

int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) { //이미 같은 집합에 속해 있다면
		return;
	}
	if (cost[xp] > cost[yp]) { //xp의 cost를 더 작게 함
		swap(xp, yp);
	}
	//cost 작은 쪽으로 union - 새로운 루트 xp
	parent[yp] = xp;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k, v, w;
	cin >> n >> m >> k;
	parent.assign(n + 1, -1);
	cost.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	while (m--) {
		cin >> v >> w;
		unionInput(v, w);
	}
	int ans = friendCost(n);
	if (ans <= k) cout << ans;
	else cout << "Oh no";
	return 0;
}
