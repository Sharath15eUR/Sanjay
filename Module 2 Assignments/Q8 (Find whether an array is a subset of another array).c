#include<stdio.h>
#include<stdlib.h>

int subset(int a1[], int x, int a2[], int y){
	int i,j;
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			if(a2[i] == a1[j])
				break;
		}
		if(j==x)
			return 0;
	}
	return 1;
}

int main(){
	int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int x = sizeof(arr1) / sizeof(arr1[0]);
    int y = sizeof(arr2) / sizeof(arr2[0]);
    
    if(subset(arr1,x,arr2,y))
    	printf("The Array 2 is a subset of Array 1 \n\n");
    else
    	printf("The Array 2 is not a subset of Array 1 \n\n");
    	
    int arr3[] = {10, 5, 2, 23, 19};
    int arr4[] = {19, 5, 3};
    x = sizeof(arr3) / sizeof(arr3[0]);
    y = sizeof(arr4) / sizeof(arr4[0]);

    if(subset(arr3, x, arr4, y))
        printf("The Array 4 is a subset of Array 3\n");
    else
        printf("The Array 4 is not a subset of Array 3\n");

    return 0;
}
