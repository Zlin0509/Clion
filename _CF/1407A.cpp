#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, cnt;
int a[10001]{};

void solve()
{
    cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ++cnt;
    }
    if (cnt <= n / 2)
    {
        cout << n - cnt << '\n';
        for (int i = 1; i <= n - cnt; i++)
            cout << 0 << ' ';
        cout << '\n';
    }
    else
    {
        if (cnt % 2 == 0)
        {
            cout << cnt << '\n';
            for (int i = 1; i <= cnt; i++)
                cout << 1 << ' ';
            cout << '\n';
        }
        else
        {
            cnt = cnt / 2 * 2;
            cout << cnt << '\n';
            for (int i = 1; i <= cnt; i++)
                cout << 1 << ' ';
            cout << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        solve();
}