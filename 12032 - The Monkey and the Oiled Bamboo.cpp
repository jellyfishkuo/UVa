#include <bits/stdc++.h>
using namespace std;

int r[100001]={0};
int cas,n;

int main()
{
    while(cin>>cas)
    {
        for(int t=1;t<=cas;t++)
        {
            cin>>n;
            for(int i=1;i<=n;i++) cin>>r[i];
            int k=r[n]-r[n-1];
            for(int i=n-1;i>0;--i)
            {
                if(k<r[i]-r[i-1]) k=r[i]-r[i-1];
                else if(k==r[i]-r[i-1]) k=r[i]-r[i-1]+1;
            }
            cout<<"Case "<<t<<": "<<k<<endl;
        }
    }
    return 0;
}
