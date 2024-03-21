#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int>ci;

int solution(int n, vector<ci>& lec) {
	sort(lec.begin(), lec.end());
	priority_queue<int, vector<int>, greater<>>pq; //종료시간 저장
	pq.push(-1);
	for (int i = 0; i < n; i++) {
		//새로 들어온 시작시간이 기존 가장 빠른 종료시간보다 같거나 늦으면 같강의실 사용가능
		if (lec[i].first >= pq.top()) {
			pq.pop();
		}
		pq.push(lec[i].second);
	}
	return pq.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ci>lec(n, { 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> lec[i].first >> lec[i].second;
	}
	cout << solution(n, lec);
	return 0;
}