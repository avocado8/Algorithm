#include<stdio.h>
#include<stdlib.h>
int BinSearch(int *A, int size, int key) {
	int first = 0, last = size - 1;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (A[mid] == key)
			return 1;
		else if (A[mid] < key)
			first = mid + 1;
		else
			last = mid - 1;
	}
	return 0;
}

int compare(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int* A = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	qsort(A, N, sizeof(int), compare);
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int key;
		scanf("%d", &key);
		cnt += BinSearch(A, N, key);
	}
	printf("%d\n", N + M - cnt * 2);
	return 0;
}