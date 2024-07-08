/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(int k, int n, vector<long long>&arr) {
    long long left = 1;
    long long right = arr[k-1];
    int answer = 0;
    
    while(left<=right){
        long long mid = (left + right)/2;
        int cnt = 0;
        for(int i=0;i<k;i++){
            cnt += arr[i] / mid;
        }
        if(cnt >= n){ //n개보다 많이 만들어도 ok
            //해당 길이로 자를 수 있음 -> 더 긴 걸로 다시 시도 (오른쪽으로 탐색)
            answer = mid;
            left = mid+1;
        } else {
            right = mid-1; //왼쪽으로 탐색
        }
    }
    return answer;
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<long long> arr(k);
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int answer = binSearch(k, n, arr);
    cout << answer;
    return 0;
}