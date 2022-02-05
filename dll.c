#include<stdio.h>
#include<stdlib.h>
struct Node
    {
        int data;
        struct Node *next;
        struct Node *prev;
    }*head=NULL;
void insertAtBeg(int);
void insertAtEnd(int);
void insertInBw(int,int);
void deleteAtBeg();
void deleteAtEnd();
void deleteInBw(int);
void display();
void main()
{
    int ch,c,value,key,r,s;
do
{
    printf("enter your choice:\n 1.insertion \n 2.deletion \n 3.display\n");
    scanf("%d",&ch);
switch(ch)
{
case 1:
    printf("1.insertion at front \n 2.insertion at last \n 3.insert in between\n");
    scanf("%d",&c);
    printf("enter the value to be inserted:\n");
    scanf("%d",&value);
    if(c==1)
    {
        insertAtBeg(value);
        printf("node inserted at beginning!!!\n");
        display();
    }
    else if(c==2)
    {
        insertAtEnd(value);
        printf("node inserted at end!!!\n");
        display();
    }
    else if(c==3)
    {
        printf("enter the key after which node has to be inserted:\n");
        scanf("%d",&key);
        insertInBw(value,key);
        printf("node inserted in the list!!!\n");
        display();
    }
    else
    {
        printf("enter correct choice!!!");
    }
    break;
case 2:
    printf("1.deletion at front \n 2.deletion at last \n 3.deletion in between\n");
    scanf("%d",&c);
    if(c==1)
    {
        deleteAtBeg();
        display();
    }
    else if(c==2)
    {
        deleteAtEnd();
        display();
    }
    else if(c==3)
    {
        printf("enter the value to be deleted:\n");
        scanf("%d",&value);
        deleteInBw(value);
        display();
    }
    else
    {
        printf("enter correct choice!!!");
    }
    break;
case 3:
    display();
    break;
default:
    printf("enter the correct choice!!!");
}
printf("do you wish to continue? \n press 1 if yes\n press 0 if no\n");
scanf("%d",&r);
}while(r==1);
}
void insertAtBeg(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}
void insertAtEnd(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node*temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
    }
}
void insertInBw(int value,int key)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node*temp=head;
        while(temp->data!=key)
        {
            if(temp->next==NULL)
                printf("node not found!!!");
            else
                temp=temp->next;
        }
        if(temp->next==NULL)
        {
            newNode->prev=temp;
            temp->next=newNode;
        }
        else
        {
            newNode->prev=temp;
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}
void deleteAtBeg()
{
    if(head==NULL)
    {
        printf("the list is empty!!!\n");
    }
    else
    {
        struct Node*temp=head;
        if(temp->next==NULL&&temp->prev==NULL)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            temp->next->prev=NULL;
            head=temp->next;
            free(temp);
        }
     printf("first node deleted!!!\n");
    }
}
void deleteAtEnd()
{
    if(head==NULL)
    {
        printf("the list is empty!!!\n");
    }
    else
    {
        struct Node*temp=head;
        if(temp->next==NULL&&temp->prev==NULL)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->prev->next=NULL;
            free(temp);
        }
     printf("last node deleted!!!\n");
    }
}
void deleteInBw(int value)
{
    if(head==NULL)
    {
        printf("empty list deletion cannot be done\n");
    }
    else
    {
        struct Node *temp=head;
        while(temp->data!=value)
        {
            if(temp->next==NULL)
            {
                printf("node not found!!!\n");
            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp->prev==NULL&&temp->next==NULL)
        {
            head=NULL;
            free(temp);
        }
        else if(temp->prev==NULL&&temp->next!=NULL)
        {
            head=temp->next;
            head->prev=NULL;
            free(temp);
        }
        else if(temp->next==NULL&&temp->prev!=NULL)
        {
            temp->prev->next=NULL;
            free(temp);
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
     printf("node deleted in the list!!!\n");
    }
}
void display()
{
    struct Node*temp=head;
        if(temp==NULL)
        {
            printf("Empty list nothing to print!!!\n");
        }
        else
        {
        printf("List...\n");
        printf("NULL--->");
        while(temp->next!=NULL)
        {
            printf("%d<--->",temp->data);
            temp=temp->next;
        }
    printf("%d--->NULL\n",temp->data);
        }
}
