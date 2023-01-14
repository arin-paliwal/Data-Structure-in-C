// Implementation of Queue using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int key;
    struct Node *next;
};

struct Queue
{
    Node *head;
    Node *tail;
};

typedef struct Node Node;
typedef struct Queue Queue;

Queue *create_queue(void);
unsigned is_empty(Queue *);
int get_head(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);

Queue *create_queue()
{
    Queue *qu = malloc(sizeof(Queue));
    qu->head = NULL;
    qu->tail = NULL;
    return qu;
}

unsigned is_empty(Queue *qu)
{
    return qu->head == NULL && qu->tail == NULL;
}

int get_head(Queue *qu)
{
    assert(!is_empty(qu));
    return qu->head->key;
}

void enqueue(Queue *qu, int key)
{
    Node *nd = malloc(sizeof(Node));
    nd->key = key;
    nd->next = NULL;
    if (is_empty(qu))
    {
        qu->head = nd;
        qu->tail = nd;
    }
    else
    {
        qu->tail->next = nd;
        qu->tail = nd;
    }
}

void dequeue(Queue *qu)
{
    assert(!is_empty(qu));
    Node *tmp_node = qu->head;
    qu->head = tmp_node->next;
    free(tmp_node);
    if (qu->head == NULL)
        qu->tail = NULL;
}
int main()
{
    int n;
    printf("Enter the size of stack : ");
    scanf("%d", &n);
}
void display()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("The queue is \n");
        temp = front;
        while (temp)
        {
            printf("%d--->", temp - > data);
            temp = temp - > next;
        }
        printf("NULL\n\n");
    }
}
int main()
{
    int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            enqueue(,value);
            break;
        case 2:
            printf("Popped element is :%d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
    return 0;
}