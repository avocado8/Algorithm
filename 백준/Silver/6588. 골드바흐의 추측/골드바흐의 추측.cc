#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

void getPrimes() {
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= MAX; i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			is_prime[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    //입력
	getPrimes();
	int n;

    while (true) {
        cin >> n;
		if (n == 0) {
			break;
		}

		//연산
		//출력
		bool flag = false;
		for (int a = 3; a <= n; a += 2) {
			if (is_prime[a] && is_prime[n - a]) {
				cout << n << " = " << a << " + " << n - a << '\n';
				flag = true;
				break;
			}
		}
		if(!flag){
		    cout << "Goldbach's conjecture is wrong." << '\n';
		}
		
		
    }
    return 0;
}