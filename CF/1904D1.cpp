#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n);
    vector<set<int>> used(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0 && a[j] <= a[i] && b[j] >= a[i]; j--)
            used[j].insert(a[i]);
        for (int j = i + 1; j < n && a[j] <= a[i] && b[j] >= a[i]; j++)
            used[j].insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i].count(b[i]) && a[i] != b[i])
        {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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