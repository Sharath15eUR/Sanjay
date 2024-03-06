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
		temp=front;
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int countelements(){
	struct node* temp=front;
	int count=0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

int main(){
	printf("Initialize a queue!\n");
    printf("Check the queue is empty or not? ");
    if (front == NULL && rear == NULL)
        printf("Yes\n");
    else
        printf("No\n");
    printf("Number of elements in queue: %d\n", countelements());
    
    printf("Insert some elements into the queue:\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("Queue elements are: ");
    disp();
    printf("Number of elements in queue: %d\n", countelements());
    
    printf("Delete two elements from the said queue:\n");
    dequeue();
    dequeue();
    printf("Queue elements are: ");
    disp();
    printf("Number of elements in queue: %d\n", countelements());
    
    printf("Insert another element into the queue:\n");
    enqueue(4);
    printf("Queue elements are: ");
    disp();
    printf("Number of elements in the queue: %d\n", countelements());

    return 0;
}
