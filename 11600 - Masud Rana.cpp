#include <bits/stdc++.h>
using namespace std;

const int N=35;
vector<int> G[N];        // 鄰接表，儲存初始的連通情況
map<int,double> dp[N];   // 記憶化搜索的 Map，dp[u][S] 表示目前在第 u 個分量，狀態為 S 時的期望值
int cnt[N];              // 儲存每個連通分量（Connected Component）中的節點數量
int p, n;                // p 是連通分量的個數，n 是總城市數
bool visited[N];         // DFS 使用，標記節點是否訪問過

double DP(int u, int S)
{
    int have=0;
    if(dp[u].count(S)) return dp[u][S]; // 記憶化搜索，若算過就直接回傳
    
    for(int i=0;i<p;i++)                // 計算目前狀態 S 中已經包含的所有城市總數
        if(S&(1<<i))
            have+=cnt[i];

    if(have==n) return 0;               // 如果所有城市都連通了，不需要額外天數，期望值為 0

    // 核心轉移公式推導：
    // 設 E 為當前期望值。
    // 抽到「已經在狀態內」的點的機率是 (have-1)/(n-1)，這會導致自環（天數 +1 但狀態不變）。
    // 抽到「不在狀態內」的點的機率是 cnt[i]/(n-1)。
    // 經化簡後，E = (n-1)/(n-have) + Σ [ DP(下個狀態) * cnt[i]/(n-have) ]
    
    dp[u][S]=(n-1)*1.0/(n-have);        // 基礎期望值（考慮了抽到重複點的情況）

    for(int i=0;i<p;i++)                // 嘗試連接到尚未包含的連通分量 i
    {
        if(S&(1<<i)) continue;          // 如果 i 已經在目前的連通塊中，跳過
        dp[u][S]+=DP(i,S|(1<<i))*cnt[i]/(n-have); // 累加轉移期望值
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
    return ret; // 回傳該連通分量中共有多少個點
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
            G[a].push_back(b); // 建立初始雙向邊
            G[b].push_back(a);
        }
        
        p=0; // 重置連通分量計數
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                dp[p].clear();        // 清除該分量的 DP 紀錄
                cnt[p++]=dfs(i);      // 算出第 p 個分量的大小，p 增加
            }
        }
        // 從第 0 個分量開始，初始狀態為 1 (即二進位 000...001，代表包含第 0 個分量)
        cout<<"Case "<<++cas<<fixed<<setprecision(6)<<": "<<DP(0,1)<<endl;
    }
    return 0;
}
