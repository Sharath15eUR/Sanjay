#include<stdio.h>
int main(){
	int num;
	printf("Enter a Number: ");
	scanf("%d", &num);
	
	if(num&1)
		printf("%d is a Odd Number", num);
	else
		printf("%d is an Even Number", num);
	
	return 0;
}
