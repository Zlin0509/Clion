#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int m, n;
int used[5010]{};
int a[5010]{};

void dfs(int small, int depth, int sum)
{
    if (small == 0 || depth == n)
    {
        m = min(m, sum);
        return;
    }
    int i = 0;
    while (i < small)
    {
        dfs(i, depth + used[i], sum + small * used[i] - small + i);
        ++i;
        if (used[i] > used[i - 1])
            break;
    }
}

void solve()
{
    memset(used, 0, sizeof(used));
    m = INT_MAX;

    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= 5000)
            ++used[a[i]];
    }
    int l = 0;
    while (used[l])
        ++l;
    // cout << l << endl;
    dfs(l, 0, 0);
    cout << m << '\n';
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