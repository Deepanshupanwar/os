#include<stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("enter the of requests\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the request sequence\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int initial_head;
    printf("enter initial head\n");
    scanf("%d",&initial_head);
    int total_seek=0;
    printf("seek sequence is:\n");
    for(int i=0;i<n;i++)
    {
        total_seek+=fabs(initial_head-arr[i]);
        printf("%d\n",arr[i]);
        initial_head=arr[i];
    }
    printf("total number of seek %d",total_seek);
}
