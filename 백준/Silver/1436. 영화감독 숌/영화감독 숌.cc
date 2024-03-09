#include <iostream>
#include <string>

using namespace std;
typedef pair<int, int>ct;

int getNum(int n) {
	int cnt = 0;
	int start = 666;
	while (1) {
		string start_str = to_string(start);
		if (start_str.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == n) {
			break;
		}
		start++;
	}
	return start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << getNum(n);
	return 0;
}