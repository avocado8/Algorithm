#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int n;
vector<vector<int>> li; //비용행렬 저장
vector<vector<int>> dp; //방문 도시에 대한 비용 게산

int dfs(int x, int visited) {
	//x: 현재 내가 있는 도시
	//visited는 도시 전체에 대해서 내가 방문했는지 여부 체크
	//ex) 5개 도시: 10101 -> 1,3,5번 도시 방문
	if (visited == (1 << n) - 1) { //모든 도시 방문 완료 (111...1)
		if (li[x][0] != 0) { //시작점으로 돌아올 수 있다면
			return li[x][0];
		}
		else { //돌아오는 길이 없음
			return INF;
		}
	}
	if (dp[x][visited] != -1) { //이미 방문한 도시일 경우
		return dp[x][visited]; //기존에 계산한 값 사용
	}
	//현재 도시 x에서 방문하지 않은 도시를 찾아서 dfs를 하고 최소비용을 갱신
	int min_dist = INF;
	for (int i = 1; i < n; i++) {
		//방문확인은 and 연산. (visited에 1을 i만큼 shift한 것을 and)
		if (!(visited & (1 << i)) && li[x][i] != 0) { //방문할 수 있는 경우
			min_dist = min(min_dist, dfs(i, visited | (1 << i)) + li[x][i]);
		}
	}
	dp[x][visited] = min_dist;
	return min_dist;
}

int main() {
	cin >> n;
	li.assign(n, vector<int>(n));
	dp.assign(n, vector<int>(1 << n, -1)); //들어갈 도시 개수만큼 shift (ex 도시 2개면 00 01 10 11 -> 4개 (4 = 110(2))
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> li[i][j];
		}
	}
	cout << dfs(0, 1) << "\n";
}
