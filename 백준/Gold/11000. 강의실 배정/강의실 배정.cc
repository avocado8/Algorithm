#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int>ci;

int arrayRoom(int n, vector<ci>lec) {
	priority_queue<int, vector<int>, greater<>> pq;
	pq.push(0);
	//입력으로 들어오는 값은 시작시각 기준으로 정렬되어 있음
	//우선순위큐에 저장할 값은 종료시각임
	for (int i = 0; i < n; i++) {
		if (lec[i].first >= pq.top()) {
			//시작시간이 이전 종료시간보다 같거나 느림 -> 같은 강의실 사용 가능
			pq.pop();
		}
		pq.push(lec[i].second); //기존 강의실 정보 갱신 or 새로운 강의실 정보 저장
	}
	return pq.size();
}

int main() {
	int n;
	cin >> n;
	vector<ci>lec(n, ci(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> lec[i].first >> lec[i].second;
	}
	sort(lec.begin(), lec.end());
	cout << arrayRoom(n, lec) << '\n';
	return 0;
}

