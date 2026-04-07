#include <bits/stdc++.h>
#define maxn 105
#define maxm 3005
using namespace std;

int n,m,dp[maxn][maxm],p[maxn][maxm];
int needs[]={6,2,5,5,4,5,6,3,7,6};

int main()
{
    int cas=0;
    while(cin>>n)
    {
        if(n==0) return 0;
        cin>>m;
        cout<<"Case "<<++cas<<": ";
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int& min_match=dp[i][j];
                min_match=p[i][j]=-1;
                if(j==0) min_match=0;
                for(int d=9;d>=0;d--)
                {
                    if(i>=needs[d])
                    {
                        int t=dp[i-needs[d]][(j*10+d)%m];
                        if(t>=0&&(t+1)>min_match)
                        {
                            min_match=t+1;
                            p[i][j]=d;
                        }
                    }
                }
            }
        }
        if(p[n][0]<0) cout<<"-1";
        else
        {
            int i=n,j=0;
            for(int d=p[i][j];d>=0;d=p[i][j])
            {
                cout<<d;
                i-=needs[d];
                j=(j*10+d)%m;
            }
        }
        cout<<endl;
    }
    return 0;
}
