#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Find the parent of a node
int findParent(vector<int>& parent, int node) {
    if (parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// Union two sets
void unionInput(vector<int>& parent, int x, int y) {
    int xp = findParent(parent, x);
    int yp = findParent(parent, y);
    if (xp == yp) return; // 이미 같은 집합에 속해 있다면 return
    if (parent[xp] < parent[yp]) {
        swap(xp, yp);
    }
    parent[yp] += parent[xp];
    parent[xp] = yp;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> parent(N + 1, -1);

    int truthCount;
    cin >> truthCount;

    vector<int> truths(truthCount);
    for (int i = 0; i < truthCount; ++i) {
        cin >> truths[i];
    }

    vector<vector<int>> parties(M);
    for (int i = 0; i < M; ++i) {
        int partySize;
        cin >> partySize;
        parties[i].resize(partySize);
        for (int j = 0; j < partySize; ++j) {
            cin >> parties[i][j];
        }
    }

    // Union-Find로 각 파티 연결
    for (const auto& party : parties) {
        for (size_t j = 1; j < party.size(); ++j) {
            unionInput(parent, party[0], party[j]);
        }
    }

    // 진실을 아는 사람들의 루트를 모두 통일
    for (int i = 1; i < truths.size(); ++i) {
        unionInput(parent, truths[0], truths[i]);
    }

    int truthRoot = truths.empty() ? -1 : findParent(parent, truths[0]);
    int result = 0;

    // 각 파티의 루트가 진실을 아는 사람의 루트와 다른지 확인
    for (const auto& party : parties) {
        bool canLie = true;
        for (const auto& person : party) {
            if (findParent(parent, person) == truthRoot) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
