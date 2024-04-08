#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 19;

vector<vector<int>>board(MAX, vector<int>(MAX, 0));
bool dfs_visited[MAX][MAX][4];
vector<pair<int, int>> stones(5, { 0,0 });

int dx[4] = { 1,1,0,-1 }; //오른쪽 오른쪽아래 아래 왼쪽아래
int dy[4] = { 0,1,1,1 };

int dfs(int x, int y, int k, int val, int cnt) {
	dfs_visited[y][x][k] = true;
	stones.push_back({ y,x });
	int nx = x + dx[k];
	int ny = y + dy[k];
	if (!(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) || board[ny][nx] != val) {
		return cnt;
	}
	return dfs(nx, ny, k, val, cnt + 1);
}

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int solution() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (board[i][j] == 0) continue;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
					if (board[ny][nx] == board[i][j] && !dfs_visited[i][j][k]) {
						stones.clear();
						stones.push_back({ i,j });
						dfs_visited[i][j][k] = true;
						if (dfs(nx, ny, k, board[i][j], 2) == 5) {
							sort(stones.begin(), stones.end(), cmp);
							return board[i][j];
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> board[i][j];
		}
	}
	int answer = solution();
	cout << answer << "\n";
	if (answer) {
		cout << stones[0].first + 1 << ' ' << stones[0].second + 1;
	}
	

	return 0;
}
