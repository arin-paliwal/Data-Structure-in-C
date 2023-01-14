  // Implementation of Stack using Linked List using C

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* top = NULL;
struct Node* temp;
int count = 0;

void display()
{
	temp = top;
	if(count == 0)
	{
		printf("\nStack is Empty!\n");
		return;
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}	
		printf("\n");
	}
}

void push(int el)
{
	if(top == NULL)
	{
		top = (struct Node*) malloc(sizeof(struct Node*));
		top->data = el;
		top->next = NULL;
	}
	else
	{
		temp = (struct Node*) malloc(sizeof(struct Node*));
		temp->next = top;
		temp->data = el;
		top = temp;
	}
	count++;
}

void pop()
{
	temp = top;
	if(top == NULL)
	{
		printf("\nStack is empty!\n");
		exit(1);
	}
	else
		temp = temp->next;
	
	printf("\nItem removed is %d\n", top->data);
	free(top);
	top = temp;
	count--;
}


int main()
{
	int choice;
	int el;
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Element to be inserted:\n");
				scanf("%d", &el);
				push(el);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
            case 4:
                exit(1);
			default:
				printf("\nInvalid Input!\n");			
		}
	}
	return 0;
}