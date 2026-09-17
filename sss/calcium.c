#include <stdio.h>

int MERGE(int N, int arrayA[], int arrayB[]){
	
	int merge[200], i, j, k=0, duplicate;
	
    for (i = 0; i < N; i++) {
        merge[k] = arrayA[i];
        k++;
    }

    for (i = 0; i < N; i++) {
        duplicate = 0;

        for (j = 0; j < k; j++) {
            if (arrayB[i] == merge[j]) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate == 0) {
            merge[k] = arrayB[i];
            k++;
        }
    }

    printf("\nMERGE array:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", merge[i]);
    }
}

int main () {
	int arrayA[99], arrayB[99], size, i;
	printf("Size of the array: ");
	scanf("%d", &size);
	
	printf("\nEnter %d values for Array A.\n", size);
	for(i=0; i<size; i++){
		scanf("%d", &arrayA[i]);
	}
	
	printf("\nEnter %d values for Array B.\n", size);
	for(i=0; i<size; i++){
		scanf("%d", &arrayB[i]);
	}
	
	MERGE(size, arrayA, arrayB);
	return 0;
}