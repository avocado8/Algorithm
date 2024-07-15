#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<>> pq;

int solution(int x){
    int answer;
    if(x==0){
        if(pq.empty()) answer = 0;
        else {
            answer = pq.top();
            pq.pop();
        }
    }
    else {
        pq.push(x);
    }
    return answer;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    
    cin >> n;
    while(n--){
        cin >> x;
        if(x==0){
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}