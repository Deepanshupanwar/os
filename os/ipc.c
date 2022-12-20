#include<stdio.h>
#include<unistd.h>
int main()
{
    int p[2];//0 read  1 write
    int returnstatus=0;
    char writemsg[2][25]={"operate","system"};
    char readmsg[25]; 
    returnstatus=pipe(p);
    if(returnstatus==-1)
    {
        printf("pipe is not created\n");
    }
    else
    {
        printf("writing to pipe - msg %s\n",writemsg[0]);
        write(p[1],writemsg[0],sizeof(writemsg[0]));
        printf("%d %d\n",p[0],p[1]);
        read(p[0],readmsg,sizeof(readmsg));
        printf("reading from pipe - msg %s\n",readmsg);
    }
    return 0;
}