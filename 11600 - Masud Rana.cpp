#include <bits/stdc++.h>
using namespace std;

const int N=35;
vector<int> G[N];
map<int,double> dp[N];
int cnt[N];
int p,n;
bool visited[N];

double DP(int u,int S)
{
    int have=0;
    if(dp[u].count(S)) return dp[u][S];
    for(int i=0;i<n;i++)
        if(S&(1<<i))
            have+=cnt[i];
    if(have==n) return 0;
    dp[u][S]=(n-1)*1.0/(n-have);
    for(int i=0;i<p;i++)
    {
        if(S&(1<<i)) continue;
        dp[u][S]+=DP(i,S|(1<<i))*cnt[i]/(n-have);
    }
    return dp[u][S];
}

int dfs(int u)
{
    visited[u]=true;
    int ret=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(visited[v]) continue;
        ret+=dfs(v);
    }
    return ret;
}

int main()
{
    int T,m,cas=0;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++) G[i].clear();
        int a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        p=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                dp[p].clear();
                cnt[p++]=dfs(i);
            }
        }
        cout<<"Case "<<++cas<<fixed<<setprecision(6)<<": "<<DP(0,1)<<endl;
    }
    return 0;
}
