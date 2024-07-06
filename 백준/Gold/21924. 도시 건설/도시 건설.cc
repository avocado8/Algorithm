/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int>tp;

vector<int> parent;

int findParent(int x){
    if(parent[x] < 0) return x;
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if (px == py) return false;
    if (parent[px] > parent[py]) swap(px, py);
    parent[py] += parent[px];
    parent[px] = py;
    return true;
}

long long kruskal(int v, vector<tp>&edge){
    int cnt = 0;
    long long sum = 0;
    for(auto [w, n1, n2]: edge){
        if(!unionNodes(n1,n2)) continue;
        sum += w;
        cnt++;
        if(cnt == v-1) return sum;
    }
    return -1;
}

int main()
{
    int n, m, a, b, c;
    long long total_sum=0;
    cin >> n>> m;
    parent.assign(n+1, -1);
    vector<tp> edge;
    while(m--){
        cin >> a >> b>> c;
        edge.push_back({c, a, b});
        total_sum += c; //얼마나 절약되는지 구하는 것이므로 절약 안했을때 값 저장
    }
    sort(edge.begin(), edge.end());
    long long ans = kruskal(n, edge);
    if(ans!=-1) cout << total_sum - ans;
    else cout << ans;
    return 0;
}