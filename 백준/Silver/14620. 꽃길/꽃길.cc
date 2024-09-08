#include <iostream>
#include <vector>

using namespace std;

const int MAX = 15 * 200;

int getScore(int r, int c, vector<vector<int>>&board){
    return board[r][c] + board[r-1][c] + board[r][c-1] + board[r][c+1] + board[r+1][c];
}

int solution(int n, vector<vector<int>>&board){
    int answer = MAX;
    int r1, c1, r2, c2, r3, c3;
    
    n-=2;
    for(int i=0;i<n*n;i++){
        r1 = i / n + 1;
        c1 = i % n + 1;
        for(int j=0;j<n*n;j++){
            r2 = j / n + 1;
            c2 = j % n + 1;
            if(abs(r1-r2) + abs(c1-c2) <= 2) continue;
            
            for(int k=0;k<n*n;k++){
                r3 = k / n + 1;
                c3 = k % n + 1;
                if(abs(r1-r3)+abs(c1-c3)<=2 || abs(r2-r3)+abs(c2-c3)<=2) continue;
                
                answer = min(answer, getScore(r1,c1,board) + getScore(r2,c2,board) + getScore(r3,c3,board));
            }
        }
    }
    return answer;
}

int main(){
    int n;
    vector<vector<int>>board;
    
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    cout << solution(n, board);
    return 0;
    
}