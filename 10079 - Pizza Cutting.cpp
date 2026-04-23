#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans;

main()
{
    while(cin>>n&&n>=0)
    {
        ans=n*(n+1)/2+1;
        cout<<ans<<endl;
    }
    return 0;
}
