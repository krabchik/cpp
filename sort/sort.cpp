#include <stdio.h>

void sort(int *a, int N);

int main(){
	
	int N, i;
	scanf("%d", &N);
	int *a = new int [N];
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	sort(a, N);
	for(i = 0; i < N; i++){
		printf("%d  ", a[i]);
	}
}

void sort(int *a, int N){
	
	int i, j, tmp;
	for(i = 0; i < N; i++){
		for(j = i + 1; j < N - 1; j++){
			if(a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

