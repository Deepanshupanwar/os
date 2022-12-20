#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include <stdlib.h>
struct process{
  int pid;
  int at;
  int bt;
  int ct,wt,tat,rt,start_time;
  int bt_remaining;
};
int findmax(int a, int b)
{
    return a>b?a:b;
}
int comparator(const void *p, const void *q) 
{
    int l = ((struct process *)p)->at;
    int r = ((struct process *)q)->at; 
    return (l - r);
}
int comparatorPID(const void * a, const void *b)
{
  int l = ((struct process *)a)->pid;
  int r = ((struct process *)b)->pid; 
  return (l - r); 
}
int main()
{
    int n,index;
    int cpu_utilization;
    bool visited[100]={false},is_first_process=true;
    int current_time = 0,max_completion_time;
    int completed = 0,total_idle_time=0,length_cycle;
    scanf("%d",&n);
    struct process arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&arr[i].at,&arr[i].bt);
        arr[i].pid=i;
        arr[i].bt_remaining=arr[i].bt;
    }
    int tq=3;
    qsort((void*)arr, n, sizeof(struct process), comparator);
    int queue[100],front=-1,rear=-1;
    float sum_tat=0,sum_wt=0,sum_rt=0;
    front=rear=0;
    queue[rear]=0;    
    visited[0] = true;
    while(completed != n) 
    {
      index = queue[front];      
      front++;
      if(arr[index].bt_remaining == arr[index].bt)
      {
            arr[index].start_time = findmax(current_time,arr[index].at);
            total_idle_time += (is_first_process == true) ? 0 : arr[index].start_time - current_time;
            current_time =  arr[index].start_time;
            is_first_process = false;
             
      }
      if(arr[index].bt_remaining-tq > 0)
      {    
            arr[index].bt_remaining -= tq;
            current_time += tq;
      }
      else 
      {
            current_time += arr[index].bt_remaining;
            arr[index].bt_remaining = 0;
            completed++;

            arr[index].ct = current_time;
            arr[index].tat = arr[index].ct - arr[index].at;
            arr[index].wt = arr[index].tat - arr[index].bt;
            arr[index].rt = arr[index].start_time - arr[index].at;

            sum_tat += arr[index].tat;
            sum_wt += arr[index].wt;
            sum_rt += arr[index].rt;
      }
      for(int i = 1; i < n; i++) 
      {
          if(arr[i].bt_remaining > 0 && arr[i].at <= current_time && visited[i] == false) 
          {
            queue[++rear]=i;
            visited[i] = true;
          }
      }
      if( arr[index].bt_remaining> 0) 
          queue[++rear]=index;

      if(front>rear)
      {
          for(int i = 1; i < n; i++)
          {
            if(arr[i].bt_remaining > 0)
            {
              queue[rear++]=i;
              visited[i] = true;
              break;
            }
          }
      }
   }
    max_completion_time = INT_MIN;
  
  for(int i=0;i<n;i++)
        max_completion_time = findmax(max_completion_time,arr[i].ct);
      
  length_cycle = max_completion_time - arr[0].at;  
  cpu_utilization = (float)(length_cycle - total_idle_time)/ length_cycle;
  qsort((void *)arr,n, sizeof(struct process),comparatorPID);

  printf("\nProcess No.\tAT\tCPU Burst Time\tStart Time\tCT\tTAT\tWT\tRT\n");
  for(int i=0;i<n;i++)
    printf("%d\t\t%d\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",i,arr[i].at,arr[i].bt,arr[i].start_time,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
  printf("\n");    

  printf("\nAverage Turn Around time= %.2f",(float)sum_tat/n);
  printf("\nAverage Waiting Time= %.2f",(float)sum_wt/n);
  printf("\nAverage Response Time= %.2f",(float)sum_rt/n);    
  printf("\nThroughput= %.2f",n/(float)length_cycle);
  printf("\nCPU Utilization(Percentage)= %.2f",cpu_utilization*100);
  return 0;
}