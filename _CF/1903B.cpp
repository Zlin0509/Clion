#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
        a[i].resize(n);
    vi ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = (1 << 30) - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i != j)
            {
                ans[i] &= a[i][j];
                ans[j] &= a[i][j];
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            if ((ans[i] | ans[j]) != a[i][j])
            {
                cout << "NO" << '\n';
                return;
            }
        }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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
    {
        solve();
    }
}