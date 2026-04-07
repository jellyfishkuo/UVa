#include <bits/stdc++.h>
#define MAXD 1005
using namespace std;

int l,r,lhs[MAXD],rhs[MAXD],lh,rh,lhi,rhi;

int solve()
{
    if(lh==rh)
    {
        int lt=0,rt=0;
        for(int i=l,h=lhs[l];i>lhi;i--)
        {
            lt+=h;
            h=max(h,lhs[i-1]);
        }
        for(int i=r,h=rhs[r];i>rhi;i--)
        {
            rt+=h;
            h=max(h,rhs[i-1]);
        }
        return (lhi+rhi+1)*lh*2+min(lt,rt)*2*2;
    }
    int T=min(lh,rh);
    int lti=0,rti=0;
    while(lti<l&&lhs[lti]<T) lti++;
    while(rti<r&&rhs[rti]<T) rti++;
    int lt=0,rt=0,t;
    if(lh<rh)
    {
        for(int i=l,h=lhs[l];i>lhi;i--)
        {
            lt+=h;
            h=max(lhs[i-1],h);
        }
        for(int i=rti,h=T;rhs[i]<=T;i++)
        {
            rt+=h;
            h=max(rhs[i+1],h);
        }
        t=lt>rt?(lt+rt):2*lt;
    }
    if(lh>rh)
    {
        for(int i=r,h=rhs[r];i>rhi;i--)
        {
            rt+=h;
            h=max(rhs[i-1],h);
        }
        for(int i=lti,h=T;lhs[i]<=T;i++)
        {
            lt+=h;
            h=max(h,lhs[i+1]);
        }
        t=rt>lt?(lt+rt):2*rt;
    }
    return t*2+(rti+lti+1)*T*2;
}

int main()
{
    int leftx,rightx;
    while(cin>>leftx>>rightx&&leftx&&rightx)
    {
        lh=rh=0;
        l=(-leftx)/2,r=rightx/2;
        for(int i=leftx;i<0;i+=2)
        {
            int xi=(-i)/2;
            cin>>lhs[xi];
            if(lh<=lhs[xi])
            {
                lh=lhs[xi];
                lhi=xi;
            }
        }
        for(int i=1;i<=rightx;i+=2)
        {
            int xi=i/2;
            cin>>rhs[xi];
            if(rh<rhs[xi])
            {
                rh=rhs[xi];
                rhi=xi;
            }
        }
        cout<<solve()<<endl;
    }
    return 0;
}
