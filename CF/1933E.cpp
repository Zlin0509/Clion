#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    ll n;
    cin >> n;
    vl a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    int q;
    cin >> q;
    ll l, u, r, mid, Max, m;
    while (q--)
    {
        cin >> l >> u;
        ll l1 = l, r1 = n;
        while (l1 < r1)
        {
            mid = l1 + r1 + 1 >> 1;
            if (sum[mid] - sum[l - 1] <= u)
                l1 = mid;
            else
                r1 = mid - 1;
        }
        int ans = l1;
        Max = INT_MIN;
        for (int i = max(l1 - 2, l); i <= min(l1 + 2, n); i++)
        {
            int t = sum[i] - sum[l - 1];
            m = t * (u * 2 - t + 1) / 2;
            if (m > Max)
            {
                Max = m;
                ans = i;
            }
        }
        cout << ans << " ";
    }
    cout << '\n';
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