#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
typedef pair<int, int>ci;
int board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void dragonCurve(int x, int y, int d, int g) {
    deque<ci> curve;
    curve.push_front({ x,y }); //시작
    curve.push_back({ x + dx[d], y + dy[d] }); //끝점
    board[x][y] = 1;
    board[x + dx[d]][y + dy[d]] = 1;

    for (int i = 0; i < g; i++) {
        int s = curve.size();
        ci end_point = curve.back(); //현재 드래곤커브 끝점
        for (int j = s - 2; j >= 0; j--) { //이전 세대의 커브들을 현재 끝점에 대해 회전
            //커브를 끝점 기준으로 시계방향 90도 회전
            //회전할 점 (curve[j].first, curve[j].second)
            int nx = end_point.first + (end_point.second - curve[j].second);
            int ny = end_point.second - (end_point.first - curve[j].first);
            curve.push_back(ci(nx, ny));
            board[nx][ny] = 1; //보드에 드래곤커브 표시
        }
    }
}

int main() {
    int n, x, y, d, g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        dragonCurve(x, y, d, g);
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) { //사각형을 이루는 네 점이 모두 드래곤커브에 속할 때
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
