#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e7;

void floyd(int n, vector<vector<int>>& graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>>graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) { 
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
    }
    floyd(n, graph);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != INF || graph[j][i] != INF) {
                cnt++;
            }
        }
        if (cnt==n){
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}
