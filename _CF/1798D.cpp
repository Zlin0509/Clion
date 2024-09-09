#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int n;
long long a[300010]{}, M, m;
long long check;

void solve()
{
    M = INT_MIN, m = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > M)
            M = a[i];
        if (a[i] < m)
            m = a[i];
    }
    check = M - m;
    bool ss = true;
    for (int i = 1; i <= n;i++)
    {
        if(a[i])
        {
            ss = false;
            break;
        }
    }
    if(ss)
    {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    long long sum = 0;
    while (l < r)
    {
        if (sum + a[r] < check)
            sum = max(sum + a[r], a[r]), cout << a[r--] << " ";
        else
            sum = max(sum + a[l], a[l]), cout << a[l++] << " ";
        // cout << sum << endl;
    }
    if (l == r)
        cout << a[l];
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
        solve();
}