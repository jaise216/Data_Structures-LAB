#include<stdio.h>
#define max 4
int s[max];
int un(int,int);
int find(int);
void main()
{
    int n=4, i, r, a, b;
    printf("{ {1},{2},{3},{4} }\n");
    int s[n];
    for(i=1;i<=n;i++)
    {
        s[i]=0;
    }
    do
    {
    printf("enter the singleton set to perform the union operations on:\n");
    scanf("%d%d", &a, &b);
    un(a,b);
    printf("do you wish to continue? \n 1.press 1 if yes\n 2.press if no\n");
    scanf("%d", &r);
    }while(r==1);
}
un(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
    {
        printf("the sets are equal\n");
    }
    else
    {
        s[b]=a;
    }
}
find(int a)
{
    if(s[a]==0)
        return a;
    else
    {
        find(s[a]);
    }
}
