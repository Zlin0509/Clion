#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int m;
    int a[33]{},b[33]{};
    cin>>m;
    int t,x;
    while(m--)
    {
        cin>>t>>x;
        if(t==1)
        {
            x+=1;
            ++a[x];
        }
        else{
            if(x==0)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                memset(b,sizeof(b),0);
                for(int i=30;i>=0;i--)
                {
                    if((x&(1<<i))!=0)
                    {
                        ++b[i+1];
                        b[i+1]>a[i+1]?b[i+1]-=a[i+1]:b[i+1]=0;
                        b[i]+=b[i+1]*2;
                    }
                }
                b[1]<=0?cout<<"YES"<<endl:cout<<"NO"<<endl;
            }
            
        }
    }
}