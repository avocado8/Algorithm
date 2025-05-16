#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> answer(n, 0);
    map<string, int> id_map;
    for(int i=0;i<id_list.size();i++){
        id_map[id_list[i]] = i;
    }
    
    set<string> report_set(report.begin(), report.end());
    
    vector<vector<string>> reported_by(n); //피신고자가 누구에게 신고되었는지?
    vector<int> reported_cnt(n,0); //피신고자가 신고된 횟수
    
    for(string r: report_set){
        istringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;
        int reported_index = id_map[reported]; //피신고자 인덱스
        reported_cnt[reported_index]++;
        reported_by[reported_index].push_back(reporter);
    }
    
    for(int i=0;i<id_list.size();i++){
        if(reported_cnt[i]>=k){
            for(string reporter: reported_by[i]){
                answer[id_map[reporter]]++;
            }
        }
    }
    
    return answer;
}