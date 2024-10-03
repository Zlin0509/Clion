#include "bits/stdc++.h"
using namespace std;

using ll = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

const ll Mod = 1e9 + 7;

int n;
ll x[500010]{}, ans, s1, s2;
int cnt[63]{};

void solve()
{
    ans = 0, memset(x, 0, sizeof(x)), memset(cnt, 0, sizeof(cnt));

    cin >> n;
    for (int i = 1, l; i <= n; i++)
    {
        cin >> x[i];
        l = 0;
        while ((1ll << l) <= x[i])
        {
            if ((1ll << l) & x[i])
                ++cnt[l + 1];
            ++l;
        }
    }

    for (int i = 0; i <= 63; i++)
        cnt[i] %= Mod;

    for (int i = 1, l; i <= n; i++)
    {
        s1 = 0, s2 = 0, l = 0;
        while ((1ll << l) <= x[i])
        {
            if ((1ll << l) & x[i])
            {
                s1 = (s1 + cnt[l + 1] * ((1ll << l) % Mod)) % Mod;
                s2 = (s2 + n * ((1ll << l) % Mod)) % Mod;
            }
            else
                s2 = (s2 + cnt[l + 1] * ((1ll << l) % Mod)) % Mod;
            ++l;
        }
        while (l <= 60)
        {
            s2 = (s2 + cnt[l + 1] * ((1ll << l) % Mod)) % Mod;
            ++l;
        }
        ans = (ans + s1 * s2 % Mod) % Mod;
    }
    cout << ans << '\n';
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