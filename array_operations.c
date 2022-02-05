#include<stdio.h>
void main()
{
    int i,j=0,n,m,pos,ele,temp;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array:\n");
    for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    printf("the array elements are:\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
    printf("enter your choice:\n1.insertion\n2.deletion\n3.search element\n4.sort\n");
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        printf("enter the element to be inserted and its position:\n");
        scanf("%d%d",&ele,&pos);
        pos--;
        for(i=n;i>=pos;i--)
        {
            if(i==pos)
            {
                a[i]=ele;
                break;
            }
            a[i]=a[i-1];
        }
        printf("array after insertion is:\n");
        for(i=0;i<=n;i++)
        {
            printf("%d\n",a[i]);
        }
    break;
    case 2:
        printf("enter the element to be deleted: ");
        scanf("%d",&ele);
        for(i=0;i<n;i++)
        {
            if(a[i]==ele)
            {
                pos=i;
                n--;
                i--;
                for(j=pos;j<n;j++)
                {
                    a[j]=a[j+1];
                }
            }
        }
        if(j==0)
            printf("element not found");
        else
            {
                printf("array after deletion is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d\n",a[i]);
                }
            }
    break;
    case 3:
        printf("enter the element to be searched: ");
        scanf("%d",&ele);
        for(i=0;i<n;i++)
            {
                if(a[i]==ele)
                {
                    printf("element found at %d\n",i+1);
                    j=1;
                }
            }
        if(j==0)
            printf("element not found");
    break;
    case 4:
         printf("the sorted array is:\n");
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
                {
                    if(a[j]>a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
        }
        for(i=0;i<n;i++)
        {
             printf("%d\n",a[i]);
        }
    break;
    default: printf("enter correct choice");
    }
}
