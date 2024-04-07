#include <iostream>
#include <vector>

using namespace std;
vector<bool>visited;

int dfs(int n, int index, vector<vector<int>>&li) {
	visited[index] = true;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (li[index][i] == 1 && !visited[i]) {
			cnt+=dfs(n, i, li);
		}
	}
	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	visited.assign(n, false);
	vector<vector<int>>li(n+1, vector<int>(n+1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		li[a][b] = li[b][a] = 1;
	}

	visited[1] = true;
	int answer = dfs(n,1, li);
	cout << answer - 1;

	return 0;
}
