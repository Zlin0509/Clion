#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int n, m, l, r, ans;
char s[200010]{};
map<pair<int, int>, int> z;
int L[200010]{}, R[200010]{};

void solve()
{
    z.clear();
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            R[i] = R[i - 1];
        else
            R[i] = i;
    }
    L[n + 1] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == '0')
            L[i] = L[i + 1];
        else
            L[i] = i;
    }

    while (m--)
    {
        cin >> l >> r;
        l = L[l];
        r = R[r];
        if (l >= r)
            l = r = 0;
        if (!z[{l, r}])
            ++z[{l, r}], ++ans;
    }
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
        solve();
}