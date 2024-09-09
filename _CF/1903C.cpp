#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vl a(n);
    vl sum(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i];
    ll ans = sum[0];
    for (int i = 1; i < n; i++)
        if (sum[i] > 0)
            ans += sum[i];
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