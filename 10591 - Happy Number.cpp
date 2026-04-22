#include <bits/stdc++.h>
using namespace std;

int SQUARE[]={0,1,4,9,16,25,36,49,64,81};

int next_n(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=SQUARE[n%10];
        n/=10;
    }
    return sum;
}

int cas,n;

int main()
{
    cin>>cas;
    for(int t=1;t<=cas;t++)
    {
        cin>>n;
        int cur=n;
        while(cur>=10) cur=next_n(cur);
        bool ans=(cur==1||cur==7);
        cout<<"Case #"<<t<<": "<<n<<(ans?" is a Happy number.\n":" is an Unhappy number.\n");
    }
    return 0;
}
