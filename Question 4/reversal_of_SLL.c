#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *reverse(struct node *head){
    struct node* curr = head, *prev = NULL, *Next = NULL;
    while(curr != NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    head = prev;
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

    printf("Original Linked List: \n");
	display(head);
    head = reverse(head);
    printf("\nReverse Linked List: \n");
    display(head);

    return 0;
}