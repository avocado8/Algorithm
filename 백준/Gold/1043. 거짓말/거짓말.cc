#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>parent;

int findParent(int node) {
    if (parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

// Union two sets
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);
    if (xp == yp) return; // 이미 같은 집합에 속해 있다면 return
    if (parent[xp] < parent[yp]) {
        swap(xp, yp);
    }
    parent[yp] += parent[xp];
    parent[xp] = yp;
}

int main(){
    int n, m, truth_cnt, party_size;
    cin >> n>> m >> truth_cnt;
    parent.assign(n+1, -1);
    vector<int> know_truth(truth_cnt);
    for(int i=0;i<truth_cnt;i++){
        cin >> know_truth[i];
    }
    
    vector<vector<int>> parties(m, vector<int>(n+1, 0));
    for(int i=0;i<m;i++){
        cin >> party_size;
        parties[i].resize(party_size);
        for(int j=0;j<party_size;j++){
            cin >> parties[i][j];
        }
    }
    
    for(auto party: parties){
        for(int j=1;j<party.size();j++){
            unionInput(party[0], party[j]);
        }
    }
    
    for(int i=1;i<truth_cnt;i++){
        unionInput(know_truth[0], know_truth[i]);
    }
    int truth_root = know_truth.empty() ? -1 : findParent(know_truth[0]);
    
    int answer = 0;
    for(auto party:parties){
        bool flag = true; //해당 파티에서 과장할 수 있는지
        for(auto p : party){
            if(findParent(p) == truth_root){
                flag = false; //해당 노드의 부모가 진실을 아는 집단의 부모와 동일 => 과장할 수 없음
                break;
            }
        }
        if(flag) answer++;
    }
    cout << answer;
    return 0;
    
    
}