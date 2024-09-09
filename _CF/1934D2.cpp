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
        int n,turn=0,check=0;
        long long p=0;
        cin>>p;
        n=__builtin_popcountll(p);
        if(!(n%2))
        {
            cout<<"first"<<endl;
            check=1;
        }
        else
        {
            cout<<"seconde"<<endl;
        }
        while(true)
        {
            if(turn%2==check){
                long long p1,p2;
                cin>>p1>>p2;
                if(p1==0&&p2==0)
                {
                    break;
                }
                if(__builtin_popcountll(p1)%2==0)
                    p=p1;
                else
                    p=p2;
            }
            else
            {
                int num=(64-__builtin_clzll(p))-1;
                long long p1=(1ll<<num);
                long long p2=p^p1;
                cout<<p1<<" "<<p2<<endl;
            }
            ++turn;
        }
    }
}