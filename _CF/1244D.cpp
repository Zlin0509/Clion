#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;
int n;
int c[4][200010]{};
struct Edge
{
    int to, next;
} e[200010]{};
int tot = 0, head[200010]{};
vi a;

void add_edge(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

void prework(int u, int fa)
{
    a.push_back(u);
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != fa)
            prework(e[i].to, u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        add_edge(u, v), add_edge(v, u);
    }
    a.push_back(0);
    prework(1, 1);
}