#include <string>
using namespace std;

string solution(string s) {
    if (s.length() % 2 == 0)
        return string(1, s[s.length()/2 - 1]) + s[s.length()/2];
    else
        return string(1, s[s.length()/2]);
}
