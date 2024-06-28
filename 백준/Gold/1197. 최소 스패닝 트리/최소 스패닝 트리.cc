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
    if(parent[x]<0) return x;
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if(px==py) return false;
    if(parent[px]<parent[py]) swap(px,py);
    parent[py] += parent[px];
    parent[px] = py;
    return true;
}

int kruskal(int v, vector<tp> edge){
    int sum=0, cnt=0;
    for(auto[w, n1, n2]: edge){
        if(!unionNodes(n1, n2)){ //사이클이 생길 경우
            continue;
        }
        sum += w;
        cnt++;
        if(cnt==v-1){ //간선 v-1개 모두 선택함
            return sum;
        }
    }
    return 0; //최소신장트리 만들지 못한 경우
}

int main()
{
    int v,e,a,b,c;
    cin >> v >> e;
    vector<tp> edge;
    parent.assign(v+1, -1);
    
    while(e--){
        cin >> a >> b >> c;
        edge.push_back({c,a,b});
    }
    sort(edge.begin(), edge.end()); //가중치 순으로 정렬
    cout << kruskal(v, edge);

    return 0;
}