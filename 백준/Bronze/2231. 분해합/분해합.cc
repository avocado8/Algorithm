#include <iostream>
using namespace std;

int bruteforce(int n){
    for(int i=1;i<n;i++){
        //분해합 구하기
        int tmp = i;
        int sum = i; //분해합 저장
        while(tmp > 0){
            sum += tmp % 10; //일의자리
            tmp /= 10;
        }
        if(sum == n){
            //i가 n의 생성자
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
    cout << bruteforce(n);
    
    return 0;
}