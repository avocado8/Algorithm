#include <string>
#include <vector>

using namespace std;

int strToIntTime(string time){
    int min = stoi(time.substr(0, 2));
    int sec = stoi(time.substr(3, 2));
    return min*60 + sec;
}

string intToStrTime(int time){
    int min = time / 60;
    int sec = time % 60;
    string final_min = to_string(min);
    string final_sec = to_string(sec);
    if (min < 10) final_min = "0" + final_min;
    if (sec < 10) final_sec= "0" + final_sec;
    return final_min + ":" + final_sec;
}

int playCmd(string cmd, int video_len_int, int pos_int, int op_start_int, int op_end_int){
    
    if (cmd=="prev"){
        if (pos_int <= 10) pos_int = 0;
        else pos_int -= 10;
    }
    else if (cmd=="next"){
        if (pos_int + 10 >= video_len_int) pos_int = video_len_int;
        else pos_int += 10;
    }
    
    return pos_int;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int video_int = strToIntTime(video_len);
    int pos_int = strToIntTime(pos);
    int op_start_int = strToIntTime(op_start);
    int op_end_int = strToIntTime(op_end);
    for(int i=0;i<commands.size();i++){
        if (pos_int >= op_start_int && pos_int <= op_end_int) {
            pos_int = op_end_int;
        }
        string cmd = commands[i];
        pos_int = playCmd(cmd, video_int, pos_int, op_start_int, op_end_int);
        if (pos_int >= op_start_int && pos_int <= op_end_int) {
            pos_int = op_end_int;
        }
    }
    answer = intToStrTime(pos_int);
    return answer;
}