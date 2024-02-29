#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string str) {
	stack<char> st;
	int res = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push(str[i]);
		}
		else { //닫힌 괄호라면
			st.pop();
			if (str[i-1] == '(') {
				res += st.size();
			}
			else {
				res++;
			}
		}
	}
	return res;
}

int main() {
	string str;
	cin >> str;
	int res = solution(str);
	cout << res;
	return 0;
}

