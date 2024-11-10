#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool existsInCards(const vector<int>& cards, int num) {
    //카드 목록에 num이 있는지 확인
    return binary_search(cards.begin(), cards.end(), num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num;

    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> num;

        if (existsInCards(cards, num)) {
            cout << '1' << ' ';
        } else {
            cout << '0' << ' ';
        }
    }

    return 0;
}