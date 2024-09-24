#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> li; // 톱니바퀴의 극 상태를 저장
vector<pair<int, int>> stack; // 회전 정보를 저장
vector<int> visited; // 톱니바퀴 회전 여부 확인했는지 (0: 안했음 / 1: 했음)

void checkRotation(int num, int dir){
    // 왼쪽으로 확인
    if (num - 1 >=0 && !visited[num - 1]){
        // 나의 6번톱니와 내 왼쪽바퀴의 2번톱니 같은지 확인
        if (li[num][6] != li[num - 1][2]){
            // 내 왼쪽톱니 회전
            stack.push_back(make_pair(num - 1, dir * -1));
            visited[num - 1] = 1;
            checkRotation(num - 1, dir * -1);
        }
    }
    
    // 오른쪽으로 확인
    if (num + 1 < li.size() && !visited[num + 1]){
        // 나의 2번톱니와 내 오른쪽바퀴의 6번톱니
        if (li[num][2] != li[num + 1][6]){
            // 오른쪽톱니 회전
            stack.push_back(make_pair(num + 1, dir * -1));
            visited[num + 1] = 1;
            checkRotation(num + 1, dir * -1);
        }
    }
}

int main(){
    int t, k;
    cin >> t; // 톱니바퀴 개수
    
    li.resize(t);
    for(int i=0;i<t;i++){
        cin >> li[i]; // 톱니바퀴 상태 입력받기
    }
    
    cin >> k; // 회전 횟수
    for(int i=0;i<k;i++){
        int num, direction; // 회전시킬 톱니번호, 방향
        cin >> num >> direction;
        
        stack.clear();
        stack.push_back(make_pair(num - 1, direction)); // 회전 정보 저장
        visited.assign(t, 0);
        visited[num - 1] = 1; // 타겟 톱니바퀴 확인 여부 표시
        // 다른 톱니바퀴들의 회전 여부 확인
        checkRotation(num - 1, direction);
        
        // stack에 회전 정보가 다 들어있게 됨
        // 진짜 돌리기!
        while(!stack.empty()){
            pair<int, int> curr = stack.back();
            stack.pop_back();
            int curr_num = curr.first;
            int curr_dir = curr.second;
            
            // 시계 방향으로 회전
            if (curr_dir == 1){
                li[curr_num] = li[curr_num][7] + li[curr_num].substr(0, 7);
            }
            else { // 반시계 방향으로 회전
                li[curr_num] = li[curr_num].substr(1) + li[curr_num][0];
            }
        }
    }
    
    int answer = 0;
    for(int i =0; i<t;i++){
        if(li[i][0] == '1'){
            answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}