#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int head;
    cin>>head;
    int seek=0;
    vector <int> vis(n,-1);
    cout<<"sequence"<<endl;
    for(int i=0;i<n;i++)
    {
        int close=INT_MAX;
        int request;
        int index;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==-1&&abs(head-arr[j])<close)
            {
                close=abs(head-arr[j]);
                request=arr[j];
                index=j;
            }
        }
        seek+=close;
        cout<<request<<endl;
        vis[index]=1;
        head=request;
    }
    cout<<"total seek"<<seek<<endl;
}