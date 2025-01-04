#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int n = sizes.size();
    vector<int> width;
    vector<int> height;
    for(int i=0;i<sizes.size();i++){
        // 가로를 길게 맞추기
        if(sizes[i][0] < sizes[i][1]){
            sizes[i] = {sizes[i][1], sizes[i][0]};
        }
        width.push_back(sizes[i][0]);
        height.push_back(sizes[i][1]);
    }
    sort(width.begin(), width.end());
    sort(height.begin(), height.end());
    answer = width[n-1] * height[n-1];
    return answer;
}