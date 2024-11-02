#include <iostream>
using namespace std;
typedef long long ll;

ll multi(ll a, ll b, ll c){
    ll result = 1;
    a %= c;
    while(b){
        if (b&1){ //b가 홀수면
            result = (result * a) % c;
        }
        a = (a*a)%c;
        b = b >> 1;
    }
    return result;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    //a를 b번 곱한 수를 c로 나눈 나머지
    ll result = multi(a, b,c );
    cout << result;
    return 0;
}