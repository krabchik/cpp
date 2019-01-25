#include <stdio.h>
#include <cstdlib> // содержит srand() и rand()
#include <ctime>

void matprint(int N, int M, int *a);
int* matsumm(int N, int M, int *arr1, int *arr2);
int* matproizv(int N, int M, int *arr1, int N1, int M1, int *arr2);
int* entermat(int N, int M);


int main(){
	int i, j;
	int N, M;
	int N1, M1;
	srand(time(NULL));

	printf("Enter number of columns and rows of 1 matrix: ");
	scanf("%d %d", &M, &N);
	int *arr1 = new int[N * M];
	arr1 = entermat(N, M);
	matprint(N, M, arr1);

	printf("Enter number of columns and rows of 2 matrix: ");
	scanf("%d %d", &M1, &N1);
	int *arr2 = new int[N1 * M1];
	arr2 = entermat(N1, M1);
	matprint(N1, M1, arr2);
	
	printf("Sum of your matrixes:\n");
	matprint(N, M, matsumm(N, M, arr1, arr2));

	printf("Multipl. of your matrixes:\n");
	matprint(N, M, matproizv(N, M, arr1, N1, M1, arr2));
}

int* entermat(int N, int M){
	int i;
	int *arr1 = new int[N * M];
	printf("Enter your matrix: ");
	for(i = 0; i < N * M; i++){
		scanf("%d", &arr1[i]);
	}
	return arr1;
}

int* matsumm(int N, int M, int *arr1, int *arr2){
	int i, j;
	int *res = new int[N * M];

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			res[j + N * i] = arr1[j + N * i] + arr2[j + N * i];
		}
	}

	return res;
}

int* matproizv(int N, int M, int *arr1, int N1, int M1, int *arr2){
	int i, j;
	int *res = new int[N * M];
	
	if(N == M1){
		for(i = 0; i < M; i++){
			for(j = 0; j < N; j++){
				res[j + N * i] = arr1[j + N * i] * arr2[j * N + i];
				if(res[j + N * i] < 0)
					printf("%d\n", arr2[j * N + i]);
			}
		}
	}

	return res;
}

void matprint(int N, int M, int *a){
	int i, j;
	
	printf("Your numbers:\n");
	for(i = 0; i < N; i++){
		printf("    ");
		for(j = 0; j < M; j++){
			printf("%d ", a[j + N * i]);
		}
		printf("\n");
	}
	printf("\n");
}