#include <iostream>
#include <vector>

using namespace std;
const int MAX = 9;

bool check_row[MAX][MAX + 1];
bool check_col[MAX][MAX + 1];
bool check_3x3[MAX][MAX + 1];

int get33Index(int row, int col) {
	return (row / 3) * 3 + (col / 3);
}

bool fillSudoku(int idx, vector<vector<int>>*sudoku) {
	//종료조건
	if (idx == MAX * MAX) return true;
	int row = idx / MAX;
	int col = idx % MAX;

	if ((*sudoku)[row][col] != 0) { //이미 숫자가 채워진 칸이면
		return fillSudoku(idx + 1, sudoku); //다음 칸으로 넘어감
	}

	for (int i = 1; i <= MAX; i++) {
		//아직 채워지지 않은 숫자라면
		if (!check_row[row][i] && !check_col[col][i] && !check_3x3[get33Index(row, col)][i]) {
			//칸 채우기
			check_row[row][i] = true;
			check_col[col][i] = true;
			check_3x3[get33Index(row,col)][i] = true;
			(*sudoku)[row][col] = i;
			//다음칸
			if (fillSudoku(idx + 1, sudoku)) {
				return true;
			}
			//다시 비우기
			check_row[row][i] = false;
			check_col[col][i] = false;
			check_3x3[get33Index(row, col)][i] = false;
			(*sudoku)[row][col] = 0;
		}
	}
	//위에서 다 안됐으면... 안되는거
	return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku) {
	vector<vector<int>>answer(MAX, vector<int>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			answer[i][j] = sudoku[i][j];
			if (sudoku[i][j]) {
				check_row[i][sudoku[i][j]] = true;
				check_col[j][sudoku[i][j]] = true;
				check_3x3[get33Index(i,j)][sudoku[i][j]] = true;
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
	//입력
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sudoku[i][j];
		}
	}

	//연산
	auto output = solution(sudoku);

	//출력
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << output[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
