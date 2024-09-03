#include <iostream>
#include <vector>
#include <algorithm>
const int CNT = 9;

using namespace std;

void select(vector<int> &arr){
    //아홉 난쟁이의 키의 합
    int sum = 0;
    for(int i=0;i<CNT;i++){
        sum += arr[i];
    }
    
    //완전탐색으로, 제외했을 때 100이 되는 경우를 찾음
    //100이 될 경우, 그 두 명을 제외(삭제)
    for(int i=0;i<CNT;i++){
        for(int j=i+1;j<CNT;j++){
            if(sum - arr[i] - arr[j] == 100){
                //조건 만족 - 이 두 명을 제외
                arr.erase(arr.begin() + j);
                arr.erase(arr.begin() + i);
                return;
            }
        }
    }
}

int main(){
    //입력
    vector<int> arr(CNT);
    for(int i=0;i<CNT;i++){
        cin >> arr[i];
    }
    
    //연산
    select(arr);
    sort(arr.begin(), arr.end());
    
    //출력
    for(auto it:arr){
        cout << it << '\n';
    }
}