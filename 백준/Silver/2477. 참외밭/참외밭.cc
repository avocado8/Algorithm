#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[6][2]; //들어오는 6개의 입력을 저장할 배열
int dir[4];

int solution(int k) {
    //각 방향의 등장 횟수
    for (int i = 0; i < 6; i++) {
        dir[board[i][0]]++;
    }
    
    int a1 = 1, a2 = 1;

    for (int i = 0; i < 6; i++) {
        //큰 사각형 가로세로 = 한 번씩 나오는 방향으로 갔을 때의 길이
        if (dir[board[i][0]] == 1) {
            a1 *= board[i][1];
            continue;
        }
        if (board[i][0] == board[(i + 2) % 6][0]) {
            a2 *= board[(i + 1) % 6][1];
        }
    }

    int area = a1 - a2;
    return area * k;

}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> board[i][0] >> board[i][1];
    }
    cout << solution(k);
    return 0;
}
