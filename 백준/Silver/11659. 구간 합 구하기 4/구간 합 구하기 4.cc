#include <iostream>
#include <vector>

using namespace std;

void calSum(int n, vector<int>& sum) {
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
    }
}

int getRangeSum(int i, int j, vector<int>& sum) {
    return sum[j] - sum[i - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, i, j;
    cin >> n >> m;
    vector<int>sum(n + 1, 0); //sum[0] = 0
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
    }
    //누적합 구하기
    calSum(n, sum);
    
    while (m--) {
        cin >> i >> j;
        cout << getRangeSum(i, j, sum) << "\n";
    }
    
    return 0;
}