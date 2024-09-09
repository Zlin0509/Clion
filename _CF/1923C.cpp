#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, q;
    cin >> n >> q;
    vl a(n + 1), sum(n + 1), n0(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        n0[i] = n0[i - 1];
        if (a[i] == 1)
            ++n0[i];
    }
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        if (l == r)
        {
            cout << "NO" << '\n';
            continue;
        }

        if (n0[r] - n0[l - 1] <= sum[r] - sum[l - 1] - r + l - 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
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