#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) return; //이미 같은 집합에 속해 있다면 return
	if (parent[xp] < parent[yp]) {
		swap(xp, yp);
	}
	//집합 크기가 더 큰 쪽에다 합침
	parent[yp] += parent[xp];
	//새로운 루트 yp
	parent[xp] = yp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cmd, a, b;
	cin >> n >> m;
	parent.assign(n + 1, -1);
	while (m--) {
		cin >> cmd >> a >> b;
		if (cmd==0) { //합집합
			unionInput(a, b);
		}
		else { //find
			if (findParent(a) == findParent(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
