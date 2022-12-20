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
};
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
    int burst_remaining[n];
    int is_completed[n];
    memset(is_completed,0,sizeof(is_completed));
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        cout<<"Enter priority of the process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
        cout<<endl;
    }
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while(completed!=n)
    {
        int idx=-1;
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i].arrival_time<=current_time&&is_completed[i]==0)
            {
                if(arr[i].priority>mx)
                {
                    idx=i;
                    mx=arr[i].priority;
                }
                if(arr[i].priority==mx)
                {
                    if(arr[i].arrival_time<arr[idx].arrival_time)
                    {
                        idx=i;
                        mx=arr[i].priority;
                    }
                }
            }
        }
        if(idx!=-1)
        {
            if(burst_remaining[idx]==arr[idx].burst_time)
            {
                arr[idx].start_time==current_time;
                total_idle_time +=current_time-prev;
            }
            burst_remaining[idx]-=1;
            current_time++;
            prev=current_time;
            if(burst_remaining[idx]==0)
            {
                is_completed[idx]=1;
                arr[idx].completion_time=current_time;
                arr[idx].turnaround_time=arr[idx].completion_time-arr[idx].start_time;
                arr[idx].response_time=arr[idx].start_time-arr[idx].arrival_time;
                arr[idx].waiting_time=arr[idx].turnaround_time-arr[idx].burst_time;
        
                total_response_time+=arr[idx].response_time;
                total_turnaround_time+=arr[idx].turnaround_time;
                total_waiting_time+=arr[idx].waiting_time;

                completed++;

            }
        }
        else
        {
            current_time++;
        }
    }
    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,arr[i].arrival_time);
        max_completion_time = max(max_completion_time,arr[i].completion_time);
    }
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((max_completion_time - total_idle_time) / (float) max_completion_time )*100;
    throughput = float(n) / (max_completion_time - min_arrival_time);

    cout<<endl<<endl;

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<arr[i].pid<<"\t"<<arr[i].arrival_time<<"\t"<<arr[i].burst_time<<"\t"<<arr[i].priority<<"\t"<<arr[i].start_time<<"\t"<<arr[i].completion_time<<"\t"<<arr[i].turnaround_time<<"\t"<<arr[i].waiting_time<<"\t"<<arr[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;
    return 0;
}