//Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node *CreatNode();
void display(struct node *head);
void InsertAtBegning(struct node **head);
void InsertAtEnd(struct node **head);
void InsertAfterThePosition(struct node *temp);
void Delete_From_beg(struct node **head);
void Delete_From_end(struct node **head);
void Delete_After_pos(struct node *temp,struct node *next);
struct node
{
    int data;
    struct node *next;
};
struct node *CreatNode()
{
    struct node *NextNode;
    NextNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Value\n");
    scanf("%d",&NextNode->data);
    NextNode->next=NULL;
    return NextNode;
}

void InsertAtBegning(struct node **head)
{
    struct node* NextNode=CreatNode();
    NextNode->next=*head;
    *head=NextNode;
}


void InsertAtEnd(struct node **head)
{
    struct node* NextNode=CreatNode();
    struct node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NextNode;
}



void InsertAfterThePosition(struct node *temp)
{
    struct node *NextNode=CreatNode();
    NextNode->next=temp->next;
    temp->next=NextNode;
}

void Delete_From_beg(struct node **head)
{
  struct node *temp;
  temp=*head;
  *head=temp->next;
  //*head=head->next; will also work
  free(temp);
}

void Delete_From_end(struct node **head)
{
    struct node *prev;
    struct node *temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void Delete_After_pos(struct node *temp,struct node *next)
{
    temp->next=next->next;
    free(next);
}


void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    struct node *head;
    head=NULL;
    int choice=1;
    struct node* temp;
    while(choice)
    {
        struct node *NextNode=CreatNode();
        if(head==NULL)
        {
            head=temp=NextNode;
        }
        else
        {
            temp->next=NextNode;
            temp=NextNode;
        }
        printf("Do you want to add node 1/0\n");
        scanf("%d",&choice);
    }
    printf("Created LinkedList\n");
    display(head);
    choice=1;
    while(choice)
    {
        printf("\n1) Insert At Begning\n");
        printf("2) Insert At End\n");
        printf("3) Insert After the Position\n");
        printf("4) Delete From Begning\n");
        printf("5) Delete from End\n");
        printf("6) Delete node after a given Position\n");
        printf("0) Exit");
        printf("\n");
       
        printf("Enter the Choice\n");
        scanf("%d",&choice);
       
        switch(choice)
        {
            case 1:
            printf("To Insert At the Begning\n ");
            InsertAtBegning(&head);
            break;
           
            case 2:
            printf("To Insert At the End\n ");
            InsertAtEnd(&head);
            break;
           
            case 3:
            int pos;
            printf("Enter the position after which to insert:");
            scanf("%d",&pos);
            struct node *temp=head;
            for(int i=1;i<pos && temp!=NULL;i++)
            {
                temp=temp->next;
            }
           
            if(temp!=NULL)
            {
                InsertAfterThePosition(temp);
            }
            else{
                printf("Pos is not in the list\n");
            }
            break;
           
           
            case 4:
            printf("Deleting From Begning\n");
            Delete_From_beg(&head);
            break;
           
            case 5:
            printf("Deleting From end");
            Delete_From_end(&head);
            break;
           
            case 6:
            int position;
            printf("Enter the position after which you want to delete node\n");
            scanf("%d",&position);
            struct node *next;
            temp=head;
            for(int i=1;i<position && temp!=NULL;i++)
            {
                temp=temp->next;
                next=temp->next;
               
            }
            if(temp!=NULL)
            {
                Delete_After_pos(temp,next);
               
            }
            else
            {
                printf("position not found\n");
            }
            break;
           
           
            case 0:
            printf("Exiting...\n");
            exit(0);
           
            default:
            printf("Invalid Input\n");
           
        }
        printf("Updated Linked List: ");
        display(head);
        printf("\n");
    }
}