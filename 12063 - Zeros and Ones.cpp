#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
int dp[65][35][105];

int solve(int pos,int ones,int rem) {
    if(pos==n)
        return (ones==n/2&&rem==0)?1:0;
    if(dp[pos][ones][rem]!=-1)
        return dp[pos][ones][rem];
    int cnt=0;
    if((pos-ones)<n/2)
        cnt+=solve(pos+1,ones,(rem*2+0)%k);
    if(ones<n/2)
        cnt+=solve(pos+1,ones+1,(rem*2+1)%k);
    return dp[pos][ones][rem]=cnt;
}

main()
{
    int cas;
    cin>>cas;
    for(int t=1;t<=cas;t++)
    {
        cin>>n>>k;
        int ans=0;
        if(n%2==0&&k>0)
        {
            memset(dp,-1,sizeof(dp));
            ans=solve(1,1,1%k);
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
