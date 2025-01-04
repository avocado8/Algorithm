#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int t=0;t<commands.size();t++){
        vector<int> cur_com = commands[t];
        int i = cur_com[0]-1;
        int j = cur_com[1]-1;
        int k = cur_com[2]-1;
        vector<int> new_array = vector<int>(array.begin() + i, array.begin()+j+1);
        sort(new_array.begin(), new_array.end());
        answer.push_back(new_array[k]);
    }
    return answer;
}