   // Implementation of Stack using Array.
#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push()
{
    if(top>=n-1)
    {
        printf("\n\tStack Overflow\n");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\tStack Underflow\n");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n %d",stack[i]);
        printf("\n");
    }
    else
    {
        printf("\n The Stack is empty");
    }
   
}
int main()
{
    top=-1;
    printf("\n Enter the size of Stack : ");
    scanf("%d",&n);
    printf("\n\t Stack operations using array");
    printf("\n\t------------------------------");
    printf("\n\t 1.Push\n\t 2.Pop\n\t 3.Display\n\t 4.Exit\n");
    do
    {
        printf("\n Enter the Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\tWrong Choice: please see the options");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
