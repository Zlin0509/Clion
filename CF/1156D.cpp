#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

ll n, ans = 0, n0[200010]{}, n1[200010]{};
int f0[200010]{}, f1[200010]{}, check0[200010]{}, check1[200010]{};
int head[400010]{}, tot = 0;
struct ss
{
    int to, next, val;
} e[400010]{};

void add_edge(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}

int find0(int x) { return f0[x] == x ? x : f0[x] = find0(f0[x]); }
int find1(int x) { return f1[x] == x ? x : f1[x] = find1(f1[x]); }

void merge0(int x, int y)
{
    int fx = find0(x), fy = find0(y);
    if (fx == fy)
        return;
    n0[fx] += n0[fy];
    f0[fy] = fx;
}

void merge1(int x, int y)
{
    int fx = find1(x), fy = find1(y);
    if (fx == fy)
        return;
    n1[fx] += n1[fy];
    f1[fy] = fx;
}

void perwork(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        if (e[i].to != fa)
        {
            e[i].val == 1 ? merge1(u, e[i].to) : merge0(u, e[i].to);
            perwork(e[i].to, u);
        }
    }
}

void dfs(int u, int fa)
{
    ans += n0[find0(u)] + n1[find1(u)] - 2;
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != fa)
            dfs(e[i].to, u);
}

void read()
{
    cin >> n;
    for (int i = 1, u, v, val; i < n; i++)
    {
        cin >> u >> v >> val;
        add_edge(u, v, val), add_edge(v, u, val);
        val == 1 ? ++check1[u], ++check1[v] : ++check0[u], ++check0[v];
    }
    for (int i = 1; i <= n; i++)
        f0[i] = i, f1[i] = i, n0[i] = 1, n1[i] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    perwork(1, 1);
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
        if (check0[i] && check1[i])
            ans += (n0[find0(i)] - 1) * (n1[find1(i)] - 1);
    cout << ans;
}