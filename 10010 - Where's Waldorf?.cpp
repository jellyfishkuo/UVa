#include <bits/stdc++.h>
using namespace std;

int dr[]={-1,1,0,0,-1,-1,1,1};
int dc[]={0,0,-1,1,-1,1,-1,1};

bool check(int r,int c,int m,int n,const string& word,const vector<string>& grid)
{
    for(int i=0;i<8;i++)
    {
        int nr=r,nc=c;
        bool match=true;
        for(int k=0;k<word.length();k++)
        {
            if(nr<0||nr>=m||nc<0||nc>=n||grid[nr][nc]!=word[k])
            {
                match=false;
                break;
            }
            nr+=dr[i];
            nc+=dc[i];
        }
        if(match) return true;
    }
    return false;
}

void solve()
{
    int m,n;
    cin>>m>>n;
    vector<string> grid(m);
    for(int i=0;i<m;i++)
    {
        cin>>grid[i];
        for(int j=0;j<n;j++) grid[i][j]=tolower(grid[i][j]);
    }

    int k;
    cin>>k;
    while(k--)
    {
        string word;
        cin>>word;
        for(int i=0;i<word.length();i++) word[i]=tolower(word[i]);
        bool found=false;
        for(int i=0;i<m&&!found;i++)
        {
            for(int j=0;j<n&&!found;j++)
            {
                if(check(i,j,m,n,word,grid))
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    found=true;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        if(t>0) cout<<endl;
    }
    return 0;
}
