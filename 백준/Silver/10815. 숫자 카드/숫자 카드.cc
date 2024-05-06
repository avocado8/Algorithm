#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, input;
    cin >> n;
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (binary_search(arr.begin(), arr.end(), input)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }
    return 0;
}