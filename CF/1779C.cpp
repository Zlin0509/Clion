#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int a[200010]{}, n, m, ans = 0;
long long sum[200010]{}, check;
priority_queue<long long, vector<long long>, greater<long long>> q;
priority_queue<long long, vector<long long>, less<long long>> p;

void solve()
{
    while (!q.empty())
        q.pop();
    while (!p.empty())
        p.pop();
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    check = sum[m];
    for (int i = m; i >= 1; i--)
    {
        while (sum[i] < check)
        {
            // cout << i << endl;
            ++ans;
            check -= p.top() * 2;
            p.pop();
        }
        p.push(a[i]);
    }
    // cout << endl;
    check = sum[m];
    for (int i = m + 1; i <= n; i++)
    {
        q.push(a[i]);
        while (sum[i] < check)
        {
            // cout << i << endl;
            ++ans;
            check += q.top() * 2;
            q.pop();
        }
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