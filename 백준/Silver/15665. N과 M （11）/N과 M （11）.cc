#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int MAX = 7;

int n, m;
int sequence[MAX];
bool visited[10001];
set<vector<int>> result;

void printAns() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtracking(int cnt, vector<int>& arr) {
    if (cnt == m) {
        vector<int>tmp;
        for (int i = 0; i < m; i++) {
            tmp.push_back(sequence[i]);
        }
        result.insert(tmp);
        tmp.clear();
        return;
    }
    for (int i = 0; i < n; i++) {
        visited[arr[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        sequence[cnt] = arr[i];
        backtracking(cnt + 1, arr);
    }
}

int main() {
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // 입력된 수열을 사전 순으로 정렬
    backtracking(0, arr);
    
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        vector<int> res = *iter;
        for (int i = 0; i < m; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
