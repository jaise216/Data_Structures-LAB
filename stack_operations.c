#include<stdio.h>
#include<stdlib.h>
struct Node
    {
        int data;
        struct Node *next;
    }*top=NULL;
void pushEle(int);
void popEle();
int searchEle(int);
void display();
void main()
{
    int ch,ele,r,n;
    do
    {
    printf("enter your choice:\n 1.push \n 2.pop \n 3.search\n 4.display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("enter the element to be pushed:");
                scanf("%d",&ele);
                pushEle(ele);display();break;
        case 2: popEle();display();break;
        case 3: printf("enter the element to be searched:");
                scanf("%d",&ele);
                n=searchEle(ele);
                if(n==1)
                    printf("element found\n");
                else
                    printf("element not found\n");
                display();break;
        case 4: display();break;
        default:printf("enter correct choice\n");
        }
        printf("do you wish to continue:\n press 0 if yes \n press 1 if no:\n");
        scanf("%d",&r);
    }
        while(r==0);
}
    void pushEle(int ele)
    {
        struct Node*newNode;
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=ele;
        if(top==NULL)
        {
            newNode->next=NULL;
            top=newNode;
        }
        else
        {
            newNode->next=top;
            top=newNode;
        }
    }
    void popEle()
    {
        if(top==NULL)
        {
            printf("underflow\n");
        }
        else
        {
            struct Node*temp=top;
            top=temp->next;
            free(temp);
            printf("element at top of the stack is removed\n");
        }
    }
    int searchEle(int ele)
  {
      struct Node*temp=top;
      while(temp!=NULL)
      {
          if(temp->data==ele)
          {
              return 1;
          }
          temp=temp->next;
      }
      return 0;
  }
    void display()
    {
        struct Node*temp=top;
        if(top==NULL)
        {
            printf("List is empty!!!\n");
        }
        else
        {
        printf("Stack...\n");
        while(temp->next!=NULL)
        {
            printf("%d--->",temp->data);
            temp=temp->next;
        }
    printf("%d--->NULL\n",temp->data);
        }
    }
