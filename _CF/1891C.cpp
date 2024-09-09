#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], s += a[i];
    s /= 2;
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!s)
            break;
        if (a[i] <= s)
        {
            ++ans;
            s -= a[i];
            a[i] = 0;
        }
        else
        {
            a[i] -= s;
            ++ans;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        ans += a[i];
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