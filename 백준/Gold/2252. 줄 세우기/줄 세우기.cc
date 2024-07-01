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
    queue<int> q; //진입차수 0인 정점 관리할 큐
    vector<int> result;
    
    for(int i=1;i<=n;i++){
        if(!indegree[i]){ //초기상태에서 진입차수가 0인 정점을
            q.push(i); //큐에 추가
        }
    }
    while(!q.empty()){
        int node = q.front(); //큐의 가장 앞 요소를 꺼냄
        q.pop();
        
        result.push_back(node); //결과배열에 꺼낸 정점 삽입
        //정점을 찾았으면, 그 정점으로부터 나오는 간선을 삭제해야 함
        //--> 연결된 정점의 진입차수를 1씩 감소시킴
        for(int i=0;i<graph[node].size();i++){
            int next_node = graph[node][i];
            indegree[next_node]--;
            if(!indegree[next_node]){ //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에 삽입
            }
        }
    }
    return result;
}

int main()
{
    int n, m, a, b;
    cin >> n>> m;
    vector<int>indegree(n+1, 0); //진입차수
    vector<vector<int>>graph(n+1, vector<int>(0)); //인접리스트 그래프
    while(m--){
        cin >> a>> b; //a b는 a가 b의 앞에 서야 한다는 의미
        graph[a].push_back(b);
        indegree[b]++; //a -> b이므로 b의 진입차수 증가
    }
    vector<int>result = topologicalSort(n, indegree, graph);
    for(int i=0;i<n;i++){
        cout << result[i] << ' ';
    }

    return 0;
}