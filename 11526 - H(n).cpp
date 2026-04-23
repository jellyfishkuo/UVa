#include <bits/stdc++.h>
#define int long long
using namespace std;

int H(int n)
{
    if (n<=0) return 0;
    int res=0,left=1,right;
    while(left<=n)
    {
        int val=n/left;
        right=n/val;
        if(right>n) right=n;
        res+=(right-left+1)*val;
        left=right+1;
        if(val==0) break;
    }
    return res;
}

int t,n;

main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<H(n)<<endl;
    }
    return 0;
}
