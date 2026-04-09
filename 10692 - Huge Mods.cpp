#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int num[10000];

int phi_of(int m)
{
    int phi=m;
    for(int i=2;i*i<=m;i++)
    {
        if(m%i) continue;
        phi=phi/i*(i-1);
        while(m%i==0) m/=i;
    }
    if(m>1) phi=(phi/m)*(m-1);
    return phi;
}

int powmod(int a,int exp,int m)
{
    int ret=1;
    for(;exp>0;exp>>=1)
    {
        if(exp&1) ret=ret*a%m;
        a=a*a%m;
    }
    return ret;
}

int ans(int d,int m)
{
    if(d==n-1) return num[d]%m;
    int phi=phi_of(m);
    int e=ans(d+1,phi)+phi;
    return powmod(num[d],e,m);
}

main()
{
    string s;
    int cas=1;
    while(cin>>s)
    {
        if(s[0]=='#') break;
        int m=stoi(s);
        cin>>n;
        for(int i=0;i<n;i++) cin>>num[i];
        cout<<"Case #"<<cas++<<": "<<ans(0,m)<<endl;
    }
    return 0;
}

/*
10 4 2 3 4 5
100 2 5 2
53 3 2 3 2
#

*/
