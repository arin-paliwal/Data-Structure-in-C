#include <stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;
void insertatbeg(node **start, int item)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = *start;
    *start = ptr;
}
void insertatend(node **start, int item)
{
    node *ptr, *last;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = NULL;
    if (*start == NULL)
        *start = ptr;
    else
    {
        last = *start;
        while (last->next != NULL)
            last = last->next;
        last->next = ptr;
    }
}
void display(node *start)
{
    if (start == NULL)
    {
        printf("\n LINKED LIST IS EMPTY");
        return;
    }
    while (start != NULL)
    {
        printf("%d->", start->info);
        start = start->next;
    }
}
void deleteatbeg(node **start)
{
    node *ptr;
    if (*start == NULL)
    {
        printf("\n LINKED LIST IS EMPTY");
        return;
    }
    ptr = *start;
    *start = ptr->next;
    printf("\n Deleted value=%d", ptr->info);
    free(ptr);
}
void deleteatend(node **start)
{
    node *ptr, *last;
    if (*start == NULL)
    {
        printf("\n LINKED LIST IS EMPTY");
        return;
    }
    if ((*start)->next == NULL)
    {
        ptr = *start;
        *start = NULL;
    }
    else
    {
        last = *start;
        while (last->next->next != NULL)
            last = last->next;
        ptr = last->next;
        last->next = NULL;
    }
    printf("\n Deleted value=%d", ptr->info);
    free(ptr);
}
void displayreverse(node *start)
{
    if (start->next != NULL)
        displayreverse(start->next);
    printf("%d->", start->info);
}
void reverse(node **start)
{
    node *pnode, *cnode, *nnode;
    pnode = NULL;
    cnode = *start;
    nnode = cnode->next;
    cnode->next = NULL;
    while (nnode != NULL)
    {
        pnode = cnode;
        cnode = nnode;
        nnode = cnode->next;
        cnode->next = pnode;
    }
    *start = cnode;
}
int main()
{
    int item, choice;
    node *head;
    head = NULL;
    while (1)
    {
        printf("\n------LINKED LIST MENU-----");
        printf("\n 1) INSERT AT BEGINNING");
        printf("\n 2) INSERT AT END");
        printf("\n 3) DELETE AT BEGINNING");
        printf("\n 4) DELETE AT END");
        printf("\n 5) DISPLAY IN ORDER");
        printf("\n 6) DISPLAY IN REVERSE");
        printf("\n 7) REVERSING OF LINKED LIST");
        printf("\n 8) EXIT");
        printf("\n ENTER YOUR CHOICE");
        scanf("\n %d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n ENTER ITEM=");
            scanf("%d", &item);
            insertatbeg(&head, item);
            break;
        case 2:
            printf("\n ENTER ITEM=");
            scanf("%d", &item);
            insertatend(&head, item);
            break;
        case 3:
            deleteatbeg(&head);
            break;
        case 4:
            deleteatend(&head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            displayreverse(head);
            break;
        case 7:
            reverse(&head);
            break;
        default:
            exit(1);
        }
    }
}
