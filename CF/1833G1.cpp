#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n+1), b(n+1);
    a[1] = m;
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int l = 1, r = n, mid;
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        bool check = true;
        for (int i = 1; i <= mid; i++)
        {
            if (a[i] >= b[i + n - mid])
            {
                check = false;
                break;
            }
        }
        if (check)
            l = mid;
        else
            r = mid - 1;
    }
    cout << n - l << '\n';
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