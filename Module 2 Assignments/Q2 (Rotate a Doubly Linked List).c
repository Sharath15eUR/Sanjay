#include<stdio.h>
#include<stdlib.h>

struct node {
	char data;
	struct node* prev;
	struct node* next;
};

void insertend(struct node** head, char d){
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	struct node* tail = *head;
	new_node->data=d;
	new_node->next=NULL;
	
	if(*head == NULL){
		new_node->prev=NULL;
		*head = new_node;
		return;
	}	
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next=new_node;
	new_node->prev=tail;
}

void display(struct node* curr){
	while(curr != NULL){
		printf("%c ",curr->data);
		curr=curr->next;
	}
	printf("\n");
}

void rot(struct node** head,int n){
	if(*head == NULL || n==0)
		return;
	
	struct node* curr = *head;
	int  count=1;
	
	while(count<n && curr!=NULL){
		curr = curr->next;
		count++;
	}
	if(curr==NULL)
		return;
	
	struct node* n_node=curr;
	
	while(curr->next != NULL)
		curr = curr->next;
		
	curr->next= *head;
	(*head)->prev= curr;
	*head=n_node->next;
	(*head)->prev=NULL;
	n_node->next=NULL;
}

int main(){
	struct node* head=NULL;
	
	insertend(&head, 'a');
	insertend(&head, 'b');
	insertend(&head, 'c');
	insertend(&head, 'd');
	insertend(&head, 'e');
	insertend(&head, 'f');
	
	printf("Initial List: ");
	display(head);
	
	rot(&head,2);
	printf("List after rotating by 2 positions: \n");
	display(head);
	
	return 0;
}
