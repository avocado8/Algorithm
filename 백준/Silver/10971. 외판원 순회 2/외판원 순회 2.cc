#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e8;

vector<bool>visited;
vector<vector<int>>matrix;
int ans = INF;

void backtracking(int n, int cnt, int cur_city, int cost) {
	if (cost >= ans) return;
	//종료 조건(n개 도시 순회)
	if (cnt == n) {
		//시작점으로 돌아오기
		if (matrix[cur_city][0] != 0) {
			ans = min(ans, cost + matrix[cur_city][0]);
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		//길이 있고, 아직 방문x
		if (matrix[cur_city][i] && !visited[i]) {
			visited[i] = true;
			backtracking(n, cnt + 1, i, cost + matrix[cur_city][i]);
			visited[i] = false;
		}
	}
}

int solution(int n, vector<vector<int>>& cost) {
	visited.assign(n, false);
	matrix = cost;
	
	visited[0] = true;
	backtracking(n, 1, 0, 0);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<vector<int>> cost;
	int answer;

	//입력
	cin >> n;
	cost.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	answer = solution(n, cost);

	//출력
	cout << answer;
	return 0;
}
