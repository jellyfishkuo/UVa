#include <bits/stdc++.h>
using namespace std;

int s[1440];
int n,t,m,c;

int main()
{
    cin>>c;
    while(c--)
    {
        cin>>n>>t>>m;
        t*=2;
        int tot=0,act=0;
        for(int i=0;i<m;i++) cin>>s[i];
        for(int i=(m+n-1)%n;i<m;i+=n)
            act=tot>s[i]?tot:s[i],tot=act+t;
        cout<<tot-t/2<<" "<<(m+n-1)/n<<endl;
    }
    return 0;
}
