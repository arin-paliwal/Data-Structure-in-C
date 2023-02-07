#include <stdio.h>
#include <malloc.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
} *root;

void find(int item, struct node **par, struct node **loc)
{
    struct node *ptr, *ptrsave;

    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->value)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->value)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;

    while (ptr != NULL)
    {
        if (item == ptr->value)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}

void insert(int item)
{
    struct node *temp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL)
    {
        printf("Item already present");
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = item;
    temp->left = NULL;
    temp->right = NULL;

    if (parent == NULL)
        root = temp;
    else if (item < parent->value)
        parent->left = temp;
    else
        parent->right = temp;
}

void case_a(struct node *par, struct node *loc)
{
    if (par == NULL)
        root = NULL;
    else if (loc == par->left)
        par->left = NULL;
    else
        par->right = NULL;
}

void case_b(struct node *par, struct node *loc)
{
    struct node *child;

    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;

    if (par == NULL)
        root = child;
    else if (loc == par->left)
        par->left = child;
    else
        par->right = child;
}

void case_c(struct node *par, struct node *loc)
{
    struct node *ptr, *ptrsave, *suc, *parsuc;

    /*Find inorder successor and its parent*/
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;

    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);

    if (par == NULL)
        root = suc;
    else if (loc == par->left)
        par->left = suc;
    else
        par->right = suc;

    suc->left = loc->left;
    suc->right = loc->right;
}

int del(int item)
{
    struct node *parent, *location;
    if (root == NULL)
    {
        printf("Tree empty");
        return 0;
    }

    find(item, &parent, &location);
    if (location == NULL)
    {
        printf("Item not present in tree");
        return 0;
    }

    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}

int preorder(struct node *ptr)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return 0;
    }
    if (ptr != NULL)
    {
        printf("%d  ", ptr->value);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(struct node *ptr)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d  ", ptr->value);
        inorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d  ", ptr->value);
    }
}

void display(struct node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->value);
        display(ptr->left, level + 1);
    }
}
int main()
{
    int choice, num;
    root = NULL;
    while (1)
    {
        printf("\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Inorder Traversal\n");
        printf("4.Preorder Traversal\n");
        printf("5.Postorder Traversal\n");
        printf("6.Display\n");
        printf("7.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted : ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            printf("Enter the number to be deleted : ");
            scanf("%d", &num);
            del(num);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            display(root, 1);
            break;
        case 7:
            break;
        default:
            printf("Wrong choice\n");
        }
    }
}
