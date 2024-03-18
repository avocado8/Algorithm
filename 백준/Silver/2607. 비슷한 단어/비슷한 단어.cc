#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> wordCount(string s) {
	vector<int>cnt(26, 0);
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A']++;
	}
	return cnt;
}

int solution(int n, vector<string>vec) {
	int res = 0;
	string target = vec[0];
	vector<int>target_cnt = wordCount(target);
	for (int i = 1; i < vec.size(); i++) {
		int flag = 0;
		int a = 0, b = 0;
		string cmp = vec[i];
		vector<int>cmp_cnt = wordCount(cmp);
		for (int j = 0; j < 26; j++) {
			if (target_cnt[j] == cmp_cnt[j]) continue;
			if (abs(target_cnt[j] - cmp_cnt[j]) > 1) {
				flag = 1;
				break;
			}
			else if (target_cnt[j] < cmp_cnt[j]) {
				a++;
			}
			else if (target_cnt[j] > cmp_cnt[j]) {
				b++;
			}
			if (a > 1 || b > 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		res++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cout << solution(n, vec);
	return 0;
}