#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    int key[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    string answer = "";
    pair<int,int> left = {3, 0};
    pair<int, int> right = {3,2};
    
    for(int i=0;i<numbers.size();i++){
        int num = numbers[i];
        pair<int, int> target;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(key[i][j]==num) target={i, j}; //좌표찾기
            }
        }
        if(num==1 || num==4 || num==7){
            answer += "L";
            left = target;
        }
        else if(num==3 || num==6 || num==9){
            answer += "R";
            right = target;
        }
        else {
            int left_dist = abs(target.first - left.first) + abs(target.second - left.second);
            int right_dist = abs(target.first - right.first) + abs(target.second - right.second);
            if(left_dist < right_dist || ((left_dist == right_dist) && hand=="left")){
                answer+="L";
                left=target;
            } else {
                answer+="R";
                right=target;
            }
        }
    }
    
    
    return answer;
}