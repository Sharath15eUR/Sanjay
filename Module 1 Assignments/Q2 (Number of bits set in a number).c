#include<stdio.h>
int main(){
	int num,count,t;
	printf("Enter a Number: ");
	scanf("%d", &num);
	count=0;
	while(num!=0){
		t=num&1;
		if(t==1)
			count+=1;
		num>>=1;
	}
	printf("The number of Bits set in the number is  : %d", count);
	return 0;
}

