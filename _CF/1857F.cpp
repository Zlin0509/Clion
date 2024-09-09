#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    map<long long, long long> cnt;
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        ++cnt[x];
    }
    int q;
    cin >> q;
    unsigned long long x, y, ans;
    while (q--)
    {
        cin >> y >> x;
        long long check = sqrt(y * y - 4 * x);
        long long l = y + check, r = y - check;
        if (l % 2 != 0 || r % 2 != 0 || check * check != y * y - 4 * x)
            ans = 0;
        else
        {
            if (l != r)
                ans = cnt[l / 2] * cnt[r / 2];
            else
                ans = cnt[l / 2] * (cnt[l / 2] - 1) / 2ll;
        }
        cout << ans << ' ';
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
        solve();
}