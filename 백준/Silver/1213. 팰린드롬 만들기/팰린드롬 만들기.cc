#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int SIZE = 26;
vector<int> countAlp(string s) {
	vector<int> count(SIZE, 0);
	for (int i = 0; i < s.size(); i++) {
		count[s[i] - 'A']++;
	}
	return count;
}

string makePalindrome(vector<int>& count) {
	string p1 = "", p2 = "", p3 = "";
	for (int i = 0; i < SIZE; i++) {
		if (count[i] % 2 == 1) {
			if (p2.size() == 1) {
				return "I'm Sorry Hansoo";
			}
			p2 = (char)(i + 'A');
		}
		for (int j = 0; j < count[i] / 2; j++) {
			p1 = p1 + (char)(i + 'A');
			p3 = (char)(i + 'A') + p3;
		}
	}
	return p1 + p2 + p3;
}

string solution(string s) {
	vector<int>count = countAlp(s);
	return makePalindrome(count);
}

int main() {
	string s;
	cin >> s;
	cout << solution(s);
	return 0;
}

