//Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


void LengthCount(struct node *head)
{
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("\nLength Of Linked List is :- %d\n",count); 
}

int main()
{
 struct node *head,*newnode,*temp;
 head=0;
 int choice=1;
 while(choice)
 {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value : \n");
    scanf("%d",&newnode->data);
    newnode->next=0;

    if(head==0)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    printf("do you want to add another node, if yes press 1 else press 0 :- ");
    scanf("%d",&choice);
 }
    temp=head;
    while(temp!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    LengthCount(head);
return 0;
}

//If not working in vs code we can use online compiler to run this code