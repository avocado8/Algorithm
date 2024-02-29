#include <string>
#include <vector>

using namespace std;

int getShortest(string s, int n) {
	int len = s.length();
	string prev_substr = ""; //기준 문자열
	int count = 1; //반복횟수
	int new_len = len;

	int left = 0; //서브스트링의 왼쪽 인덱스
	int right = n; //오른쪽 인덱스

	while (right <= len) {
		string curr_substr = s.substr(left, n); //해당 인덱스까지 자른 서브스트링
		if (prev_substr == curr_substr) { //둘이 같으면 => 이 서브스트링이 반복되었다는 뜻
			count++; //반복횟수 추가
		}
		else { //다르면 => 다른 서브스트링이 등장함
			if (count > 1) { //압축되었다면
				new_len += to_string(count).length(); //abab -> 2ab와 같은 식으로 할거니까 반복횟수 숫자만큼 길이추가
				new_len -= (count - 1) * n; //압축된 서브스트링은 하나만 남기고 없어져야 하니까 그만큼 전체길이에서 빼줌
			}
			//다른 서브스트링이 등장했으므로 비교 기준이 되는 문자열 바꿔줌
			prev_substr = curr_substr;
			//반복 횟수 초기화
			count = 1;
		}
		left += n;
		right += n;
	}
	//반복 끝났을 때 압축 문자열 남아있는지 확인
	if (count > 1) {
		new_len += to_string(count).length();
		new_len -= (count - 1) * n;
	}
	return new_len;
}

int solution(string s) {
	int res = s.length();
	for (int i = 1; i <= s.length(); i++) {
		res = min(res, getShortest(s, i));
	}
	return res;
}
