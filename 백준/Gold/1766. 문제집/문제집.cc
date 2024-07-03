/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<int>&indegree, vector<vector<int>>&graph){
    priority_queue<int, vector<int>, greater<>> pq; //숫자가 적은 게 더 우선순위 높게
    vector<int> result;
    
    for(int i=1;i<=n;i++){
        if(!indegree[i]){ //진입차수가 0인 정점 삽입
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        result.push_back(node);
        
        for(int i=0;i<graph[node].size();i++){
            int next_node = graph[node][i];
            indegree[next_node]--;
            if(!indegree[next_node]){ //진입차수가 0이 되었다면
                pq.push(next_node);
            }
        }
    }
    
    return result;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<int> indegree(n+1);
    vector<vector<int>> graph(n+1, vector<int>(0));
    while(m--){
        cin >> a >> b; //a를 b보다 먼저
        indegree[b]++;
        graph[a].push_back(b);
    }
    vector<int> result = topologicalSort(n, indegree, graph);
    for(int i=0;i<n;i++){
        cout << result[i] << ' ';
    }

    return 0;
}