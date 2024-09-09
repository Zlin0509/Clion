#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

ll n, k, l, r, mid;
ll a[1010]{};
ll cnt[1010]{};

inline bool check(int x)
{
    for (ll i = 1, c, m; i <= n; i++)
    {
        c = 0;
        m = x;
        for (int j = i; j <= n; j++)
        {
            if (a[j] >= m)
                break;
            c += m - a[j];
            if (j == n)
            {
                if (a[n] <= m)
                    return false;
                else
                    return true;
            }
            m = max(0ll, m - 1);
        }
        if (c <= k)
            return true;
    }
    return false;
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    l = INT_MIN;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], l = max(l, a[i]);
    r = l + k;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}