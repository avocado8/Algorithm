#include <iostream>

using namespace std;

int solution(int n){
    // n을 분해합으로 갖는 수 찾기
    for(int i=1;i<n;i++){ // i는 생성자
        int sum = i; // 분해합
        int tmp = i;
        while(tmp){
            sum += tmp % 10; //일의자리 더하기
            tmp /= 10;
        }
        if(sum == n){
            return i;
        }
    }
    return 0;
}

int main(){
    //입력
    int n;
    cin >> n;
    //연산
    //출력
    cout << solution(n);
    return 0;
}