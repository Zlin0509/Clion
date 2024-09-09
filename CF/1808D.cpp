#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

int n, k, ans = 0, l, r, z;
int a[200010]{};
vi p1[200010]{}, p2[200010]{};
set<int> used;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        used.insert(a[i]);
        (i & 1) ? p1[a[i]].push_back(i) : p2[a[i]].push_back(i);
    }
    if (k == 1)
    {
        cout << 0;
        return 0;
    }
    ll ans = 1ll * (k / 2) * (n - k + 1);
    for (auto it : used)
    {
        for (auto i : p1[it])
        {
            l = max(i - k + 1, k - i + 1);
            r = min(i - 2, 2 * n - i - k + 1);
            auto x = lower_bound(p1[it].begin(), p1[it].end(), l);
            auto y = upper_bound(p1[it].begin(), p1[it].end(), r);
            z = distance(x, y);
            ans -= z <= 0 ? 0 : z;
        }
        for (auto i : p2[it])
        {
            l = max(i - k + 1, k - i + 1);
            r = min(i - 2, 2 * n - i - k + 1);
            auto x = lower_bound(p2[it].begin(), p2[it].end(), l);
            auto y = upper_bound(p2[it].begin(), p2[it].end(), r);
            z = distance(x, y);
            ans -= z <= 0 ? 0 : z;
        }
    }
    cout << ans;
}