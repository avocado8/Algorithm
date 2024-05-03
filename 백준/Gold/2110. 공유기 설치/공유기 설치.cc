#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntRouter(int dist, vector<int>& house, int n) {
    int cnt = 1;
    int cur = house[0]; //마지막으로 설치한 집
    for (int i = 1; i < n; i++) {
        if (house[i] - cur >= dist) {
            cnt++;
            cur = house[i]; //마지막으로 설치한 집 갱신
        }
    }
    return cnt;
}

int binarySearch(vector<int>&house, int n, int c) {
    int left = 0;
    int right = house[n - 1];
    while (left <= right) {
        int mid = (left + right) / 2;
        int installed = cntRouter(mid, house, n); //mid에서 설치할 수 있는 공유기 수
        if (installed >= c) {
            left = mid + 1; //더 탐색 가능 -> 오른쪽으로
        }
        else {
            right = mid - 1; //왼쪽으로
        }
    }
    return left - 1; //upperbound - 1
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> house(n);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    cout << binarySearch(house, n, c);
    return 0;
}