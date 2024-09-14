#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calculate(int& s, string operation) {

	int x = 0;
	int pos = operation.find(" "); //���� �������� ������ ����
	string oper = operation.substr(0, pos); // ���� ����

	if (pos != string::npos) { // ������ ������ ���� ����(*������ ã�� ���ϸ� npos ��ȯ)
		x = stoi(operation.substr(pos + 1)); // ���� ������ ����, string -> int, x��
	}

	int x_bit = 1 << x; //x�� ��Ʈ����ũ�� ǥ��

	if (oper == "add") {
		s |= x_bit; //x �߰�, or ����(������)
	}
	else if (oper == "remove") {
		s &= ~x_bit; //x ����, ������
	}
	else if (oper == "check") {
		if ((s & x_bit) == x_bit) { //s�� x�� and ����(������)�� x���(== s�� x�� �ִٸ�) 1 ��ȯ
			return 1;
		}
		else { //x�� ���ٸ� 0 ��ȯ
			return 0;
		}
	}
	else if (oper == "toggle") {
		if ((s & x_bit) == x_bit) { //s�� x�� and ����(������)�� x���(== s�� x�� �ִٸ�)
			s &= ~x_bit; //x ����
		}
		else { //x�� ���ٸ�
			s |= x_bit; //x �߰�
		}
	}
	else if (oper == "all") {
		s = 0; //���� ���� ��
		for (int i = 1; i <= 20; i++) { //1���� 20���� �߰�
			int tmp_bit = 1 << i;
			s |= tmp_bit; //������
		}
	}
	else if (oper == "empty") {
		s = 0; //���� ����(== s�� ����������)
	}

	return 2; //check�� �ƴϸ� 2 ��ȯ
}

int main() {

	//����� �ӵ� ���
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	string operation;
	int s = 0;
	int check_result;

	//�Է� & ����
	cin >> m;
	cin.ignore(); //���� ���� ����

	for (int i = 0; i < m; i++) {
		getline(cin, operation); //���� ���� �Է�
		check_result = calculate(s, operation);

		//���
		if (check_result == 0 || check_result == 1) { //check_result�� 0 �Ǵ� 1�̸�(== check �����̸�)
			cout << check_result << "\n";
		}
	}

	return 0;
}