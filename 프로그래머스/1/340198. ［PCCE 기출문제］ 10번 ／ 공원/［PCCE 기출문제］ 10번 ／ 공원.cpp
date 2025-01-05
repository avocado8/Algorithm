#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// k*k 돗자리를 이 위치에 깔 수 있는지
bool check(int k, int start_r, int start_c, vector<vector<string>> &park){
    int r = park.size();
    int c = park[0].size();
    if (start_r + k > r || start_c + k > c){
        return false;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if (park[start_r+i][start_c+j] != "-1"){
                return false;
            }
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<>());
    for(auto k: mats){
        for(int i=0;i<park.size();i++){
            for(int j=0;j<park[0].size();j++){
                if(check(k, i, j, park)) return k;
            }
        }
    }
    return -1;
}