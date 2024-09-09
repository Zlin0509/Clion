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
    ll num = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            int k = a[i - 1] / a[i];
            if (a[i - 1] % a[i] != 0)
                ++k;
            num += k - 1;
            a[i - 1] /= k;
        }
    }
    cout << num << '\n';
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