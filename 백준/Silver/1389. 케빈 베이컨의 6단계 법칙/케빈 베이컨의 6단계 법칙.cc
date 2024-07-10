/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void floyd(int n, vector<vector<int>>&graph){
    for(int k=1;k<=n;k++){ //중간
        for(int i=1;i<=n;i++){ //시작
            for(int j=1;j<=n;j++){ //끝
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(cost, graph[i][j]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 1e6));
    for(int i=1;i<=n;i++){
        graph[i][i] = 0;
    }
    int a, b;

    vector<int> kevin_arr(n+1, 0);
    while(m--){
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    floyd(n, graph);
    for(int i=1;i<=n;i++){
        int kevin = 0;
        for(int j=1;j<=n;j++){
            kevin += graph[i][j];
        }
        kevin_arr[i]=kevin;
    }
    
    int min_kevin = 1e6;
    int min_index = 0;
    for(int i=1;i<=n;i++){
        if (kevin_arr[i] < min_kevin) {
            min_kevin = kevin_arr[i];
            min_index = i; // 최소 케빈 베이컨 수를 가진 사람의 인덱스 업데이트
        }
    }
    cout << min_index;

    return 0;
}