//Linear Linked List
#include <stdio.h>
#include <stdlib.h>
void insert_at_last();
void insert_at_start();
void display();
typedef struct list{
    int data;
    struct list *next;
}node;
node *head=NULL;
int main(){
    int choice,run=1;
    printf("Press 1 for Inserting at start\n");
    printf("Press 2 for Inserting at last\n");
    printf("Press 3 for Display\n");
    printf("Press 4 for EXIT\n");
    while(run){
    printf("\nEnter your choice: ");
    scanf("\n%d",&choice);
    switch(choice)
    {
        case 1:{ insert_at_start(); break ; }
        case 2:{ insert_at_last(); break ; }
        case 3:{ insert_at_given_pos(); break; }
        case 4:{ delete_at_start();break;}
        case 5:{ delete_at_end();break;}
        case 6:{ delete_at_given_pos();break;}
        case 7:{ display(); break; }
        case 8:{ goto arin; }
        default:{printf("Enter Valid Choice"); break;}
    } 
        } arin:
    return 0;
}

void display(){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void insert_at_start(){
    node *new;
    new=(node*)malloc(sizeof(node));
    printf("Enter Data\n");
    scanf("%d",&(new->data));
    new->next=NULL;
    if (head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head=new;
    }
}
void insert_at_last(){
    node *new,*temp=head;
    new=(node*)malloc(sizeof(node));
    printf("Enter Data\n");
    scanf("%d",&(new->data));
    new->next=NULL;
    if (head==NULL){
        head=new;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}