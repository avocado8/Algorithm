#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getShortest(string target, int unit_length) {
	int len = target.length();
	int new_len = len;
	string prev_str = "";
	int count = 1;
	
	int left = 0;
	int right = unit_length;

	while (right <= len) {
		string curr_str = target.substr(left, unit_length);
		if (prev_str == curr_str) {
			count++;
		}
		else {
			if (count > 1) {
				new_len -= (count - 1) * unit_length;
				new_len += to_string(count).length();
			}
			prev_str = curr_str;
			count = 1;
		}
		left += unit_length;
		right += unit_length;
	}
	if (count > 1) {
		new_len -= (count - 1) * unit_length;
		new_len += to_string(count).length();
	}
	return new_len;
}

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= s.length()/2; i++) {
		answer = min(answer, getShortest(s, i));
	}
	return answer;
}