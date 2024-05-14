//Insertion in Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node *CreatNode();
void DisplayList(struct node *head);
void Insert_at_beg(struct node **head);
void Insert_at_end(struct node **head);
void Insert_after_pos(struct node *temp);
struct node
{
    int data;
    struct node *next;
};
struct node *CreatNode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}
//Insert at the Beg 
void Insert_at_beg(struct node **head)
{
    struct node * newnode=CreatNode();
    newnode->next=*head;
    *head=newnode;
}

void Insert_at_end(struct node **head)
{
    struct node * newnode=CreatNode();
    struct node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;            
}

void Insert_after_pos(struct node *temp)
{
    struct node * newnode=CreatNode();

    newnode->next=temp->next;
    temp->next=newnode;
}

void DisplayList(struct node *head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *temp;
    struct node *head=NULL;
    int choice=1;
    printf("First Creat a LinkedList\n");
    while(choice)
    {
        struct node *newnode=CreatNode();
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you to add node 1 ya 0\n");
        scanf("%d",&choice);
    }
    printf("Created LinkedList\n");
    DisplayList(head);
    choice=1;
   
    while(choice)
    {
        printf("\n1) Insert At Begning\n");
        printf("2) Insert At End\n");
        printf("3) Insert After the Position\n");
        printf("4) Exit\n");
       
        printf("Enter your Choice\n");
        scanf("%d",&choice);
       
        switch(choice)
        {
            case 1:
            printf("Enter the data to Insert at Begning\n");
            Insert_at_beg(&head);
            break;
           
            case 2:
            printf("Enter the data to Insert at End\n");
            Insert_at_end(&head);
            break;
            case 3:
            int pos;
            printf("Enter the Position After which you want to insert\n");
            scanf("%d",&pos);
            temp=head;
            for(int i=1; i<pos && temp!=NULL; i++)
            {
                temp=temp->next;
            }
           
            if(temp!=NULL)
            {
                printf("Enter the data to Insert after the given Position\n");
                Insert_after_pos(temp);
            }
            else
            {
                printf("Position doesnot exist\n");
            }
            break;
            case 4:
            printf("Exiting...\n");
            exit(0);
            break;
        }
        printf("Updated LinkedList\n");
        DisplayList(head);
    }
}