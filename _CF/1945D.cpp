#include<bits/stdc++.h>
using namespace std;

int n=0,m,ans=0;
long long a[200010]{},b[200010]{},dp[200010]{};

void solve()
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=a[i]=b[i]=0;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=n;i>m;i--)
    {
        dp[i]=min(dp[i+1]+a[i],dp[i+1]+b[i]);
    }
    for(int i=m;i>=1;i--)
    {
        dp[i]=dp[i+1]+b[i];
    }
    if(m==1)
    {
        ans=dp[m+1]+a[m];
        cout<<ans<<'\n';
        return;
    }
    for(int i=m-1;i>=1;i--)
    {
        if(dp[i+1]+a[i]>dp[i+2]+a[i+1]||dp[i]>dp[i+2]+a[i+1])
        {
            ans=dp[i+2]+a[i+1];
            cout<<ans<<'\n';
            return;
        }
        if(i==1)
        {
            ans=dp[i+1]+a[i];
            cout<<ans<<'\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}