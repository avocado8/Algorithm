#include <string>
#include <vector>

using namespace std;

int getShortest(string target, int unit_length) {
	int length = target.length();
	int new_len = length;
	int left = 0, right = unit_length;
	string prev_str = "";
	int cnt = 1;
	while (right <= length) {
		string curr_str = target.substr(left, unit_length);
		if (prev_str == curr_str) cnt++;
		else {
			if (cnt > 1) { //이미 압축됨
				new_len += to_string(cnt).length();
				new_len -= (cnt - 1) * unit_length;
			}
			prev_str = curr_str;
			cnt = 1;
		}
		left += unit_length;
		right += unit_length;
	}
	if (cnt > 1) {
		new_len += to_string(cnt).length();
		new_len -= (cnt - 1) * unit_length;
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
