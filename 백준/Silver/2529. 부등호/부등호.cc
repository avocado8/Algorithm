#include <iostream>
#include <vector>
#include <string>

using namespace std;
string max_num = "0123456789";
string min_num = "9876543210";
vector<char>brackets;
vector<int>choose;
vector<bool>is_used(10, false);

string chooseToString() {
	string num = "";
	for (int i = 0; i < choose.size(); i++ ) {
		num += to_string(choose[i]);
	}
	return num;
}

void updateAns() {
	string num = chooseToString();
	max_num = max(max_num, num);
	min_num = min(min_num, num);
}

void findMinMax(int idx) {
	//(부등호개수 +1개 숫자 다 뽑은 경우(종료조건)
	if (idx == brackets.size() + 1) {
		updateAns();
		return;
	}

	//0~9 정수 탐색
	for (int i = 0; i < 10; i++) {
		//이미 선택한 함수면 skip
		if (is_used[i]) continue;

		//선택한 숫자 저장
		is_used[i] = true;
		choose.push_back(i);

		//처음 숫자를 뽑는 경우 or 이전숫자 < 현재숫자 만족 or 이전숫자 > 현재숫자 만족
		if (idx == 0 || (brackets[idx - 1] == '<' && choose[choose.size() - 2] < i) || (brackets[idx - 1] == '>' && choose[choose.size() - 2] > i)) {
			//다음 인덱스 탐색
			findMinMax(idx + 1);
		}

		//재귀호출 종료시 숫자 반납
		is_used[i] = false;
		choose.pop_back();
	}
}

int main() {
	int k;
	cin >> k;
	brackets.assign(k, '<');
	for (int i = 0; i < k; i++) {
		cin >> brackets[i];
	}
	min_num = min_num.substr(0, k + 1);
	max_num = max_num.substr(0, k + 1);

	findMinMax(0);

	cout << max_num << '\n' << min_num;
	return 0;
}
