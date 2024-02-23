#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main() {

	while (true) {
		string s;
		getline(cin, s);
		stack<char> basket;
		if (s[0] == '.') break;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '(': case '[':
				basket.push(s[i]);
				break;
			case ')':
				if (!basket.empty() && basket.top() == '(') basket.pop();
				else {
					basket.push(')');
				}
				break;
			case ']':
				if (!basket.empty() && basket.top() == '[') basket.pop();
				else {
					basket.push(']');
				}
				break;
			}
		}
		if (basket.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}

