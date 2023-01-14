// Implementation of Circular Queue using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *link;
};

void addcirq(struct node **, struct node **, int);
int delcirq(struct node **, struct node **);
void cirq_display(struct node *);
void printMenu();
int main()
{
    struct node *front = NULL, *rear = NULL;
    int data, ch, data1;
    printMenu();
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted/entered\n");
            scanf("%d", &data);
            addcirq(&front, &rear, data);
            break;
        case 2:
            data1 = delcirq(&front, &rear);
            if (data1 != -1000)
                printf("The deleted element is %d\n", data1);
            break;
        case 3:
            printf("The contents of the queue are");
            cirq_display(front);
            printf("\n");
            break;
        case 4:
            exit(1);
        default:
            printf("Enter valid choice");
        }
    }
    return 0;
}

void printMenu()
{
    printf("Choice 1 : Enter element into Queue\n");
    printf("Choice 2 : Delete element from Queue\n");
    printf("Choice 3 : Display\n");
    printf("Choice 4 : Exit\n");
}

void addcirq(struct node **f, struct node **r, int item)
{

    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = item;
    nn->link = NULL;
    if (*f == NULL)
    {
        *f = nn;
        *r = nn;
        (*r)->link = *f;
    }
    else
    {
        (*r)->link = nn;
    }
    *r = nn;
    (*r)->link = *f;
}

int delcirq(struct node **f, struct node **r)
{
    int re = -1000, value;
    struct node *p;
    if (*f == NULL)
    {
        printf("Queue is empty\n");
        return re;
    }
    else
    {
        if (*f == *r)
        {
            value = (*f)->data;
            free(*f);
            *f = *r = NULL;
        }
        else
        {
            p = *f;
            value = p->data;
            *f = (*f)->link;
            (*r)->link = *f;
            free(p);
        }
        return value;
    }
    return re;
}

void cirq_display(struct node *f)
{
    struct node *p = f, *s = NULL;
    if (f == NULL)
    {
        printf(" {}");
    }
    while (p != s)
    {
        printf(" %d", p->data);
        p = p->link;
        s = f;
    }
}