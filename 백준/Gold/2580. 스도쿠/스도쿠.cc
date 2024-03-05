#include <iostream>
#include <vector>

using namespace std;
const int MAX = 9;
//check[a][b] -> a행/열/구역에 숫자 b가 존재함
bool check_row[MAX][MAX + 1]; //각 행에서 중복 체크
bool check_col[MAX][MAX + 1]; //각 열
bool check_3x3[MAX][MAX + 1]; //각 3x3사각형
int get3x3Idx(int row, int col) {
	return (row / 3) * 3 + (col / 3);
}

bool fillSudoku(int idx, vector<vector<int>>* sudoku) {
	if (idx == MAX * MAX) return true;
	int row = idx / MAX;
	int col = idx % MAX;
	if ((*sudoku)[row][col]) { //이미 채워진 칸이면 다음으로
		return fillSudoku(idx + 1, sudoku);
	}
	for (int i = 1; i <= MAX; i++) {
		//1~9까지 넣어보면서 조건 만족하나 확인
		if (!check_row[row][i] && !check_col[col][i] && !check_3x3[get3x3Idx(row, col)][i]) {
			//만족하면 해당칸에 숫자 들어갈 수 있음
			//체크 배열에 표기
			check_row[row][i] = true;
			check_col[col][i] = true;
			check_3x3[get3x3Idx(row, col)][i] = true;
			//스도쿠 칸 채우기
			(*sudoku)[row][col] = i;

			if (fillSudoku(idx + 1, sudoku)) {
				return true;
			}

			//체크 배열 다시 수정, 스도쿠 칸 비우기
			check_row[row][i] = false;
			check_col[col][i] = false;
			check_3x3[get3x3Idx(row, col)][i] = false;
			(*sudoku)[row][col] = 0;
		}
	}
	return false;
}

vector<vector<int>> solution(vector<vector<int>>sudoku) {
	vector<vector<int>>answer(MAX, vector<int>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			answer[i][j] = sudoku[i][j];
			if (sudoku[i][j]) {
				check_row[i][sudoku[i][j]] = true;
				check_col[j][sudoku[i][j]] = true;
				check_3x3[get3x3Idx(i, j)][sudoku[i][j]] = true;
			}
		}
	}
	fillSudoku(0, &answer);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> sudoku(MAX, vector<int>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sudoku[i][j];
		}
	}
	auto output = solution(sudoku);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << output[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}