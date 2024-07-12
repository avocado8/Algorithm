/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> ci;

int solution(int n, vector<ci>&arr){
    int cnt = 0;
    int finish = 0;
    for(int i=0;i<n;i++){
        if(arr[i].second < finish){ //끝나는 시간보다 다음회의 시작시간이 빠르면 배정불가
            continue;
        }
        finish = arr[i].first; //회의 배정, 종료시간 갱신
        cnt++;
    }
    return cnt;
}

int main()
{
    int n, a, b;
    cin >> n;
    vector<ci>arr(n);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        arr[i] = make_pair(b, a); //끝나는 시간 기준
    }
    sort(arr.begin(), arr.end()); //끝나는시간 기준으로 정렬
    int ans = solution(n, arr);
    cout << ans;
    return 0;
}