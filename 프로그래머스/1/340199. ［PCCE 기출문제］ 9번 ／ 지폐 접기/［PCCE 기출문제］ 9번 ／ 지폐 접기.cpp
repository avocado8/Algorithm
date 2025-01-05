#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    // wallet과 bill의 가로, 세로 길이를 정렬
    int wal_w = max(wallet[0], wallet[1]);
    int wal_h = min(wallet[0], wallet[1]);
    int bill_w = max(bill[0], bill[1]);
    int bill_h = min(bill[0], bill[1]);

    // 긴 쪽을 우선적으로 반으로 접음
    while (bill_w > wal_w || bill_h > wal_h) {
        if (bill_w > bill_h) {
            bill_w /= 2;  // 가로를 반으로 접음
        } else {
            bill_h /= 2;  // 세로를 반으로 접음
        }
        answer++;

        // 긴 쪽과 짧은 쪽을 정렬
        if (bill_w < bill_h) {
            swap(bill_w, bill_h);
        }
    }

    return answer;
}
