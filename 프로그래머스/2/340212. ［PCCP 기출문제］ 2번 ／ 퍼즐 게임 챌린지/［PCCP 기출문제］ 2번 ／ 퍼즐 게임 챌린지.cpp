#include <string>
#include <vector>

using namespace std;

bool checkSolve(int level, vector<int>&diffs, vector<int>&times, long long &limit){
    long long total_time = 0;
    for(int i=0; i<diffs.size();i++){
        int cur_diff = diffs[i];
        int cur_time = times[i];
        if (cur_diff <= level) total_time += cur_time;
        else {
            int prev_time = i>0 ? times[i-1] : 0;
            total_time += (prev_time + cur_time)*(cur_diff - level) + cur_time;
        }
    }
    if (total_time <= limit) return true;
    return false;
}

int binSearch(int left, int right, vector<int> diffs, vector<int> times, long long limit){
    int answer = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if (checkSolve(mid, diffs, times, limit)){
            // 이 레벨로 풀 수 있음 - 최소레벨 찾아야 하니 왼쪽으로
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return answer;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int max_level = 0;
    for(int i=0;i<diffs.size();i++){
        max_level = max(max_level, diffs[i]);
    }
    answer= binSearch(1,max_level, diffs, times, limit);
    
    return answer;
}