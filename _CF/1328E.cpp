#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

int n, m, step = 0;
vector<vector<int>> t(200010);
int d[200010]{}, f[200010]{}, dfn[200010]{}, s[200010]{};
int z[200010]{};

bool cmp(int x, int y) { return d[x] < d[y]; }

void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    f[u] = fa;
    dfn[u] = ++step;
    s[u] = 1;
    for (auto v : t[u])
        if (v != fa)
        {
            dfs(v, u);
            s[u] += s[v];
        }
}

bool check(int x, int y)
{
    return (dfn[x] <= dfn[y] && dfn[y] < dfn[x] + s[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, t[u].push_back(v), t[v].push_back(u);
    dfs(1, 1);
    while (m--)
    {
        int k;
        bool ch = true;
        cin >> k;
        for (int i = 1, x; i <= k; i++)
            cin >> x, z[i] = f[x];
        sort(z + 1, z + 1 + k, cmp);
        for (int i = 1; i < k; i++)
        {
            if (!check(z[i], z[i + 1]))
            {
                ch = false;
            }
        }
        cout << (ch ? "YES" : "NO") << '\n';
    }
}