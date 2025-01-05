#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = wallpaper.size()-1, luy = wallpaper[0].length()-1;
    int rdx=-1, rdy=-1;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].length();j++){
            char target = wallpaper[i][j];
            if (target == '#'){
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i);
                rdy = max(rdy, j);
                cout << "lux luy " << lux << " " << luy << "\n";
                cout << "rdx rdy " << rdx << " " << rdy << "\n";
            }
        }
    }
    answer = {lux, luy, rdx+1, rdy+1};
    return answer;
}