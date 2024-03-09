#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int cnt=0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i+1]) cnt++;
	}
	if (cnt == 0) cout << cnt;
	else cout << cnt / 2;

	return 0;
}