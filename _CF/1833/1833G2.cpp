#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

ll n, m;
int a[200010]{}, b[200010]{}, c[200010]{};

bool check(int x)
{
    for (int i = 1; i <= n - x; i++)
        if (a[i] >= b[x + i])
            return false;
    return true;
}

int ss(int x)
{
    for (int i = 2; i <= n; i++)
        a[i] = c[i];
    a[1] = x;
    sort(a + 1, a + 1 + n);
    int l = 0, r = n, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solve()
{
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b + 1, b + 1 + n);
    ll a1 = ss(1);
    int l = 1, r = m + 1, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (ss(mid) > a1)
            r = mid;
        else
            l = mid + 1;
    }
    // cout << a1 << ' ' << l << '\n';
    ll ans = a1 * m + m - l + 1;
    cout << ans << '\n';
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