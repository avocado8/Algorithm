#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int total_time, cheese_cnt;
vector<vector<int>>board;
vector < vector<bool>>visited;

int dx[] = { 1,-1,0,0 }; //동서남북 방향
int dy[] = { 0,0,1,-1 };

void bfs() {
	queue<ci> q; //검사해야하는 공기 위치
	queue<ci> tmp; //가장자리 치즈 위치(이번 턴에 녹는 치즈. 다음 턴에는 공기)
	q.push(ci(0, 0)); //지금 검사하는 요소 제거
	
	while (!q.empty()) {
		cheese_cnt = q.size(); //첫턴 이후에는 tmp값

		//이번 턴에 녹는 치즈 검사
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop(); //현재 검사하는 요소 제거
			for (int i = 0; i < 4; i++) { //동서남북 칸 검사
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) { //새 인덱스가 보드판 칸 안에 있는지
					if (!visited[new_x][new_y] && board[new_x][new_y] == 1) { //방문한 적 없는 이번턴 녹을 수 있는 치즈
						tmp.push(ci(new_x, new_y));
					}
					else if (!visited[new_x][new_y] && board[new_x][new_y] == 0) { //방문한 적 없는 공기
						//이번 턴에 녹을 수 있는 치즈가 있는지 검사
						q.push(ci(new_x, new_y));
					}
					visited[new_x][new_y] = true;
				}
			}
		}
		while (!tmp.empty()) {
			q.push(tmp.front());
			tmp.pop();
		}
		total_time++;
	}
}

int main() {
	cin >> n >> m;
	total_time = 0, cheese_cnt = 0;
	board.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	//연산
	visited[0][0] = true;
	bfs();
	cout << total_time - 1 << '\n'; //while문 마지막에 total_time을 증가시켰으므로 하나 더 많게 되니 1을 빼줌
	cout << cheese_cnt << '\n';
	return 0;
}
