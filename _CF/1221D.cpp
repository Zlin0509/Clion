#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

const ll INF = 0x3f3f3f3f3f3f3f;

ll n, ans;
int a[300010]{}, b[300010]{};
ll d[300010][3]{};

void solve()
{
    ans = INF;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    for (int i = 1; i <= n; i++)
        memset(d[i], INF, sizeof(d[i]));
    d[1][0] = 0, d[1][1] = b[1], d[1][2] = b[1] * 2;
    for (int i = 2; i <= n; i++)
        for (int k = 0; k < 3; k++)
            for (int j = 0; j < 3; j++)
                if (a[i - 1] + k != a[i] + j)
                    d[i][j] = min(d[i][j], d[i - 1][k] + b[i] * j);

    for (int i = 0; i < 3; i++)
        ans = min(ans, d[n][i]);

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