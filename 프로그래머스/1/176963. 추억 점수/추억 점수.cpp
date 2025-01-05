#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> yearn_map;
    for(int i=0;i<name.size();i++){
        yearn_map[name[i]] = yearning[i];
    }
    for(int i=0;i<photo.size();i++){
        int tmp_ans = 0;
        for(int j=0;j<photo[i].size();j++){
            tmp_ans += yearn_map[photo[i][j]];
        }
        answer.push_back(tmp_ans);
    }
    return answer;
}