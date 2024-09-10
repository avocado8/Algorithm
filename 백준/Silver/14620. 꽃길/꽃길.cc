#include <iostream>
#include <vector>

using namespace std;

int getCost(int r, int c, vector<vector<int>>&arr){
    return arr[r][c] + arr[r-1][c] + arr[r+1][c] + arr[r][c+1] + arr[r][c-1];
}

int solution(int n, vector<vector<int>>&arr){
    n -= 2;
    int r1, c1, r2, c2, r3, c3;
    
    int answer = 200 * 15;
    
    for(int i=0;i<n*n;i++){
        r1 = i / n + 1;
        c1 = i % n + 1;
        for(int j=0;j<n*n;j++){
            r2 = j / n + 1;
            c2 = j % n + 1;
            // 두점의 |행의 값의 차| + |열 값의 차| <= 2 이면 고를 수 없음
            if(abs(r1-r2)+abs(c1-c2) <= 2){
                continue;
            }
            for(int k=0;k<n*n;k++){
                r3 = k / n + 1;
                c3 = k % n + 1;
                if(abs(r1-r3)+abs(c1-c3)<=2 || abs(r2-r3)+abs(c2-c3)<=2){
                    continue;
                }
                
                //세 점 골랐음
                answer = min(answer, getCost(r1,c1,arr) + getCost(r2,c2,arr) + getCost(r3,c3,arr));
            }
        }
    }
    
    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    cout << solution(n, arr);
    return 0;
}