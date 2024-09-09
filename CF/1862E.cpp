#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

long long n, m, d;
int a[200010]{};
priority_queue<int, vector<int>, greater<int>> q;
long long ans, sum;

void solve()
{
    ans = 0;
    sum = 0;
    while (!q.empty())
        q.pop();

    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long check;
    for (long long i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            if (q.size() < m)
                q.push(a[i]), sum += a[i];
            else if (q.top() < a[i])
                sum += a[i] - q.top(), q.pop(), q.push(a[i]);
            check = sum - d * i;
            // cout << check << endl;
            ans = max(ans, check);
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