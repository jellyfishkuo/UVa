#include <bits/stdc++.h>
using namespace std;

int m,n;

int main()
{
    cin>>m;
    while(m--)
    {
        cin>>n;
        int ans[1001],cnt=0,sum=0;
        for(int i=2;sum+i<=n;i++)
        {
            sum+=i;
            ans[cnt++]=i;
        }
        int left=n-sum;
        for(int i=cnt-1;left>0;i--,left--)
        {
            if(i<0) i=cnt-1;
            ans[i]++;
        }
        cout<<ans[0];
        for(int i=1;i<cnt;i++) cout<<" "<<ans[i];
        cout<<endl;
        if(m) cout<<endl;
    }
    return 0;
}
