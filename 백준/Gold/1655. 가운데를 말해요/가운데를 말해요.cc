/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

void balance(priority_queue<int>&max_pq,priority_queue<int, vector<int>, greater<>>&min_pq){
    int max_top = max_pq.top();
    int min_top = min_pq.top();
    
    //작은값들은 최대히프, 큰값들은 최소히프에 저장되어야 함
    if(max_top > min_top){
        //즉 현재 최대히프의 top이 최소히프의 top보다 크다면, 자리를 바꿔주어야 함
        max_pq.pop();
        min_pq.pop();
        
        min_pq.push(max_top);
        max_pq.push(min_top);
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n, num;
    cin >> n;
    
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<>> min_pq;
    
    while(n--){
        cin >> num;
        
        if(max_pq.size() > min_pq.size()) {
            //같거나, 최대히프가 하나 더 많도록
            //즉 현재 최대히프사이즈가 더 크다면, 최소히프에 저장해 개수를 맞춰줌
            min_pq.push(num);
        } else {
            max_pq.push(num);
        }
        
        if(!max_pq.empty() && !min_pq.empty()){
            balance(max_pq, min_pq);
        }
        
        //최대히프 top이 중간값이므로 출력
        cout << max_pq.top() << '\n'; 
    }
    
    return 0;
}