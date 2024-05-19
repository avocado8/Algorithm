#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int pre[10001];
int post[10001];
int postIdx = 0;

// solution 함수: 전위 순회 결과를 통해 BST를 구성하고 후위 순회 결과를 post 배열에 저장
void solution(int x, int y) {
    if (x >= y) return; // 종료조건 - 범위를 벗어날 경우
    if (x == y - 1) { // 노드가 하나 남았을 경우
        post[postIdx++] = pre[x];
        return;
    }

    // 루트보다 작은 값들은 왼쪽 서브트리에, 큰 값들은 오른쪽 서브트리에 위치
    int idx = x + 1;
    while (idx < y && pre[idx] < pre[x]) {
        idx++;
    }
    solution(x + 1, idx); // 왼쪽 서브트리 재귀 호출
    solution(idx, y); // 오른쪽 서브트리 재귀 호출
    post[postIdx++] = pre[x]; // 루트 노드 처리
}

int main() {
    int n, i = 0;
    // 전위 순회 결과 입력받기
    while (cin >> n) {
        pre[i++] = n;
    }

    // BST 구성 및 후위 순회 수행
    solution(0, i);

    // 후위 순회 결과 출력
    for (int j = 0; j < postIdx; j++) {
        cout << post[j] << endl;
    }

    return 0;
}
