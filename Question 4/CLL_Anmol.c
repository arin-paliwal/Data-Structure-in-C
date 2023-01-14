//Circular Linked List
#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;
int main()
{
    int item, choice;
    node *head;
    head = NULL;
    printf("\n 1) INSERT AT BEGINNING");
    printf("\n 2) INSERT AT END");
    printf("\n 3) DELETE AT BEGINNING");
    printf("\n 4) DELETE AT END");
    printf("\n 5) DISPLAY IN ORDER");
    printf("\n 6) EXIT");
    while (1)
    {
        printf("\n Your Choice : ");
        scanf("\n %d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter Value : ");
            scanf("%d", &item);
            insertatbegCLL(&head, item);
            break;
        case 2:
            printf("\n Enter Value : ");
            scanf("%d", &item);
            insertatendCLL(&head, item);
            break;
        case 3:
            deleteatbegCLL(&head);
            break;
        case 4:
            deleteatendCLL(&head);
            break;
        case 5:
            displayCLL(head);
            break;
        default:
            exit(1);
        }
    }
}

void insertatbegCLL(node **start, int item)
{
    node *ptr, *last;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    if (*start == NULL)
        ptr->next = ptr;
    else
    {
        last = *start;
        while (last->next != *start)
            last = last->next;
        last->next = ptr;
        ptr->next = *start;
    }
    *start = ptr;
}
void insertatendCLL(node **start, int item)
{
    node *ptr, *last;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    if (*start == NULL)
    {
        ptr->next = ptr;
        *start = ptr;
    }
    else
    {
        last = *start;
        while (last->next != *start)
            last = last->next;
        ptr->next = last->next;
        last->next = ptr;
    }
}
void deleteatbegCLL(node **start)
{
    node *ptr, *last;
    if (*start == NULL)
    {
        printf("\n CLL IS EMPTY");
        return;
    }
    ptr = *start;
    if (ptr->next == ptr)
        *start = NULL;
    else
    {
        last = *start;
        while (last->next != *start)
            last = last->next;
        last->next = ptr->next;
        *start = (*start)->next;
    }
    printf("\n Deleted Value : %d", ptr->info);
    free(ptr);
}
void deleteatendCLL(node **start)
{
    node *ptr, *temp;
    if (*start == NULL)
    {
        printf("\n CLL IS EMPTY");
        return;
    }
    if ((*start)->next == *start)
    {
        ptr = *start;
        *start = NULL;
    }
    else
    {
        ptr = *start;
        temp = NULL;
        while (ptr->next != *start)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
    }
    printf("\n Deleted Value : %d", ptr->info);
    free(ptr);
}
void displayCLL(node *start)
{
    node *ptr;
    if (start == NULL)
    {
        printf("\n CLL IS EMPTY");
        return;
    }
    ptr = start;
    printf("%d ", ptr->info);
    ptr = ptr->next;
    while (ptr != start)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}
