#include<stdio.h>
#include<stdlib.h>
struct Node
    {
        int data;
        struct Node *next;
    }*head=NULL;
void insertAtBeg(int);
void insertAtEnd(int);
void insertInBw(int,int);
void deleteAtBeg();
void deleteAtEnd();
void deleteInBw(int);
void display();
int search(int);
void main()
{
    int ch,c,value,key,r,s;
do
{
    printf("enter your choice:\n 1.insertion \n 2.deletion \n 3.display \n 4.searching \n");
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
        printf("first node deleted!!!\n");
        display();
    }
    else if(c==2)
    {
        deleteAtEnd();
        printf("last node deleted!!!\n");
        display();
    }
    else if(c==3)
    {
        printf("enter the value to be deleted:\n");
        scanf("%d",&value);
        deleteInBw(value);
        printf("node deleted in the list!!!\n");
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
case 4:
    printf("enter the value to be searched:\n");
    scanf("%d",&value);
    s=search(value);
    if(s==1)
        printf("element found!!!\n");
    else
        printf("element not found!!!\n");
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
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct Node*temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newNode->next=head;
        head=newNode;
        temp->next=head;
    }
}
void insertAtEnd(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct Node*temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }
}
void insertInBw(int value,int key)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct Node*temp=head;
        while(temp->data!=key)
        {
            if(temp->next==head)
                printf("node not found!!!");
            else
                temp=temp->next;
        }
        if(temp->next==head)
        {
            temp->next=newNode;
            newNode->next=head;
        }
        else
        {
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}
void deleteAtBeg()
{
    if(head==NULL)
    {
        printf("the list is empty!!!");
    }
    else
    {
        struct Node*temp=head,*prev=head;
        if(temp->next==head)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=head)
                temp=temp->next;
            head=prev->next;
            temp->next=head;
            free(prev);
        }
    }
}
void deleteAtEnd()
{
    if(head==NULL)
    {
        printf("the list is empty!!!");
    }
    else
    {
        struct Node*temp=head,*prev;
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
    }
}
void deleteInBw(int value)
{
    if(head==NULL)
    {
        printf("the list is empty");
    }
    struct Node*temp=head,*prev=NULL;
    while(temp->data!=value)
    {
        if(temp->next==head)
            printf("element not found");
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    if((temp->next==head)&&(prev==NULL))
        head=NULL;
    else if(temp==head)
    {
        prev=head;
        while(prev->next!=head)
            prev=prev->next;
        head=head->next;
        prev->next=head;
    }
    else if(temp->next==head)
        prev->next=head;
    else
        prev->next=temp->next;
    free(temp);
}
void display()
{
    struct Node*temp=head;
        if(temp==NULL)
        {
            printf("List is empty!!!\n");
        }
        else
        {
        printf("List...\n");
        while(temp->next!=head)
        {
            printf("%d--->",temp->data);
            temp=temp->next;
        }
    printf("%d--->NULL\n",temp->data);
        }
}
int search(int value)
{

      struct Node*temp=head;
      while(temp->next!=head)
      {
          if(temp->data==value)
          {
              return 1;
          }
          temp=temp->next;
      }
      if(temp->data==value)
        return 1;
      else
        return 0;
}
