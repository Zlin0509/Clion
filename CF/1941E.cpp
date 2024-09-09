#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        vector<long long>a(n);
        
        for(int i=0;i<n;i++)
        {
            vector<int>c(m);
            vector<long long>dp(m,1e9);
            multiset<long long>mcost={1};
            cin>>c[0];
            dp[0]=1;
            for(int j=1;j<m-1;j++)
            {
                cin>>c[j];
                dp[j]=*mcost.begin()+a[j]+1;
                if(j-d-1>=0)
                {
                    mcost.erase(mcost.find(dp[j-d-1]));
                }
                mcost.insert(dp[j]);
            }
            cin>>c.back();
            dp.back()=*mcost.begin()+1;
            a[i]=dp.back();
        }
        long long ans=0;

        for(int i=0;i<k;i++)
        {
            ans+=a[i];
        }

        long long cur=ans;
        for(int i=1;i<n-k;i++)
        {
            cur+=a[i+k]-a[i];
            ans=min(ans,cur);
        }
        cout<<ans<<'\n';
    }
}