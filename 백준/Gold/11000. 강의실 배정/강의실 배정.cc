#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int>ci;

int sugang(int n, vector<ci>subject) {
	//시작 시간 오름차순 정렬
	sort(subject.begin(), subject.end());
	//큐에는 종료시각을 오름차순으로 저장
	priority_queue<int, vector<int>, greater<>>pq;
	pq.push(-1);
	for (int i = 0; i < n; i++) {
		if (subject[i].first >= pq.top()) {
			//시작시각이 종료시각보다 늦다면 같은 강의실 사용가능
			pq.pop();
		}
		//종료시각 큐에 푸시
		pq.push(subject[i].second);
	}
	return pq.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ci>lec(n);
	for (int i = 0; i < n; i++) {
		cin >> lec[i].first >> lec[i].second;
	}
	cout << sugang(n, lec);
	
	return 0;
}