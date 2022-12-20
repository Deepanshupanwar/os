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
    int capacity;
    cin>>capacity;
    unordered_set<int> s;
    queue<int> q;
    int page_fault=0;
    for(int i=0;i<n;i++)
    {
        if(q.size()<capacity)
        {
            if(s.find(arr[i])==s.end())
            {
                page_fault++;
                s.insert(arr[i]);
                q.push(arr[i]);
            }
        }
        else
        {
            if(s.find(arr[i])==s.end())
            {
                page_fault++;
                int page=q.front();
                s.insert(arr[i]);
                s.erase(page);
                q.pop();
                q.push(arr[i]);
            }
        }
    }
    cout<<"page fault:"<<page_fault<<endl;
}