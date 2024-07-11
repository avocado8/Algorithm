#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int square(int n, int y, int x) {
    int tmp = pow(2, n - 1);
    ci s1 = { 0, 0 };
    ci s2 = { tmp, 0 };
    ci s3 = { 0, tmp };
    ci s4 = { tmp, tmp };

    if (y < tmp && x < tmp) return 0;
    else if (y < tmp && x >= tmp) return 1;
    else if (y >= tmp && x < tmp) return 2;
    else return 3;
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<int> cnt(n + 1, 0);

    for (int i = n; i > 0; i--) {
        int sq = square(i, r, c);
        cnt[i] = sq;

        int half = pow(2, i - 1);
        if (sq == 1) {
            c -= half;
        } else if (sq == 2) {
            r -= half;
        } else if (sq == 3) {
            r -= half;
            c -= half;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i] * pow(4, i - 1);
    }

    cout << ans;
    return 0;
}
