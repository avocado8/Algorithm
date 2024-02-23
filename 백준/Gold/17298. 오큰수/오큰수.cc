#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void nge(vector<int>v, int n) {
	stack<int>s;
	vector<int>res(n);

	for (int i = 0; i < n; i++) {
		while (!s.empty() && (v[i] > v[s.top()])) {
			res[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		res[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
}

int main() {
	int n;
	cin >> n;
	stack<int>s;
	vector<int>v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	nge(v, n);

	

}

