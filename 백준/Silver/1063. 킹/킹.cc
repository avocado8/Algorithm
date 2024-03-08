#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int>ct;

void chess(string king, string stone, vector<string>op, int n) {
	pair<int, int> k = { king[0], king[1]};
	pair<int, int> s = { stone[0], stone[1]};
	map<string, ct>move = { {"R",{1,0}}, {"L",{-1,0}}, {"B",{0,-1}}, {"T",{0,1}},
	{"RT",{1,1}}, {"LT",{-1,1}}, {"RB",{1,-1}}, {"LB",{-1,-1}} };
	for (int i = 0; i < n; i++) {
		ct cur_move = move[op[i]]; //1,0과 같은 pair
		int k_next_x = k.first + cur_move.first;
		int k_next_y = k.second + cur_move.second;
		if (k_next_x <= 72 && k_next_y <= 56 && k_next_x > 64 && k_next_y > 48) {
			//킹 이동위치 = 돌 위치
			if (k_next_x == s.first && k_next_y == s.second) {
				int s_next_x = s.first + cur_move.first;
				int s_next_y = s.second + cur_move.second;
				if (s_next_x <= 72 && s_next_y <= 56 && s_next_x > 64 && s_next_y > 48) {
					k = { k_next_x, k_next_y };
					s = { s_next_x, s_next_y };
				}
			}
			else {
				k = { k_next_x, k_next_y };
			}
		}
	}
	cout << char(k.first) << char(k.second) << "\n";
	cout << char(s.first) << char(s.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string king, stone;
	cin >> king >> stone >> n;
	vector<string>op(n);
	for (int i = 0; i < n; i++) {
		cin >> op[i];
	}
	chess(king, stone, op, n);

	return 0;
}