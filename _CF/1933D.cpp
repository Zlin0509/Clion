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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (a[0] < a[1])
    {
        cout << "YES" << '\n';
        return;
    }
    int check = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] % check != 0)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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