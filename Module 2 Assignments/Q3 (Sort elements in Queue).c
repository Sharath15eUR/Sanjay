#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int d){
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = d;
	ptr->next = NULL;
	
	if((front == NULL) && (rear == NULL) ){
	
		front = rear = ptr;
	}
	else{
		rear->next = ptr;
		rear = ptr;
	}
}

int dequeue(){
	if(front == NULL){
		printf("Underflow!");
		return -1;
	}
	else{
		struct node* temp = front;
		int temp_d = front->data;
		front = front->next;
		free(temp);
		return temp_d;
	}
}

void disp(){
	struct node* temp;
	if((front == NULL) && (rear == NULL)){
		printf("Queue is empty!");
	}
	else{
		printf("The queue elements : ");
		temp=front;
		while(temp!=NULL){
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void sortqueue(){
	struct node *i, *j;
	int temp;
	if(front == NULL)
		return;
	
	for(i=front; i!=NULL; i=i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if(i->data > j->data){
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

int main(){
	enqueue(4);
	enqueue(2);
	enqueue(7);
	enqueue(5);
	enqueue(1);
	
	disp();
	
	sortqueue();
	
	printf("The queue after sorting!!! \n");
	disp();
	
	return 0;
}
