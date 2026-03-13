#include <bits/stdc++.h>
using namespace std;

int read()
{
    int q=0;
    char ch=' ';
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        q=q*10+ch-'0';
        ch=getchar();
    }
    return q;
}

const int N=1e6+5;
int T,n,m;
int f[N],a[N],ans[N],lake[N];

int find(int x)
{
    if(f[x]==x) return x;
    f[x]=find(f[x]);
    return f[x];
}

int work()
{
    int x;
    for(int i=1;i<=n;i++) lake[i]=0;
    for(int i=1;i<=m;i++)
    {
        if(!a[i]) continue;
        x=find(lake[a[i]]);
        if(x<=i)
        {
            ans[x]=a[i];
            f[x]=find(x+1);
        }
        else return 0;
        lake[a[i]]=i;
    }
    puts("YES");
    for(int i=1;i<=m;i++)
        if(!a[i]) cout<<ans[i]<<" ";
    cout<<endl;
    return 1;
}

int main()
{
    int las;
    T=read();
    while(T--)
    {
        n=read();
        m=read();
        for(int i=1;i<=m;i++)
        {
            ans[i]=0;
            a[i]=read();
        }
        las=m+1;
        f[m+1]=m+1;
        for(int i=m;i>=0;i--)
        {
            if(!a[i]&&i!=0) las=i;
            f[i]=las;
        }
        if(!work()) cout<<"NO\n";
    }
    return 0;
}
