#include <iostream>
#include <vector>

#define MAX 10000 // 2부터 최대 1만까지의 수들 중 소수 판별 | 500만은 오버플로우 발생하니 주의...

using namespace std;

// 소수 배열 구하기
vector<int> getPrimes()
{
    // 0으로 초기화 -> 각 인덱스의 값이 0이면 그 인덱스에 해당하는 숫자는 소수
    // 1이면 그 인덱스에 해당하는 숫자는 소수가 아님
    vector<int> primes(MAX + 1, 0);
    for (int i = 2; i <= MAX; i++)
    {
        if (primes[i] != 0)// 소수가 아닌 경우
        { 
            continue;
        }

        // 에라토스테네스의 체를 이용해 소수의 배수들을 지우기
        for (int j = i * i; j <= MAX; j += i)
        {
            primes[j] = 1; // 소수의 배수들은 소수가 아님
        }
    }

    return primes;
}

void getGoldBachPartition(int t)
{
    // 소수 배열 구하기
    vector<int> primes = getPrimes();
    int n;
    while (t--) // 테스트 케이스 수만큼 반복
    {
        cin >> n;

        int a = 0;
        int b = n;

        // n = a + b를 이루는 두 개의 소수 찾기
        for (int i = 2; i <= n / 2; i++)
        {
            if (primes[i]) // i가 소수가 아니라면 (=primes[i]가 1이라면)
            {
                continue;
            }

            int j = n - i; // i + j = n이 되므로 골드바흐 파티션이 될 수 있다
            if (primes[j]) // j가 소수가 아니라면
            {
                continue;
            }

            if ((j - i) < (b - a)) // i와 j가 모두 소수일경우 이전에 기록된 소수들 보다 차이가 적은지 확인
            { 
                a = i;
                b = j;
            }
        }

        cout << a << " " << b << "\n";
    }
}

    int main()
    {
        // 입력
        int t;
        cin >> t;

        // 연산 & 출력
        getGoldBachPartition(t);
    }