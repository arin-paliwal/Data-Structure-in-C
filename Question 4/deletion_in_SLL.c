#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *deletion_at_front(struct node *head){
	struct node* temp = head;
	if(head == NULL)
		printf("Deletion not possible \n");
	
	else{
		head = head->next;
		free(temp);
	}
	return head;
}

struct node *deletion_at_end(struct node *head){
	struct node* temp = head;
	if(head == NULL)
		printf("Deletion not possible \n");
	
	else{
		if(head->next == NULL){
			head = NULL;
			free(temp);
		}
		else{
			while(temp->next->next != NULL)
				temp = temp->next;
			free(temp->next);
			temp->next = NULL;
		}
	}
	return head;
}

struct node *deletion_at_pos(struct node *head, int pos){
	struct node* temp = head, *prev = head;
	int count = 1;
	if(head == NULL)
		printf("Deletion not possible \n");
	
	else{
		if(pos == 1){
			head = head->next;
			free(temp);
		}
		else{
			while(count != pos && temp->next != NULL){
				count++;
				prev = temp;
				temp = temp->next;
			}
			if(count == pos){
				prev->next = temp->next;
				free(temp);
			}
			else	
				printf("Deletion not possible \n");
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
	struct node* second = NULL, *third = NULL, *four = NULL, *five = NULL;
	head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    four = (struct node*)malloc(sizeof(struct node));
    five = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = four;
    four->data = 4;
	four->next = five;
    five->data = 5;
	five->next = NULL;

	display(head);

	printf("\n which type of Deletion u want to perform: \n");
	printf("1. Deletion at start. \n");
	printf("2. Deletion at end. \n");
	printf("3. Deletion at some position. \n");

	printf("Enter key: ");

	int key;
	scanf("%d", &key);
	switch(key){
		case 1:{
			head = deletion_at_front(head);
			display(head);
			break;
		}

		case 2:{
			head = deletion_at_end(head);
			display(head);
			break;
		}

		case 3:{
			int pos;
			printf("enter at which position you want to perform deletion: \n");
			scanf("%d", &pos);
			head = deletion_at_pos(head, pos);
			display(head);
			break;
		}
		default:
			printf("select between 1 - 3 \n");
	}
	return 0;
}