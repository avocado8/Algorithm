/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
vector<vector<int>> arr;
vector<bool>visited_dfs;
vector<bool> visited_bfs;

void dfs(int idx, vector<int>&ans_dfs){
    visited_dfs[idx] = true;
    ans_dfs.push_back(idx);
    for(int i=1;i<=n;i++){
        if(arr[idx][i]==1 && !visited_dfs[i]){
            dfs(i, ans_dfs);
        }
    }
}

void bfs(vector<int>&ans_bfs){
    queue<int> q;
    q.push(v);
    visited_bfs[v] = true;

    while(!q.empty()){
        int next = q.front();
        q.pop();
        ans_bfs.push_back(next);
        for(int i=1;i<=n;i++){
            if(arr[next][i]==1 && !visited_bfs[i]){
                visited_bfs[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> n >> m>> v;
    vector<int> ans_dfs, ans_bfs;
    arr.assign(n+1, vector<int>(n+1, 0));
    visited_dfs.assign(n+1, false);
    visited_bfs.assign(n+1, false);
    
    while(m--){
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    
    dfs(v, ans_dfs);
    bfs(ans_bfs);
    
    for(int i: ans_dfs){
        cout << i << ' ';
    }
    cout << '\n';
    for(int i: ans_bfs){
        cout << i << ' ';
    }
    
    return 0;
}