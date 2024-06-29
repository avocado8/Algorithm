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
typedef pair<double, double>ci;
vector<int> parent;

int findParent(int x){
    if(parent[x]<0) return x;
    return parent[x] = findParent(parent[x]);
}

bool unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);
    if(xp==yp) return false;
    if(parent[xp]<parent[yp]) swap(xp, yp);
    parent[yp] += parent[xp];
    parent[xp] = yp;
    return true;
}

double kruskal(int n, vector<tp>&edge){
    double sum=0;
    int cnt=0;
    for(auto[w, n1, n2]: edge){
        if(!unionInput(n1,n2)) continue;
        sum += w;
        cnt++;
        if(cnt==n-1) return sum;
    }
    return sum;
}

int main()
{
    int n;
    double x,y;
    
    cin >> n;
    parent.assign(n+1, -1);
    vector<tp> edge;
    vector<ci> node;
    
    for(int i=0;i<n;i++){
        cin >> x >> y; //현재 점의 좌표
        node.push_back({x, y});
        //임의의 두 점에 대한 거리를 edge에 모두 저장
        //루트 ((x변화량)^2 + (y변화량)^2)
        for(int j=0;j<i;j++){
            double dx = x - node[j].first; //x변화량
            double dy = y - node[j].second; //y변화량
            double dist = sqrt(dx*dx + dy*dy);
            edge.push_back({dist, i, j});
        }
    }
    
    sort(edge.begin(), edge.end());
    double ans = kruskal(n, edge);
    
    cout << fixed;
    cout.precision(2);
    cout << ans;
    
    return 0;
}