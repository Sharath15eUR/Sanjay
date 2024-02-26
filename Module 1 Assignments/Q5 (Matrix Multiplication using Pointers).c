#include<stdio.h>
#include<stdlib.h>

void multiply(int **a, int **b, int **res, int size);
void disp(int **res, int size);

int main(){
	int n,i,j,k;
	int **mat1, **mat2, **res;
	printf("Enter the dimension for the matrix: ");
	scanf("%d", &n);
	
	mat1=(int **)malloc(n*sizeof(int*));
	mat2=(int **)malloc(n*sizeof(int*));
	res=(int **)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++){
		mat1[i]=(int *)malloc(n*sizeof(int));
		mat2[i]=(int *)malloc(n*sizeof(int));
		res[i]=(int *)malloc(n*sizeof(int));
	}
	
	printf("Enter the values for matrix 1: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &mat1[i][j]);
		}
	}
	
	printf("Enter the values for matrix 2: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &mat2[i][j]);
		}
	}
	
	multiply(mat1, mat2, res, n);
	
	printf("The product of two matrices is:\n ");
	disp(res, n);
	
	return 0;
}

void multiply(int **a, int **b, int **res, int size){
	
	int i,j,k;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			res[i][j] = 0;
			for(k=0;k<size;k++){
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}


void disp(int **res, int size){
	int i, j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf(" %d ", res[i][j]);
		}
		printf("\n");
	}
}

