/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef tuple<double, int, int>tp;
typedef pair<int, int>ci;

vector<int> parent;

int findParent(int x){
    if(parent[x] < 0) return x;
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if (px==py) return false;
    if(parent[px] < parent[py]) swap(px, py);
    parent[py] += parent[px];
    parent[px] = py;
    return true;
}

double kruskal(int v, vector<tp>&edge){
    double sum=0;
    int cnt = 0;
    for(int i=0;i<edge.size();i++){
        double w = get<0>(edge[i]);
        int a = get<1>(edge[i]);
        int b = get<2>(edge[i]);
        if(!unionNodes(a, b)){ //사이클이 생기는 경우
            continue;
        }
        sum+=w;
        cnt++;
        if(cnt==v-1) return sum;
    }
    return 0;
}

int main()
{
    int n, m, a, b, v=0;
    cin >> n>> m;
    parent.assign(n+1, -1);
    vector<tp> edge;
    vector<ci> nodes(n+1);
    for(int i=1;i<=n;i++){
        cin >> nodes[i].first >> nodes[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            double dx = nodes[i].first - nodes[j].first;
            double dy = nodes[i].second - nodes[j].second;
            double dist = sqrt(dx*dx + dy*dy);
            edge.push_back({dist, i, j});
        }
    }
    while(m--){ //이미 연결된 통로 미리 추가
        cin >> a >> b;
        if(unionNodes(a,b)) v++;
    }
    sort(edge.begin(), edge.end());
    double ans = kruskal(n - v, edge); //이미 연결된거 제외하고 연산
    
    cout << fixed;
    cout.precision(2);
    cout << ans;
    
    return 0;
}