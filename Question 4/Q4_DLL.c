#include <stdio.h> 
#include<stdlib.h>
typedef struct nodetype
{
    struct nodetype *prev;
    int info;
    struct nodetype *next;
} node;
void insertatbegDLL(node **start, node **end, int item)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->prev = NULL;
    if (*start == NULL)
    {
        ptr->next = NULL;
        *start = *end = ptr;
    }
    else
    {
        ptr->next = *start;
        (*start)->prev = ptr;
        *start = ptr;
    }
}
void insertatendDLL(node **start, node **end, int item)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = NULL;
    if (*start == NULL)
    {
        ptr->prev = NULL;
        *start = *end = ptr;
    }
    else
    {
        ptr->prev = *end;
        (*end)->next = ptr;
        *end = ptr;
    }
}
void deleteatbegDLL(node **start, node **end)
{
    node *ptr;
    if (*start == NULL)
    {
        printf("\n DLL IS EMPTY");
        return;
    }
    ptr = *start;
    if (*start == *end)
    {
        *start = *end = NULL;
    }
    else
    {
        ptr->next->prev = NULL;
        *start = ptr->next;
    }
    printf("\n DELETED VALUE=%d", ptr->info);
    free(ptr);
}
void deleteatendDLL(node **start, node **end)
{
    node *ptr;
    if (*start == NULL)
    {
        printf("\n DLL IS EMPTY");
        return;
    }
    ptr = *end;
    if (*start == *end)
    {
        *start = *end = NULL;
    }
    else
    {
        ptr->prev->next = NULL;
        *end = ptr->prev;
    }
    printf("\n DELETED VALUE=%d", ptr->info);
    free(ptr);
}
void displayinorder(node *start)
{
    if (start == NULL)
    {
        printf("\n DLL IS EMPTY");
        return;
    }
    while (start != NULL)
    {
        printf("%d", start->info);
        start = start->next;
    }
}
void displayinreverse(node *end)
{
    if (end == NULL)
    {
        printf("\n DLL IS EMPTY");
        return;
    }
    while (end != NULL)
    {
        printf("%d", end->info);
        end = end->prev;
    }
}
int main()
{
    int item, choice;
    node *start, *end;
    start = end = NULL;
        printf("\n 1) INSERT AT BEGINNING");
        printf("\n 2) INSERT AT END");
        printf("\n 3) DELETE AT BEGINNING");
        printf("\n 4) DELETE AT END");
        printf("\n 5) DISPLAY IN ORDER");
        printf("\n 6) DISPLAY IN REVERSE");
        printf("\n 7) EXIT");
    while (1)
    {
        printf("\n ENTER YOUR CHOICE");
        scanf("\n %d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n ENTER ITEM=");
            scanf("%d", &item);
            insertatbegDLL(&start, &end, item);
            break;
        case 2:
            printf("\n ENTER ITEM=");
            scanf("%d", &item);
            insertatendDLL(&start, &end, item);
            break;
        case 3:
            deleteatbegDLL(&start, &end);
            break;
        case 4:
            deleteatendDLL(&start, &end);
            break;
        case 5:
            displayinorder(start);
            break;
        case 6:
            displayinreverse(end);
            break;
        default:
            exit(1);
        }
    }
}
