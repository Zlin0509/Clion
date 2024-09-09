//
// Created by Zlin on 2024/9/4.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 2e5 + 5;

struct edge {
    int u, v, val;

    bool operator<(const edge x) const {
        return val > x.val;
    }
};

int f[N], dep[N], fa[N][22];
vi e[N], x, y;
vector<edge> a;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int u, int v) { f[find(u)] = find(v); }

inline void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v: e[u])
        if (v != f)
            dfs(v, u);
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i]; // 让u，v处于同一层
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i]; // 返回祖先的下一层
    return fa[u][0];
}

inline void Zlin() {
    int n, k, s;
    a.clear();
    x.clear();
    y.clear();
    cin >> n >> k;
    for (int i = 0, u, v, w; i < k; i++) {
        cin >> u >> v >> w;
        a.push_back({u, v, w});
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 19; j++) fa[i][j] = 0;
        f[i] = i;
        e[i].clear();
    }
    edge ans;
    for (auto it: a) {
        if (find(it.u) != find(it.v)) {
            merge(it.u, it.v);
            e[it.u].push_back(it.v);
            e[it.v].push_back(it.u);
        } else ans = it, s = find(it.u);
    }
    dfs(s, 0);
    int u = ans.u, v = ans.v, val = ans.val, ff = lca(u, v);

    while (u != ff) {
        x.push_back(u);
        u = fa[u][0];
    }
    while (v != ff) {
        y.push_back(v);
        v = fa[v][0];
    }
    x.push_back(ff);
    reverse(y.begin(), y.end());
    for (auto it: y) x.push_back(it);
    cout << val << ' ' << x.size() << '\n';
    for (auto it: x) cout << it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}