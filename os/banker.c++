#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;//processes
    int m=3;//resources
    int alloc[5][3] = { { 0, 1, 0 }, // Allocation Matrix
                     { 2, 0, 0 }, 
                     { 3, 0, 2 }, 
                     { 2, 1, 1 }, 
                     { 0, 0, 2 } }; 
 
    int max[5][3] = { { 7, 5, 3 }, // MAX Matrix
                   { 3, 2, 2 },
                   { 9, 0, 2 },
                   { 2, 2, 2 },
                   { 4, 3, 3 } };
    int avail[]={3,3,3};
    int flag[n];
    int ans[n];
    for(int i=0;i<n;i++)
    {
        flag[i]=0;
    }
    int need[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int ind=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(flag[j]==0)
            {
                int check=0;
                for(int k=0;k<m;k++)
                {
                    if(need[j][k]>avail[k])
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0)
                {
                    ans[ind++]=j;
                    for(int k=0;k<m;k++)
                    {
                        avail[k]+=need[j][k];   
                    }
                    flag[j]=1;
                }
            }
        }
    }
    int check=0;
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            check=1;
            break;
        }
    }
    if(check==0)
    {
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
}