#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int sum=0 , n,head;
    printf("ashutosh rawat section B 19\n");
    printf("enter head : ");
    scanf("%d",&head);
    printf("enter number of disk :");
    scanf("%d",&n);
    printf("enter the disk sequene :");
    int a[n];
    for(int i=0;i<n;i++)
    {   
         scanf("%d",&a[i]);
         
    }
     for(int i=0;i<n;i++)
    {   
        if(i<n-1)
            printf("( %d - %d ) + ", head , a[i]);
        else
            printf("( %d - %d ) ", head , a[i]);

         sum += fabs(head - a[i]);
         head = a[i];
    }

    printf("\ntotal seek is :%d ",sum);

    
}