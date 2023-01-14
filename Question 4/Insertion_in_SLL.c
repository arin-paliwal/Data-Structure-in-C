#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *insert_at_front(struct node *head, int val){
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = val;
	if(head == NULL){
		head = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
	return head;
}

struct node *insert_at_end(struct node *head, int val){
	struct node* newNode, *temp = head;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = val;
	if(head == NULL){
		head = newNode;
	}
	else{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	return head;
}

struct node *insert_at_pos(struct node *head, int val, int pos){
	struct node* newNode, *temp = head, *prev = head;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = val;
	if(head == NULL){
		if(pos == 1)
			head = newNode;
		else
			printf("Insertion Not Possible! ");
	}
	else{
		int count = 1;
		if(pos == 1){
			newNode->next = head;
			head = newNode;
		}
		else{
			while(count != pos - 1 && temp->next != NULL){
				count++;
				temp = temp->next;
			}
			if(count == pos - 1){
				newNode->next = temp->next;
				temp->next = newNode;
			}
			else
				printf("Insertion Not Possible! ");
		}
	}
	return head;
}

void display(struct node* head){
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
}

int main(){
    struct node* head = NULL;
	int arin=1;
	display(head);
    int data;
	printf("\nEnter data which you want to insert: ");
	scanf("%d", &data);
	printf("\n which type of insertion u want to perform: \n");
	printf("1. insertion at start. \n");
	printf("2. insertion at end. \n");
	printf("3. insertion at some position. \n");
	while(arin){
	printf("Enter your choice: ");
	int choice;
	scanf("%d", &choice);
	switch(choice){
		case 1:{
			head = insert_at_front(head, data);
			display(head);
			break;
		}

		case 2:{
			head = insert_at_end(head, data);
			display(head);
			break;
		}

		case 3:{
			int pos;
			printf("enter at which position you want to perform insertion: \n");
			scanf("%d", &pos);
			head = insert_at_pos(head, data, pos);
			display(head);
			break;
		}
		default:
			printf("select between 1 - 3 \n");
	}
	
	}
	return 0;
}