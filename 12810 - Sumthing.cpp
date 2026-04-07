#include <bits/stdc++.h>
#define int long long
const int MOD = 1000000009;
using namespace std;

int mpow(int a,int b,int MOD)
{
    int ret=1;
    while(b)
    {
        if(b&1) ret=(ret*a)%MOD;
        b>>=1;
        a=(a*a)%MOD;
    }
    return ret;
}

int cas,n;

main()
{
    int x=mpow(2,MOD-2,MOD);
    cin>>cas;
    while(cas--)
    {
        cin>>n;
        int ans=1,A;
        for(int i=0;i<n;i++)
        {
            cin>>A;
            ans*=(1+2*A);
            ans%=MOD;
        }
        ans=((ans-1)*x)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
