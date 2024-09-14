#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int M;
    cin >> M;

    int n = 0;

    while(M--) {
        string s;
        int x;
        cin >> s;

        if(s=="add") {
            cin >> x;
            n |= (1 << (x-1));
        }
        else if(s=="remove") {
            cin >> x;
            n &= ~(1 << (x-1));
        }
        else if(s=="check") {
            cin >> x;
            if(n & (1 << (x-1))) {
                cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
        else if(s=="toggle") {
            cin >> x;
            if(n & (1 << (x-1))) {
                n &= ~(1 << (x-1));
            }
            else {
                n |= (1 << (x-1));
            }
        }
        else if(s=="all") {
             n = (1 << 20) - 1;
        }
        else if(s=="empty") {
            n = 0;
        }
    }
    return 0;
}