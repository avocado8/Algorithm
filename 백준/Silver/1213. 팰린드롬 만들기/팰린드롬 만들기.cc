#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 26;

vector<int> alpCnt(string str) {
	vector<int>cnt(SIZE, 0);
	for (int i = 0; i < str.size(); i++) {
		cnt[str[i] - 'A']++;
	}
	return cnt;
}

string solution(string str) {
	vector<int>cnt = alpCnt(str);
	string p1 = "", p2 = "", p3 = "";
	for (int i = 0; i < SIZE; i++) {
		if (cnt[i] % 2 == 1) {
			if (p2.size() == 1) return "I'm Sorry Hansoo";
			p2 = (char)(i + 'A');
		}
		for (int j = 0; j < cnt[i] / 2; j++) {
			p1 = p1 + (char)(i + 'A');
			p3 = (char)(i + 'A') + p3;
		}
	}
	return p1 + p2 + p3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << solution(s);
	
}
