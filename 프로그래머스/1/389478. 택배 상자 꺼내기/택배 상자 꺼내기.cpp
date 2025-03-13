#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getCol(int row, int w, int num){
    if(row%2 == 0){
        // 0층부터... 짝수층이면
        return (num - 1) % w;
    }
    else {
        return (w - 1 - (num - 1) % w);
    }
}

int solution(int n, int w, int num) {
    int answer = 1;
    int total_row = (n + w - 1) / w;
    int row = (num - 1) / w;
    int col = getCol(row, w, num);
    for(int i=row+1;i<total_row;i++){
        int top = (i % 2==0) ? (i*w+col+1) : (i*w+(w-1-col)+1);
        if(top<=n) answer++;
    }
    return answer;
}