#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> li; // 모든 톱니바퀴 상태 저장
vector<pair<int, int>> stack; // 회전 정보 저장
vector<int> visited;

void checkRotation(int curr_num, int curr_dir){
    // 회전 가능한지 체크
    
    // 왼쪽으로 체크
    // 내 왼쪽톱니의 2번인덱스와 내톱니의 6번인덱스를 비교
    if(curr_num-1>=0 && visited[curr_num-1]==0){
        if(li[curr_num][6] != li[curr_num-1][2]){ //다른 극이라면 회전
            // 왼쪽톱니는 회전해야함 -> 회전정보 입력
            stack.push_back(make_pair(curr_num-1, curr_dir * -1));
            visited[curr_num-1] = 1;
            // 왼쪽으로 계속 탐색(체크)
            checkRotation(curr_num-1, curr_dir*-1);
        }
    }
    
    // 오른쪽으로 체크
    // 내 오른쪽톱니의 6번인덱스와 내톱니의 2번인덱스를 비교
    if(curr_num+1 < li.size() && visited[curr_num+1]==0){
        if(li[curr_num][2] != li[curr_num+1][6]){
            stack.push_back(make_pair(curr_num+1, curr_dir*-1));
            visited[curr_num+1] = 1;
            checkRotation(curr_num+1, curr_dir*-1);
        }
    }
}

int main(){
    int t, k;
    cin >> t;
    
    //톱니바퀴 입력받기
    li.resize(t);
    for(int i=0;i<t;i++){
        cin >> li[i];
    }
    
    cin >> k;
    // 회전 정보 입력받기
    for(int i=0;i<k;i++){
        int num, direction; // 회전시킨 톱니번호, 회전방향
        cin >> num >> direction;
        // 회전 입력받을 때마다 연산
        stack.clear();
        stack.push_back(make_pair(num-1, direction));
        visited.assign(t, 0); // 톱니 개수만큼 초기화
        visited[num - 1] = 1;
        checkRotation(num -1, direction);
        
        // 돌릴 톱니 확인 완료됐다면
        // stack에 회전해야할 정보가 저장되어 있을 테니 이제 진짜 돌린다!
        while(!stack.empty()){
            pair<int, int> top = stack.back();
            stack.pop_back();
            int tmp_num = top.first;
            int tmp_direction = top.second;
            if(tmp_direction == 1){
                //시계방향 회전 : 하나씩 뒤로
                // 맨끝이 맨앞으로 + 나머지 뒤에 붙이기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            else {
                //반시계방향 회전: 하나씩 앞으로
                //0번이 마지막, 나머지는 앞에 붙이 
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<t;i++){
        // 12시방향이 s극 == 0번인덱스가 1
        if(li[i][0] == '1'){
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}