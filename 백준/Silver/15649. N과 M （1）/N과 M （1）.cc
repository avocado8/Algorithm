#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

int n, m;
bool is_used[MAX + 1];
int sequence[MAX];

void print() {
	for (int i = 0; i < m; i++) {
		cout << sequence[i] << ' ';
	}
	cout << '\n';
}

void backtrack(int idx) {
	//탈출조건 (n개 숫자 다 뽑음)
	if (idx == m) {
		print();
		return;
	}
	for (int i = 1; i <= n; i++) {
		//이미 사용한 숫자라면 skip
		if (is_used[i]) continue;

		//선택한 숫자 저장
		sequence[idx] = i;
		is_used[i] = true;

		//다음 인덱스 탐색
		backtrack(idx + 1);

		//백트래킹 호출 종료시 사용한 숫자 반납
		is_used[i] = false;
	}
}

int main() {
	cin >> n >> m;
	backtrack(0);
	return 0;
}
