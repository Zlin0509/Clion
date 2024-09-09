#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int n;
int a[200010], b[200010];

void solve()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ++b[a[i]];
    }
    int num = 0;
    for (int i = 0; i <= n; i++)
    {
        num += (b[i] == 1);
        if(num==2||b[i]==0)
        {
            cout << i << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}