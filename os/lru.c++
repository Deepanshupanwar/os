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
    unordered_map<int,int> m;
    int page_fault=0;
    for(int i=0;i<n;i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(arr[i])==s.end())
            {
                s.insert(arr[i]);
                page_fault++;
            }
            m[arr[i]]=i;
        }
        else
        {
            if(s.find(arr[i])==s.end())
            {
                int lru=INT_MIN,page;
                for(auto it=s.begin();it!=s.end();it++)
                {
                    if(m[*it]<lru)
                    {
                        lru=m[*it];
                        page=*it;
                    }
                }
                s.erase(page);
                s.insert(arr[i]);
                page_fault++;
            }
            m[arr[i]]=i;
        }
    }
    cout<<"page fault:"<<page_fault<<endl;
    return 0;
}
