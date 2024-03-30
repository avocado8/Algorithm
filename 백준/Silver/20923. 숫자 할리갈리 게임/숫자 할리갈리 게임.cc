#include <iostream>
#include <vector>
#include <deque>

using namespace std;

string playGame(deque<int>dodo, deque<int>su, int n, int m) {
    deque<int>dodo_ground;
    deque<int>su_ground;
    string answer;
    
    //1이면 도도 턴 -1이면 수연 턴
    int turn = 1;
    int do_card=100, su_card=100;

    //만약 도도의 첫 카드가 5 && su.ground.empty() 무조건 패배

    for (int i = 0; i < m; i++) {

        //도도의 턴
        if (turn == 1) {
            //도도 패 내려놓음
            do_card = dodo.front();
            dodo.pop_front();
            dodo_ground.push_front(do_card);
        }
        
        //수연의 턴
        if (turn == -1) {
            su_card = su.front();
            su.pop_front();
            su_ground.push_front(su_card);
        }

        turn *= -1;

        //승리조건
        if (dodo.empty() && !su.empty()) {
            return "su";
        }
        else if (su.empty() && !dodo.empty()) {
            return "do";
        }
        else if (dodo.empty() && su.empty()) {
            return "dosu";
        }

        //수연이가 치는 조건 : 합이 5고 그라운드가 비어있지 않을 때
        if (!dodo_ground.empty() && !su_ground.empty() && do_card + su_card == 5) { //합이 5면 수연이가 침
            //도도 그라운드에 있는 카드더미를 뒤집어 자신의 덱 아래로 합침
            //수연 덱 back에 push
            while (!dodo_ground.empty()) {
                int tmp = dodo_ground.back();
                dodo_ground.pop_back();
                su.push_back(tmp);
            }
            //자기 그라운드에 있는 카드더미도 그 아래로 합침
            while(!su_ground.empty()) {
                int tmp = su_ground.back();
                su_ground.pop_back();
                su.push_back(tmp);
            }
        }
        else if ( (dodo_ground.size() && do_card == 5) || (su_ground.size() && su_card == 5)) { //패에 5가 나오면 도도가 침
            while (!su_ground.empty()) {
                int tmp = su_ground.back();
                su_ground.pop_back();
                dodo.push_back(tmp);
            }
            //자기 그라운드에 있는 카드더미도 그 아래로 합침
            while (!dodo_ground.empty()) {
                int tmp = dodo_ground.back();
                dodo_ground.pop_back();
                dodo.push_back(tmp);
            }
        }
        else {
            continue;
        }
    }

    if (dodo.size() > su.size()) answer = "do";
    else if (dodo.size() < su.size()) answer = "su";
    else answer = "dosu";

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    deque<int>dodo;
    deque<int>su;
    for (int i = 0; i < n; i++) {
        int d, s;
        cin >> d >> s;
        dodo.push_front(d);
        su.push_front(s);
    }
    //cout << dodo.front() << su.front();

    cout << playGame(dodo, su, n, m);
    return 0;
}
