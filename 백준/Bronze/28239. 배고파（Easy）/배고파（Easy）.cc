#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 60;

pair<int,int> getPair(ll m){
    int x, y; // x <= y
    
    // m이 2의 제곱수인 경우(m = 2^i)
    // m=2^(i-1) + 2^(i-1)
    // x=y=i-1
    for(int i=0;i<MAX;i++){
        // m == 2^i == 1<<i
        if (m == ((ll)1 << i)){ //오버플로우 방지
            return { i-1, i-1 };
        }
    }
    
    // m이 2의 제곱수가 아닌 경우
    // m = 2^x + 2^y
    for(x=0;x<MAX;x++){
        //x번째 비트에 1이 저장되어 있다면 그 위치가 x
        if (m & ((ll)1<<x)){
            //=m의 x번째비트가 1이라면
            //이 위치가 곧 x
            break;
        }
    }
    for(y=x+1;y<MAX;y++){
        if (m & ((ll)1<<y)){
            break;
        }
    }
    return {x,y};
}

int main(){
    int n;
    ll m;
    cin >> n;
    while(n--){
        cin >> m;
        pair<int, int > ans = getPair(m);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}