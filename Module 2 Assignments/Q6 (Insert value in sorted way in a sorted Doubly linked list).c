#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

struct node* createnode(int data){
	struct node*  nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	nn->prev=NULL;
}

void ins(struct node *head, int d){
	struct node* nn= createnode(d);
	
	if(head == NULL || d<=head->data){
		nn->next=head;
		if(head!=NULL){
			head->prev=nn;
		}
		head = nn;
	}else{
		struct node* curr = head;
		while(curr->next != NULL && curr->next->data < d){
			curr = curr->next;
		}
		
		nn->next=curr->next;
		nn->prev=curr;
		if(curr->next != NULL)
			curr->next->prev=nn;
		curr->next=nn;
	}
}

void disp(struct node* head){
	struct node* curr =  head;
	while(curr != NULL){
		printf("%d -> ",curr->data);
		curr=  curr->next;
	}
	printf("NULL\n");
}

int main(){
	struct node* head= createnode(3);
	head->next= createnode(5);
	head->next->prev=head;
	head->next->next=createnode(8);
	head->next->next->prev=head->next;
	head->next->next->next=createnode(10);
	head->next->next->next->prev=head->next->next;
	head->next->next->next->next=createnode(12);
	head->next->next->next->next->prev=head->next->next->next;
	
	printf("The inital LinkedList is: ");
	disp(head);
	
	ins(head, 9);
	
	printf("The LinkedList after adding a Value: ");
	disp(head);
	
	return 0;
}
