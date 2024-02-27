#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, char>ci;

string printWheel(int arrow_point, int n, vector<char>& wheel) {
	string res = "";
	int start = arrow_point;
	do {
		res += wheel[arrow_point];
		arrow_point = (arrow_point + 1) % n;
	} while (arrow_point != start);
	return res;
}

string solution(int n, vector<ci>& record) {
	vector<char>wheel(n, '?');
	vector<bool>check(26, false);

	int index = 0;
	for (int i = 0; i < record.size(); i++) {
		int rot = record[i].first;
		char alp = record[i].second;
		index = (index - rot%n + n) % n;
		if (wheel[index] == alp) {
			continue;
		}
		if (wheel[index] != '?' || check[alp - 'A']) {
			return "!";
		}
		wheel[index] = alp;
		check[alp - 'A'] = true;
	}
	return printWheel(index, n, wheel);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<ci>record(k, { 0,0 });
	for (int i = 0; i < k; i++) {
		cin >> record[i].first >> record[i].second;
	}
	cout << solution(n, record);
	return 0;
}

