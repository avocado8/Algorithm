#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int CNT = 9;

void solution(vector<int> &arr){
    // 아홉 난쟁이의 키의 합
    int sum =0;
    for(int i=0;i<CNT;i++){
        sum += arr[i];
    }
    
    for(int i=0;i<CNT;i++){
        for(int j=i+1;j<CNT;j++){
            if(sum - arr[i] - arr[j] == 100){
                //둘을 뺸 값이 100이라면 이 둘이 잘못된난쟁이4
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
    solution(arr);
    sort(arr.begin(), arr.end());
    
    //출력
    for(auto it: arr){
        cout << it << '\n';
    }
    return 0;
}