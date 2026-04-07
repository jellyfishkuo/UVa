#include <bits/stdc++.h>

using namespace std;

int n,maxd,cp[20];

bool dfs(int cur)
{
    if(cur==maxd) return (cp[cur]==n);
    int curmax=cp[cur];
    if((curmax<<(maxd-cur))<n) return false;
    for(int i=cur;i>=0;i--)
    {
        int next=cp[cur]+cp[i];
        if(next<=10000)
        {
            cp[cur+1]=next;
            if(dfs(cur+1)) return true;
        }
        next=cp[cur]-cp[i];
        if(next>0)
        {
            cp[cur+1]=next;
            if(dfs(cur+1)) return true;
        }
    }
    return false;
}

int main()
{
    while(cin>>n,n)
    {
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        cp[0]=1;
        maxd=1;
        while(true)
        {
            if(dfs(0))
            {
                cout<<maxd<<endl;
                break;
            }
            maxd++;
        }
    }
    return 0;
}
