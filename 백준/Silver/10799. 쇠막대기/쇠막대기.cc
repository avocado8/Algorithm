#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
	stack<char>st;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			st.pop();
			if (s[i - 1] == '(') {
				cnt += st.size();
			}
			else {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << solution(s);
	return 0;
}