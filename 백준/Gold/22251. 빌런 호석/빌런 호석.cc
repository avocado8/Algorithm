/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> bit_number = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};

int calcDiff(vector<int>& start_num, int n, int k){ //x와 n의 서로 다른 비트수 계산
    int cnt = 0;
    for(int i=0;i<k;i++){ //n의 각 자리수
        unsigned int diff = (start_num[i] ^ bit_number[n % 10]); //서로 다른 비트만 1로
        for(int j=0;j<7;j++){ //서로다른 비트 개수세기
            cnt += (diff & 1); //1과 and 연산
            diff >>= 1; //shift
        }
        n /= 10; //다음 자리수로
    }
    return cnt;
}

int solution(int n,int k, int p, int x){
    vector<int> start_num(k);
    int tmp_x = x;
    for(int i=0;i<k;i++){ //start_num에 현재층 각 자리수에 해당하는 비트값 저장
        start_num[i] = bit_number[tmp_x % 10];
        tmp_x /= 10;
    }
    
    int ans = 0;
    for(int i=1;i<=n;i++){ //1층부터 n층까지 탐색
        if (i==x) continue; //1개 이상 반전해야 하니까 같은 경우는 해당 X
        int diff = calcDiff(start_num, i, k); //현재층 기준 서로다른 비트수 세기
        if(diff>=1 && diff<=p) ans++; //반전 가능한 비트수가 1~p개라면 조건 만족
    }
    return ans;
}

int main()
{
    int n,k,p,x;
    cin>>n>>k>>p>>x;
    cout << solution(n,k,p,x);

    return 0;
}