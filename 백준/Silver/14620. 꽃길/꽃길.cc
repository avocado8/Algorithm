#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 30000;

int getScore(int r, int c, vector<vector<int>>&gr) { //씨앗의 중심이 주어졌을 때 상하좌우 다섯칸의 값의 합
	return gr[r - 1][c] + gr[r][c - 1] + gr[r + 1][c] + gr[r][c + 1] + gr[r][c];
}

int solution(int n, vector<vector<int>>&gr) {
	int ans = MAX;
	int r1, c1, r2, c2, r3, c3;
	n -= 2; //가장자리는 골라서는 안되니까
	for (int i = 0; i < n * n; i++) {
		//첫번째 씨앗 위치
		r1 = i / n + 1;
		c1 = i % n + 1;
		for (int j = 0; j < n * n; j++) {
			//두번째 씨앗 위치
			r2 = j / n + 1;
			c2 = j % n + 1;
			if (abs(r1 - r2) + abs(c1 - c2) <= 2) { //겹쳐서 죽는 경우
				continue;
			}
			for (int k = 0; k < n * n; k++) {
				//세번째 씨앗 위치
				r3 = k / n + 1;
				c3 = k % n + 1;
				if ((abs(r1 - r3) + abs(c1 - c3) <= 2) || (abs(r2 - r3) + abs(c2 - c3) <= 2)){
					continue;
				}
				ans = min(ans, getScore(r1, c1, gr) + getScore(r2, c2, gr) + getScore(r3, c3, gr));
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>>gr;
	gr.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gr[i][j];
		}
	}
	cout << solution(n, gr);
	return 0;
}