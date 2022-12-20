#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int head;
    cin>>head;
    vector<int> left,right;
    int seek=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>head)
          right.push_back(arr[i]);
        if(arr[i]<head)
          left.push_back(arr[i]);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    cout<<"sequence is:"<<endl;
    for(int i=0;i<right.size();i++)
    {
        seek+=abs(head-right[i]);
        cout<<right[i];
        head=right[i];
    }
    seek+=abs(head-left[0]);
    head=left[0];
    for(int i=0;i<left.size();i++)
    {
        seek+=abs(head-left[i]);
        cout<<left[i];
        head=left[i];
    }
    cout<<"seek:"<<seek<<endl;
}
