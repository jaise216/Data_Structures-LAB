#include<stdio.h>
#include<stdlib.h>
struct Node
    {
        int data;
        struct Node *next;
    }*head=NULL;
void insertAtBeginning(int);
void insertAtLast(int);
void insertInBw(int,int,int);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtSpec(int);
void display();
void main()
{
    int ch,c,value,loc1,loc2,r;
    do
    {
    printf("enter your choice:\n 1.insertion\n 2.deletion\n 3.traversal\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("where do you want to insert:\n 1.at the beginning of the list\n 2.at the end of the list\n 3.in between the list\n");
        scanf("%d",&c);
        printf("enter the value to be inserted:");
        scanf("%d",&value);
        switch (c)
        {
        case 1: insertAtBeginning(value);display();break;
        case 2: insertAtLast(value);display();break;
        case 3: printf("enter the position where node has to be inserted:\n");
                scanf("%d%d",&loc1,&loc2);
                insertInBw(value,loc1,loc2);display();break;
        default:printf("enter correct choice\n");
        }
    }
    else if(ch==2)
    {
        printf("where do you want to delete:\n 1.node at the beginning\n 2.node at the end\n 3.a specific node \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: deleteAtBeg();display();break;
            case 2: deleteAtEnd();display();break;
            case 3: printf("enter the node to be deleted:");
                    scanf("%d",&value);
                    deleteAtSpec(value);display();break;
            default:printf("enter correct choice:");
        }
    }
    else if(ch==3)
        {display();}
    else
        {printf("enter correct choice");}
    printf("do you wish to continue?\n press 0 if yes\n press 1 if no\n");
    scanf("%d",&r);
    }
    while(r==0);
}
void insertAtBeginning(int value)
{
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
    printf("node inserted at the beginning !!!\n");
}
void insertAtLast(int value)
{
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else
    {
        struct Node*temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    printf("node inserted at last position !!!\n");
}
void insertInBw(int value,int loc1,int loc2)
{
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        struct Node*temp=head;
        while((temp->data!=loc1)&&(temp->data!=loc2))
            temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    printf("node inserted !!!\n");
}
void deleteAtBeg()
{
    struct Node*temp=head;
    if(head==NULL)
        printf("list is empty !!!\n");
    else
    {
        temp=head;
        head= head->next;
        free(temp);
        printf("front node deleted !!!\n");
    }
}
void deleteAtEnd()
{
    if(head==NULL)
        printf("list is empty !!!\n");
    else
    {
        struct Node*temp=head,*prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==head)
            head=NULL;
        else
        {
            prev->next=temp->next;
            free(temp);
        }
    }
    printf("end node deleted !!!\n");
}
void deleteAtSpec(int value)
{
    if(head==NULL)
        printf("list is empty !!!\n");
    struct Node*temp=head,*prev;
    if((temp->next!=NULL)&&(temp->data==value))
    {
        head=temp->next;
        free(temp);
        printf("node deleted !!!\n");
    }
    while((temp->next!=NULL)&&(temp->data!=value))
    {
        prev=temp;
        temp=temp->next;
    }
    if((temp->next==NULL)&&(temp->data!=value))
        printf("element was not found !!!\n");
    else
    {
        prev->next=temp->next;
        free(temp);
        printf("node deleted !!!\n");
    }
}
void display()
{
    struct Node*temp=head;
    if(temp==NULL)
        printf("empty list !!!\n");
    else
    {
    printf("List...\n");
    while(temp->next!=NULL)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
    printf("%d--->NULL\n",temp->data);
    }
}
