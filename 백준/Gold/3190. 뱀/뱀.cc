#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int>ci;

int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
	//우 상 좌 하
	int dr[4] = { 0,-1,0,1 };
	int dc[4] = { 1, 0, -1, 0 };
	//뱀 초기화
	deque<ci>snake;
	snake.push_front(ci(0, 0));
	board[0][0] = 1;

	int t = 0, head = 0; //시간, 뱀 머리방향
	while (1) {
		t++;
		int nr = snake.front().first + dr[head];
		int nc = snake.front().second + dc[head];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) {
			break;
		}
		if (board[nr][nc] != 2) {
			//사과가 있지 않다면 꼬리가 위치한 칸을 비워줌
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		//다음 칸에 머리를 위치시킴
		snake.push_front(ci(nr, nc));
		board[nr][nc] = 1;

		//방향 변환 확인
		if (cmd[t] == 'L')
			head = (head + 1) % 4;
		if (cmd[t] == 'D')
			head = (head + 3) % 4;
	}
	return t;
}

int solution(int n, int k, int l, vector<vector<int>>& apple, vector<int>& rot_t, vector<char>& rot_d) {
	vector<vector<int>> board(n, vector<int>(n)); //게임 보드판(nxn)
	map<int, char> cmd;
	for (int i = 0; i < k; i++) {
		board[apple[i][0] - 1][apple[i][1] - 1] = 2; //사과 표시
	}
	for (int i = 0; i < l; i++) {
		cmd[rot_t[i]] = rot_d[i];
	}
	int answer = playGame(n, board, cmd);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, l;
	cin >> n >> k;
	vector<vector<int>> apple(k, vector<int>(2)); //k행 2열의 2차원 벡터로 사과위치 저장
	for (int i = 0; i < k; i++) {
		cin >> apple[i][0] >> apple[i][1];
	}
	cin >> l;
	vector<int> rot_t(l); //시간
	vector<char> rot_d(l); //방향
	for (int i = 0; i < l; i++) {
		cin >> rot_t[i] >> rot_d[i];
	}
	int answer = solution(n, k, l, apple, rot_t, rot_d);
	cout << answer;
	return 0;
}