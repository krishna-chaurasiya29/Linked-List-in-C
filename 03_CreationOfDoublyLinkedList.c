#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct node *CreateNode();
void Display(struct node *head);

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*temp;

struct node *CreateNode()
{
    struct node *newNode;
    newNode =(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    newNode->prev= NULL;
    return newNode;
}

void Display( struct node *head)
{
    temp =head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
head =NULL;
int choice=1;
printf("Creating The Doubly Linked List\n");
while(choice)
{
    struct node *newNode=CreateNode();
    if(head==NULL)
    {
        head=temp=newNode;
    }
    else
    {
        temp->next=newNode;
        newNode->prev=temp;
        temp=temp->next;
    }
    printf("Do you want add one more Node,If Yes press 1 or if NOT press 0\n");
    scanf("%d",&choice);
}
printf("The Updated Linked List is \n");
Display(head);
return 0;
}