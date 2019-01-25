#include <stdio.h>

int main(){

	int i, j;

	int N, M;
	printf("Enter number of columns and rows: ");
	scanf("%d %d", &M, &N);

	int *a = new int[N * M];
	printf("Enter your matrix: ");
	for(i = 0; i < N * M; i++){
		scanf("%d", &a[i]);
	}

	
	printf("Your numbers:\n");
	for(i = 0; i < N; i++){
		printf("    ");
		for(j = 0; j < M; j++){
			printf("%d ", a[i * M + j]);
		}
		printf("\n");
	}
}