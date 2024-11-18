#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ci;

ci dfs (int cur, int prev, vector<vector<ci>>&graph, int weight){
    int max_node = cur;
    int max_edge = weight;
    
    for(int i=0;i<graph[cur].size();i++){ //연결된 노드 탐색
        int next_node=graph[cur][i].first;
        int next_edge=graph[cur][i].second;
        
        if(next_node==prev) continue;
        
        ci search = dfs(next_node, cur, graph, weight + next_edge);
        
        if(search.second > max_edge){
            // 자식노드 리턴값 중 큰 것으로 갱신
            max_node = search.first;
            max_edge = search.second;
        }
    }
    return {max_node, max_edge};
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<ci>> graph(n+1, vector<ci>(0));
    int v1, v2, e;
    for(int i=0;i<n-1;i++){
        cin >> v1 >> v2 >> e;
        graph[v1].push_back({v2, e});
        graph[v2].push_back({v1, e});
    }
    
    ci farmost = dfs(1, -1, graph, 0);
    ci another_farmost = dfs(farmost.first, -1, graph, 0);
    
    cout << another_farmost.second; //가중치 출력
    
    return 0;
}