#include<stdio.h>
#include<stdlib.h>
#define max 5
int front=-1,rear=-1;
int queue[max];
void enqueue(int);
void dequeue();
void display();
void main()
{
    int choice,ele,r;
    do
    {
    printf("enter your choice\n 1.enqueue\n 2.dequeue\n 3.display\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("enter the element to be inserted:");
        scanf("%d",&ele);
        enqueue(ele);
        display();
        break;
    case 2:
        dequeue();
        display();
        break;
    case 3:
        display();
        break;
    default:
        printf("enter correct choice!!!\n");
    }
    printf("\ndo you wish to continue\npress 1 if yes\npress 0 if no\n");
    scanf("%d",&r);
    }
    while(r==1);
}
void enqueue(int ele)
{
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=ele;
    }
    else if((rear+1)%max==front)
    {
        printf("overflow");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=ele;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("underflow");
    }
    else if(front==rear)
    {
        printf("%d is dequeued!!!\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("%d is dequeued!!!\n",queue[front]);
        front=(front+1)%max;
    }
}
void display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("queue is empty!!!\n");
    }
    else
    {
        printf("the elements in the queue are:");
        for(i=front;i<=rear;i=((i+1)%max))
        {
            printf("\n%d",queue[i]);
        }
    }
}
