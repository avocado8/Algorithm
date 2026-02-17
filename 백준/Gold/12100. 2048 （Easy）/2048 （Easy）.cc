/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer = 0;

vector<int> mergeLineLeft(vector<int>&line){
    vector<int> vals;
    vals.reserve(N);
    // 0 제거
    for(int x: line){
        if(x != 0) vals.push_back(x);
    }
    
    vector<int> res;
    res.reserve(N);
    // 같은 숫자 병합
    for(int i=0;i<vals.size();){
        if(i+1 < vals.size() && vals[i] == vals[i+1]){
            // 같은 숫자면 2배 해서 추가 후 인덱스 건너뛰기
            res.push_back(vals[i] * 2);
            i += 2;
        } else {
            res.push_back(vals[i]);
            i++;
        }
    }
    
    // 패딩
    while(res.size() < N){
        res.push_back(0);
    }
    
    return res;
}

vector<vector<int>> moveBoard(vector<vector<int>>& board, int dir){
    vector<vector<int>> nextBoard = board;
    
    // dir = 0(왼) 1(오) 2(위) 3(아래)
    if(dir==0){
        for(int r=0;r<N;r++){
            nextBoard[r] = mergeLineLeft(board[r]);
        }
    } else if(dir==1){
        for(int r=0;r<N;r++){
            vector<int> line = board[r];
            reverse(line.begin(), line.end());
            line = mergeLineLeft(line);
            reverse(line.begin(), line.end());
            nextBoard[r] = line;
        }
    } else if(dir == 2){
        for(int c=0;c<N;c++){
            vector<int> col(N);
            for(int r=0;r<N;r++) col[r] = board[r][c];
            col = mergeLineLeft(col);
            for(int r=0;r<N;r++) nextBoard[r][c] = col[r];
        }
    } else {
        for(int c=0;c<N;c++){
            vector<int> col(N);
            for(int r=0;r<N;r++) col[r] = board[r][c];
            reverse(col.begin(), col.end());
            col = mergeLineLeft(col);
            reverse(col.begin(), col.end());
            for(int r=0;r<N;r++) nextBoard[r][c] = col[r];
        }
    }
    return nextBoard;
}

int getMaxInBoard(vector<vector<int>>& board){
    int maxNumber = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            maxNumber = max(maxNumber, board[i][j]);
        }
    }
    return maxNumber;
}

void dfs(vector<vector<int>>& board, int depth){
    answer = max(answer, getMaxInBoard(board));
    if(depth == 5) return;
    
    for(int dir = 0;dir<4;dir++){
        vector<vector<int>> nextBoard = moveBoard(board, dir);
        dfs(nextBoard, depth + 1);
    }
}

int main()
{
    // 입력
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    
    dfs(board, 0);
    cout << answer << "\n";
    return 0;
}