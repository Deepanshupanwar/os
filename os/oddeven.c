/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<unistd.h>
int main()
{
    int arr[8]={1,2,3,4,5,6,7,8};
    int even=0,odd=0;
    int x=fork();
    printf("x=%d\n",x);
    if(x!=0)//parent
    {
        for(int i=0;i<8;i++)
        {
            if(arr[i]%2!=0)
              odd+=arr[i];
        }
        printf("process id %d odd sum %d\n",getpid(),odd);
    }
    else//child
    {
        for(int i=0;i<8;i++)
        {
            if(arr[i]%2==0)
              even+=arr[i];
        }
        printf("process id %d even sum %d",getpid(),even);
    }
}
