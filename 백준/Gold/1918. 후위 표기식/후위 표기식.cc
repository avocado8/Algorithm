#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void toPostfix(string exp) {
	char ch, top_op;
	int len = exp.length();
	stack<char>s;
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '/': case '*':
			while (!s.empty() && (prec(s.top()) >= prec(ch)) ) {
				cout << s.top();
				s.pop();
			}
			s.push(ch);
			break;
		case '(':
			s.push(ch);
			break;
		case ')':
			top_op = s.top();
			s.pop();
			while (top_op != '(') {
				cout << top_op;
				top_op = s.top();
				s.pop();
			}
			break;
		default:
			cout << ch;
			break;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	string exp;
	cin >> exp;
	toPostfix(exp);
}

