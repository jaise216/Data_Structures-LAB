#include<stdio.h>
#include<stdlib.h>
void main()
{
    int s1, s2, i, ch, r;
    printf("enter the size of first set:");
    scanf("%d",&s1);
    printf("enter the size of second set:");
    scanf("%d",&s2);
    int a1[s1], a2[s2];
    printf("denote presence and absence of elements using 0s and 1s of 1st set:\n");
    for(i=0;i<s1;i++)
    {
        scanf("%d", &a1[i]);
    }
    printf("denote presence and absence of elements using 0s and 1s of 2nd set:\n");
    for(i=0;i<s2;i++)
    {
        scanf("%d", &a2[i]);
    }
    do
    {
    printf("enter your choice:\n 1.UNION\n 2.INTERSECTION\n 3.DIFFERENCE\n 4.EQUALITY\n");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        if(s1!=s2)
        {
            printf("set operations cannot be done!!!");
            exit(0);
        }
        else
        {
            int a3[s1];
            for(i=0;i<s1;i++)
            {
                a3[i] = a1[i] || a2 [i];
            }
            printf("the resultant set after UNION operation:\n");
            for(i=0;i<s1;i++)
            {
                printf("%d", a3[i]);
            }
        printf("\n");
        }
        break;
    case 2:
        if(s1!=s2)
        {
            printf("set operations cannot be done!!!");
            exit(0);
        }
        else
        {
            int a3[s1];
            for(i=0;i<s1;i++)
            {
                a3[i] = a1[i] && a2 [i];
            }
            printf("the resultant set after INTERSECTION operation:\n");
            for(i=0;i<s1;i++)
            {
                printf("%d", a3[i]);
            }
        printf("\n");
        }
        break;
    case 3:
        if(s1!=s2)
        {
            printf("set operations cannot be done!!!");
            exit(0);
        }
        else
        {
            int a3[s1];
            for(i=0;i<s1;i++)
            {
                a3[i] = a1[i] && !(a2[i]);
            }
            printf("the resultant set after DIFFERENCE operation:\n");
            for(i=0;i<s1;i++)
            {
                printf("%d", a3[i]);
            }
        printf("\n");
        }
        break;
    case 4:
        if(s1!=s2)
        {
            printf("set operations cannot be done!!!");
            exit(0);
        }
        else
        {
            for(i=0;i<s1;i++)
            {
                if(a1[i] != a2[i])
                {
                    printf("the sets are not equal");
                    break;
                }
            }
        printf("\n");
        }
        break;
    default:
        printf("enter correct choice!!!\n");
    }
    printf("do you wish to continue?\n press 1 if yes\n press 0 if no\n");
    scanf("%d", &r);
    }
    while(r==1);
}
