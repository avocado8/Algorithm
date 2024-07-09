#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0}; // 상하좌우

int board[51][51];
bool visited[51][51];

void dfs(int x, int y, int m, int n) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n && board[ty][tx] == 1 && !visited[ty][tx]) {
            dfs(tx, ty, m, n);
        }
    }
}

int main() {
    int t, m, n, k, x, y;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1; // 가로길이가 열임에 주의
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !visited[i][j]) {
                    dfs(j, i, m, n);
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
