//Singly Linked List
#include <stdio.h>
#include <stdlib.h>
void insert_at_last();
void insert_at_start();
void display();
typedef struct list
{
    int data;
    struct list *next;
} node;
node *head = NULL;
int main()
{
    int choice, run = 1;
    printf("Press 1 for Inserting at start\n");
    printf("Press 2 for Inserting at last\n");
    printf("Press 3 for Inserting at given position\n");
    printf("Press 4 for Deleting at start\n");
    printf("Press 5 for Deleting at last\n");
    printf("Press 6 for Deleting at given position\n");
    printf("Press 7 for Displaying the list Reverse\n");
    printf("Press 8 for Reversing the List\n");
    printf("Press 9 for Display\n");
    printf("Press 10 for EXIT\n");
    while (run)
    {
        printf("\nEnter your choice: ");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
        {
            insert_at_start();
            break;
        }
        case 2:
        {
            insert_at_last();
            break;
        }
        case 3:
        {
            insert_at_given_pos();
            break;
        }
        case 4:
        {
            delete_at_start();
            break;
        }
        case 5:
        {
            delete_at_end();
            break;
        }
        case 6:
        {
            delete_at_given_pos();
            break;
        }
        case 7:
        {
            display_reverse();
            break;
        }
        case 8:
        {
            reverse_the_list();
            break;
        }
        case 9:
        {
            display();
            break;
        }
        case 10:
        {
            goto arin;
        }
        default:
        {
            printf("Enter Valid Choice");
            break;
        }
        }
    }
arin:
    return 0;
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void insert_at_start()
{
    node *new;
    new = (node *)malloc(sizeof(node));
    printf("Enter Data\n");
    scanf("%d", &(new->data));
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
}
void insert_at_last()
{
    node *new, *temp = head;
    new = (node *)malloc(sizeof(node));
    printf("Enter Data\n");
    scanf("%d", &(new->data));
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void delete_at_start()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Deletion Not Possible\n");
        return;
    }
    head = head->next;
    free(temp);
}
void delete_at_end()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Deletion Not Possible\n");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        // last = *head;
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}
void display_reverse()
{
    node *temp = head;
    if (head == NULL)
        return;
    else
    {
        display_reverse(head->next);
        printf("%d", temp->data);
    }
}

void reverse_the_list()
{
    node *prev, *curr, *NEXT;
    prev = NULL;
    curr = head;
    NEXT = NULL;
    while (curr != NULL)
    {
        NEXT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NEXT;
    }
    head = curr;
}
void insert_at_given_pos()
{
    int i, loc, item;
    node *ptr, *temp;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d", &loc);
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted");
    }
}
void delete_at_given_pos()
{
    node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d ", loc + 1);
}