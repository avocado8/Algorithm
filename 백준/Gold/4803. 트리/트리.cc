#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> cycle;

int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) { //이미 같은 집합에 속해 있다면 사이클 발생, union하지 않음
		cycle[xp] = true;
		return;
	}
	if (cycle[xp] || cycle[yp]) { //다른 집합에 속해 있지만 하나라도 사이클이 있는 집합이면
		cycle[xp] = cycle[yp] = true;
	}
	if (parent[xp] < parent[yp]) {
		swap(xp, yp);
	}
	//집합 크기가 더 큰 쪽에다 합침
	parent[yp] += parent[xp];
	//새로운 루트 yp
	parent[xp] = yp;
}

int cntTree(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] < 0 && !cycle[i]) { //루트 정점이면서 사이클이 없음
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b, num = 0;

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		num++;
		parent.assign(n + 1, -1);
		cycle.assign(n + 1, false);
		while (m--) {
			cin >> a >> b;
			unionInput(a, b);
		}
		int ans = cntTree(n);
		cout << "Case " << num;
		switch (ans) {
		case 0:
			cout << ": No trees.\n";
			break;
		case 1:
			cout << ": There is one tree.\n";
			break;
		default:
			cout << ": A forest of " << ans << " trees.\n";
			break;
		}
	}

	return 0;
}
