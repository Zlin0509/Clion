#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int m, n;
int dp[5010]{};
int cnt[5010]{};

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        if (x <= 5000)
            ++cnt[x];
    }
    int small = 0;
    while (cnt[small])
        ++small;

    // cout << small << '\n';

    for (int i = small - 1; i >= 0; i--)
    {
        dp[i] = small * (cnt[i] - 1) + i;
        for (int j = i + 1; j <= small; j++)
            dp[i] = min(dp[i], dp[j] + j * (cnt[i] - 1) + i);
    }

    cout << dp[0] << '\n';
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