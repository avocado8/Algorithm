#include <iostream>
#include <queue>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while (q.size() != 0) {
		for (int i = 0; i < k-1; i++) {
			int deletedP = q.front();
			q.pop();
			q.push(deletedP);
		}
		if (q.size() != 1) {
			cout << q.front() << ", ";
			q.pop();
		}
		else {
			cout << q.front() << '>';
			q.pop();
		}
		
		
	}
	return 0;
}

