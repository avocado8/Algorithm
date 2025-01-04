#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a=0, b=0, c = 0;
    
    vector<int> a_ans = {1,2,3,4,5};
    vector<int> b_ans = {2,1,2,3,2,4,2,5};
    vector<int> c_ans = {3,3,1,1,2,2,4,4,5,5};
    for(int i=1;i<=answers.size();i++){
        int cur = answers[i-1];
        int rem_a = i % a_ans.size();
        if (rem_a==0){
            if (cur==5) a++;
        } else {
            if (cur==rem_a) a++;
        }
        if (i%2==1){
            if (cur==2) b++;
        } else {
            int b_rem = i % b_ans.size();
            if (b_rem==2){
                if(cur==1) b++;
            } else if (b_rem==4){
                if(cur==3) b++;
            } else if (b_rem==6){
                if(cur==4) b++;
            } else{
                if(cur==5) b++;
            }
        }
        int c_rem = i % c_ans.size();
        if(c_rem==1 || c_rem==2){
            if(cur==3) c++;
        } else if (c_rem==3 || c_rem==4){
            if(cur==1) c++;
        } else if (c_rem==5 || c_rem==6){
            if(cur==2) c++;
        } else if (c_rem==7 || c_rem==8){
            if(cur==4) c++;
        } else {
            if(cur==5) c++;
        }
    }
    vector<int> tmp = {a,b,c};
    sort(tmp.begin(), tmp.end(), greater<>());
    int max = tmp[0];
    
    if(a==tmp[0]) answer.push_back(1);
    if(b==tmp[0]) answer.push_back(2);
    if(c==tmp[0]) answer.push_back(3);

    
    return answer;
}