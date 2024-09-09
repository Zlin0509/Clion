#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
        cout << i << " " << i + 1 << '\n';
    for (int i = 1, d, p = n - 1; i <= q; i++)
    {
        cin >> d;
        if (d == p)
            cout << "-1 -1 -1\n";
        else
            cout << n << " " << p << " " << d << '\n', p = d;
    }
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