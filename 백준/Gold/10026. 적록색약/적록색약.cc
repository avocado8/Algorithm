#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char board[101][101];
char board_weak[101][101];
bool visited[101][101];

int n;
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y){
    char color = board[x][y];
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx>=0 && tx<n && ty>=0 && ty<n){
            char next_color = board[tx][ty];
            if(!visited[tx][ty] && color == next_color){
                dfs(tx, ty);
            }
        }
    }
}

void dfs_weak(int x, int y){
    char color = board_weak[x][y];
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx>=0 && tx<n && ty>=0 && ty<n && !visited[tx][ty]){
            char next_color = board_weak[tx][ty];
            if(color == next_color){
                dfs_weak(tx, ty);
            }
        }
    }
}

int main()
{
    cin >> n;
    char color;
    
    //입력
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> color;
            if(color=='R' || color=='B') {
                board[i][j] = color;
                board_weak[i][j] = color;
            }
            else{ //초록
                board[i][j] = color;
                board_weak[i][j] = 'R'; //적색과 똑같이
            }
        }
    }
    
    int ans1 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                dfs(i, j);
                ans1++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    int ans2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                dfs_weak(i, j);
                ans2++;
            }
        }
    }
    
    cout << ans1 << ' ' << ans2;
    
    return 0;
}