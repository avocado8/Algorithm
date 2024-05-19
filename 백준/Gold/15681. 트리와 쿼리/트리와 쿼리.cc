#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_size;

int solution(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    int cnt = 1;
    for (int child : graph[node]) {
        if (!visited[child]) {
            cnt += solution(child, graph, visited);
        }
    }
    subtree_size[node] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q, v1, v2, x;
    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1);
    subtree_size.resize(n + 1, 0);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // 루트에서 시작하여 서브트리 크기를 계산합니다.
    solution(r, graph, visited);

    for (int i = 0; i < q; i++) {
        cin >> x;
        cout << subtree_size[x] << "\n";
    }

    return 0;
}
