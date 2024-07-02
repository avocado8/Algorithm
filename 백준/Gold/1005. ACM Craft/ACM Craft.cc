/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int topologicalSort(int n, int w, vector<int>&indegree, vector<vector<int>>&graph, vector<int>&delay){
    queue<int> q;
    vector<int> dp(n+1, 0); //현재 건물을 짓기까지 걸리는 최소 시간
    
    for(int i=1;i<=n;i++){
        dp[i] = delay[i];
        if(!indegree[i]){ //진입차수 0인 정점 큐에 삽입
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            int next_node = graph[node][i];
            //다음 정점의 최소 시간 = 현재정점들 중 가장 긴 시간이 걸리는 것
            dp[next_node] = max(dp[next_node], dp[node] + delay[next_node]);
            indegree[next_node]--; //진입차수 1 감소
            if(indegree[next_node]) continue;
            
            //진입차수가 0이라면
            if(next_node == w) return dp[w]; //w와 연결된 전 정점이 없다면 바로 종료
            q.push(next_node); //그렇지 않다면 큐에 넣고 다음 반복으로
        }
    }
    return dp[w];
}

int main()
{
    int t, n, k, x, y, w;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int>indegree(n+1); //진입차수
        vector<vector<int>> graph(n+1, vector<int>(0));
        vector<int>delay(n+1); //짓는 데 걸리는 딜레이
        for(int i=1;i<=n;i++){
            cin >> delay[i];
        }
        while(k--){
            cin >> x >> y; //x 다음에 y를 지어야 함
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;
        cout << topologicalSort(n,w,indegree,graph,delay) << "\n";
    }

    return 0;
}