#include<stdio.h>
void main()
{
    int s1,s2,s3,i,k,temp;
    printf("enter the size of first array:");
    scanf("%d",&s1);
    printf("enter the size of second array:");
    scanf("%d",&s2);
    s3=s1+s2;
    int a1[s1];int a2[s2];int a3[s3];
    printf("enter the elements of first array:\n");
    for(i=0;i<s1;i++)
    {
        scanf("%d",&a1[i]);
        a3[i]=a1[i];
    }
    printf("enter elements of second array:\n");
    k=s1;
    for(i=0;i<s2;i++)
    {
        scanf("%d",&a2[i]);
        a3[k]=a2[i];
        k++;
    }
    printf("first array:\n");
    for(i=0;i<s1;i++)
    {
        printf("%d ",a1[i]);
    }
    printf("\n");
    printf("second array:\n");
    for(i=0;i<s2;i++)
    {
        printf("%d ",a2[i]);
    }
    printf("\n");
    printf("array after merging is:\n");
    for(i=0;i<s3;i++)
    {
        printf("%d ",a3[i]);
    }
    for(i=0;i<s3;i++)
    {
        for(k=i+1;k<s3;k++)
        {
            if(a3[k]<a3[i])
            {
                temp=a3[k];
                a3[k]=a3[i];
                a3[i]=temp;
            }
        }
    }
    printf("\n");
    printf("the array after sorting is:\n");
    for(i=0;i<s3;i++)
    {
        printf("%d ",a3[i]);
    }
}
