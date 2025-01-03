#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci;

bool compare(ci a, ci b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    
    // 필요한거
    // 장르별 재생횟수합 정렬
    // 장르내에서 각 재생횟수 정렬
    // 고유번호 유지 필요
    // key가 장르, value는 {재생횟수, 고유번호}배열 ? 
    map<string, vector<ci>> hash_map;
    for(int i=0;i<n;i++){
        hash_map[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    // 각 해시맵에서 value vector를 조회수별 정렬
    for(auto &iter: hash_map){
        sort(iter.second.begin(), iter.second.end(), compare);
    }
    
    vector<pair<int, string>> cnt;
    for(auto iter: hash_map){
        int tmp = 0;
        for(auto p: iter.second){
            // cout << p.first << " " << p.second << "\n";
            tmp += p.first;
        }
        cnt.push_back(make_pair(tmp, iter.first));
        // cout<< "next\n";
    }
    
    sort(cnt.begin(), cnt.end(), greater<>());
    
    // cnt에 횟수를 내림차순으로 저장 (횟수, 장르이름) pair
    // cnt의 첫번째 요소부터, 각 장르에서 2개씩 선정
    for(int i=0;i<cnt.size();i++){
        string cur_genre = cnt[i].second; // 장르명
        vector<ci> cur_arr = hash_map[cur_genre]; // 해당 장르의 곡들 (정렬상태)
        answer.push_back(cur_arr[0].second); // 상위 2개의 고유번호
        if(cur_arr.size() > 1){
            answer.push_back(cur_arr[1].second);
        }
    }
    
    return answer;
}