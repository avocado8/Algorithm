/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<>> min_pq;
priority_queue<int, vector<int>, less<>> max_pq;
map<int, int>cnt;

void syncQueue(){
    while(!max_pq.empty() && cnt[max_pq.top()]==0) max_pq.pop();
    while(!min_pq.empty() && cnt[min_pq.top()]==0) min_pq.pop();
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t, k, n;
    char cmd;
    cin >> t;
    
    while(t--){
        while(!max_pq.empty()) max_pq.pop();
        while(!min_pq.empty()) min_pq.pop();
        cnt.clear();
        
        cin >> k;
        while(k--){
            cin >> cmd >> n;
            if(cmd=='I'){
                max_pq.push(n);
                min_pq.push(n);
                cnt[n]++;
            }
            else{
                if(n==1){ //최댓값삭제
                    if(!max_pq.empty()){
                        int target = max_pq.top();
                        max_pq.pop();
                        cnt[target]--;
                    }
                }
                else { //최솟값삭제
                    if(!min_pq.empty()){
                        int target = min_pq.top();
                        min_pq.pop();
                        cnt[target]--;
                    }
                }
                syncQueue();
            }
        }
        
        syncQueue();
        if(max_pq.empty() || min_pq.empty()) cout << "EMPTY" << '\n';
        else cout << max_pq.top() << ' ' << min_pq.top() << '\n';
    }
    
    return 0;
}