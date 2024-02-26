#include<stdio.h>

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int a,b;
	printf("Enter two numbers: ");
	scanf("%d %d", &a , &b );
	printf("\nThe two numbers before swapping: 'a = %d' 'b = %d'.", a,b );
	
	void (*ptr)(int *, int *);
	ptr = swap;
	
	(*ptr)(&a,&b);
	
	printf("\nThe two numbers after swapping: 'a = %d' 'b = %d'.", a,b );
	return 0;
}
