#include<bits/stdc++.h>
using namespace std;
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int burst_remaining;
};
bool comp1(struct process a,struct process b)
{
    return a.arrival_time < b.arrival_time;
}
bool compare2(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}
int main()
{
    int n;
    cout<<"enter the number of process"<<endl;
    cin>>n;
    struct process arr[n];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int tq;
    cout<<"Enter time quantum: ";
    cin>>tq;
    memset(is_completed,0,sizeof(is_completed));
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>arr[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>arr[i].burst_time;
        cout<<"Enter priority of the process "<<i+1<<": ";
        cin>>arr[i].priority;
        arr[i].pid = i+1;
        arr[i].burst_remaining = arr[i].burst_time;
        cout<<endl;
    }
    sort(arr,arr+n,comp1);
    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark,0,sizeof(mark));
    mark[0] = 1;
    int idx;
    while(completed!=n)
    {
        idx=q.front();
        q.pop();
        if(arr[idx].burst_remaining==arr[idx].brust_time)
        {
            arr[idx].start_time=max(current_time,arr[idx].arrival_time);
            current_time=arr[idx].start_time;
            total_idle_time+=arr[idx].start_time-current_time;
        }
        if(arr[idx].burst_remaining-tq > 0) {
            arr[idx].burst_remaining -= tq;
            current_time += tq;
        }
        else
        {
            current_time+=arr[idx].burst_remaining;
            arr[idx].burst_remaining=0;
            completed++;

            arr[idx].completion_time=current_time;
            arr[idx].turnaround_time=arr[idx].completion_time-arr[idx].arrival_time;
            arr[idx].response_time=arr[idx].start_time-arr[idx].arrival_time;
            arr[idx].waiting_time=arr[idx].turnaround_time-arr[idx].burst_time;

            total_turnaround_time+=arr[idx].turnaround_time;
            total_response_time+=arr[idx].response_time;
            total_waiting_time+=arr[idx].waiting_time;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i].burst_remaining==0&&arr[i].arrival_time<=current_time&& mark[i]==0)
            {
                q.push(i);
                mark[i]=1;
            }
        }
        if(arr[idx].burst_remaining>0)
        {
            q.push(idx);
        }
        if(q.empty())
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i].burst_remaining>0)
                {
                    q.push(i);
                    mark[i]=1;
                    break;
                }
            }
        }
    }
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((arr[n-1].completion_time - total_idle_time) / (float) arr[n-1].completion_time)*100;
    throughput = float(n) / (arr[n-1].completion_time - arr[0].arrival_time);

    sort(p,p+n,compare2);

    cout<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<arr[i].pid<<"\t"<<arr[i].arrival_time<<"\t"<<arr[i].burst_time<<"\t"<<arr[i].start_time<<"\t"<<arr[i].completion_time<<"\t"<<arr[i].turnaround_time<<"\t"<<arr[i].waiting_time<<"\t"<<arr[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;

}