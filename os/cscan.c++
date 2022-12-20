#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int max_disk_size=200;
    cout<<"enter the of requests"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the request sequence"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int initial_head;
    cout<<"enter initial head"<<endl;
    cin>>initial_head;
    int total_seek=0;
    vector<int> right;
    vector<int> left;
    left.push_back(0);
    right.push_back(max_disk_size-1);
    for(int i=0;i<n;i++)
    {
        if(arr[i]<initial_head)
        {
            left.push_back(arr[i]);
        }
        if(arr[i]>initial_head)
        {
            right.push_back(arr[i]);
        }
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    cout<<"seek sequence is:"<<endl;
    for(int i=0;i<right.size();i++)
    {
        total_seek+=fabs(right[i]-initial_head);
        initial_head=right[i];
        cout<<right[i]<<endl;
    }
    total_seek+=max_disk_size-1;
    initial_head=0;
    for(int i=0;i<left.size();i++)
    {
        total_seek+=fabs(left[i]-initial_head);
        initial_head=left[i];
        cout<<left[i]<<endl;
    }
    cout<<"Total number of seek operations: "<<total_seek<<endl;
    return 0;
}