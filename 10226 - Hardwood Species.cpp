#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<string,int> mp;
    string treeName;
    int totalTrees=0;
    while(getline(cin,treeName)&&!treeName.empty())
    {
        mp[treeName]++;
        totalTrees++;
    }
    for(auto const& [name,cnt]:mp)
    {
        double p=(double)cnt*100.0/totalTrees;
        cout<<name<<" "<<fixed<<setprecision(4)<<p<<endl;
    }
}

int main()
{
    int cas;
    string dummy;
    cin>>cas>>ws;
    for(int i=0;i<cas;i++)
    {
        if(i>0) cout<<endl;
        solve();
    }
    return 0;
}
