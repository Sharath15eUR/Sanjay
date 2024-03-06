#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
struct stack {
	char items[max];
	int top;
};

int isempty(struct stack* s){
	return s->top == -1;
}

int isfull(struct stack* s){
	return s->top == max - 1;
}

void push(struct stack* s, char v){
	if(isfull(s)){
		printf("Stack Overflow!");
	}
	else{
		s->top++;
		s->items[s->top] = v;
	}
}

char pop(struct stack* s){
	char item;
	if(isempty(s)){
		printf("Stack is Empty! ");
		item= '\0';
	}
	else{
		item=s->items[s->top];
		s->top--;
	}
	return item;
}

void revstr(char *str){
	int l = strlen(str);
	int i;
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s->top = -1;
	
	for(i=0;i<l;i++){
		push(s,str[i]);
	}
	for(i=0;i<l;i++){
		 str[i]=pop(s);
	}
	free(s);
}

int main(){
	char str[] = "LetsLearn";
	printf("The given string : %s\n", str);
	revstr(str);
	printf("The string after reversing: %s\n",str);
	return 0;
}
