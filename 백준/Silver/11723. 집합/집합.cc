#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int s = 0;

void add(int n) {
	//추가: 해당 인덱스를 1로 표기
	s = s | (1 << n);
}
void remove(int n) {
	//삭제: 해당 인덱스를 0으로 표기
	//1을 0으로 바꿔야하니까 ~(1<<n)과 and
	s = s & ~(1 << n);
}

int check(int n) {
	//있음 : 해당 인덱스가 1, 없음: 0
	if (s & (1 << n)) {
		return 1;
	}
	else return 0;
}

void toggle(int n) {
	if (s & (1 << n)) {
		remove(n);
	}
	else add(n);
}

void all(){
	s = (1 << 21) - 1;
}

void empty() {
	s = 0;
}

int solution(string op, int x) {
	if (op == "add") {
		add(x);
	}
	else if (op == "remove") {
		remove(x);
	}
	else if (op == "check") {
		return check(x);
	}
	else if (op == "toggle") {
		toggle(x);
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for (int i = 0; i < m;i++) {
		string op;
		cin >> op;
		if (op == "all") {
			all();
		}
		else if (op == "empty") {
			empty();
		}
		else {
			int x;
			cin >> x;
			int ans = solution(op, x);
			if (ans != -1) cout << ans << "\n";
		}
	}

	return 0;
}