#include <vector>
using namespace std;


int solution(vector<int> nums)
{
    int n = nums.size();
    int max = n/2;
    vector<bool> visited(200001, false);
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!visited[nums[i]]) { // 중복 숫자가 아니면
            visited[nums[i]] = true; // 중복 표시
            answer++; //중복 아닌 수 개수 추가
        }
        // 중복이면 넘어감
    }
    
    if (answer > max) {
        answer = max;
    }
    
    return answer;
}