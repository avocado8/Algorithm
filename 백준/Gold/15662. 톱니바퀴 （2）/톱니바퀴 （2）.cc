#include <iostream>
#include <vector>

using namespace std;

// 시계방향 회전 함수
string turnClockwise(string oneState) {
    return oneState[7] + oneState.substr(0, 7);
}

// 반시계방향 회전 함수
string turnCounterclockwise(string oneState) {
    return oneState.substr(1, 7) + oneState[0];
}

// 톱니바퀴 회전 함수
void turnWheels(int num, int wise, vector<string> &state) {
    int T = state.size();
    vector<int> turnNum(T, 0);  // 각 톱니바퀴가 회전하는 방향을 저장할 벡터
    turnNum[num - 1] = wise;  // 현재 톱니바퀴 회전 방향 저장

    // 왼쪽 톱니바퀴들이 회전하는지 확인
    for (int i = num - 1; i > 0; i--) {
        if (state[i][6] != state[i - 1][2]) {
            turnNum[i - 1] = -turnNum[i]; 
        } else {
            break;  
        }
    }

    // 오른쪽 톱니바퀴들이 회전하는지 확인
    for (int i = num - 1; i < T - 1; i++) {
        if (state[i][2] != state[i + 1][6]) {
            turnNum[i + 1] = -turnNum[i];  
        } else {
            break;  
        }
    }

    // 각 톱니바퀴 회전시키기
    for (int i = 0; i < T; i++) {
        if (turnNum[i] == 1) {
            state[i] = turnClockwise(state[i]);
        } else if (turnNum[i] == -1) {
            state[i] = turnCounterclockwise(state[i]);
        }
    }
}

// S극이 12시 방향에 있는 톱니바퀴의 개수 계산 함수
int makeCount(const vector<string> &state) {
    int count = 0;
    for (string s : state) {
        if (s[0] == '1') count++;  
    }
    return count;
}

int main() {
    // 입력
    int T, K;
    cin >> T;

    vector<string> state(T);
    for (int i = 0; i < T; i++) {
        cin >> state[i];
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, wise;
        cin >> num >> wise;
        // 연산
        turnWheels(num, wise, state);
    }

    int count = makeCount(state);
    // 출력
    cout << count << endl;

    return 0;
}