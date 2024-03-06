#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertbegin(struct node **head, int d){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = d;
	new_node->next = (*head);
	(*head) = new_node;
}

void display(struct node* curr){
	while(curr != NULL){
		printf("%d->",curr->data);
		curr=curr->next;
	}
	printf("\n");
}

void rmduplicate(struct node* head){
	struct node* curr = head;
	struct node* temp;
	
	if(curr == NULL)
		return;
		
	while(curr->next != NULL){
		if(curr->data == curr->next->data){
			temp = curr->next->next;
			free(curr->next);
			curr->next =  temp;
		}
		else{
			curr=curr->next;
		}
	}
}

int main(){
	struct node* head = NULL;
	
	insertbegin(&head,4);
	insertbegin(&head,3);
	insertbegin(&head,3);
	insertbegin(&head,2);
	
	printf("Initial List: ");
	display(head);
	
	rmduplicate(head);
	printf("Linked list after removing duplicates: \n");
	display(head);
	return 0;
}
