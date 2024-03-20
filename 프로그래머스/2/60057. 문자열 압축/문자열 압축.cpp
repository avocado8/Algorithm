#include <string>
#include <vector>

using namespace std;

int getShortest(string target, int unit_len) {
	int length = target.length();
	int new_len = length;
	int cnt = 1;
	int left = 0, right = unit_len;
	string prev_str = "";
	while(right<=length) {
		string curr_str = target.substr(left, unit_len);
		if (prev_str == curr_str) cnt++;
		else {
			if (cnt > 1) {
				new_len += to_string(cnt).length();
				new_len -= (cnt - 1) * unit_len;
			}
			prev_str = curr_str;
			cnt = 1;
		}
		left += unit_len;
		right += unit_len;
	}
	if (cnt > 1) {
		new_len += to_string(cnt).length();
		new_len -= (cnt - 1) * unit_len;
	}
	return new_len;
}

int solution(string str) {
	int ans = str.length();
	for (int i = 1; i <= str.length() / 2; i++) {
		ans = min(ans, getShortest(str, i));
	}
	return ans;
}