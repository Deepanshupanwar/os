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
    string direction="";
    cout<<"enter the direction"<<endl;
    cin>>direction;
    vector<int> right;
    vector<int> left;
    if(direction=="left")
    {
        left.push_back(0);
    }
    else
    {
        right.push_back(max_disk_size-1);
    }
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
    int run=2;
    cout<<"seek sequence is:"<<endl;
    while(run--)
    {
        if(direction=="left")
        {
            for(int i=left.size()-1;i>=0;i--)
            {
                total_seek+=fabs(initial_head-left[i]);
                initial_head=left[i];
                cout<<left[i]<<endl;
            }
            direction="right";
        }
        else
        {
            for(int i=0;i<right.size();i++)
            {
                total_seek+=fabs(initial_head-right[i]);
                initial_head=right[i];
                cout<<right[i]<<endl;
            }
            direction="left";
        }
    }
    cout<<"Total number of seek operations: "<<total_seek<<endl;
    return 0;
}