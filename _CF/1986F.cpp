//
// Created by Zlin on 2024/9/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, ans;

const int N = 2e5 + 5;
int dfn[N], low[N], cnt, tot;
struct edge {
    int u, v;
};
vector<edge> e;
vi h[N];
struct bridge {
    int x, y;
} bri[N];

inline void add(int x, int y) {
    e.push_back({x, y});
    h[x].push_back(e.size() - 1);
}

inline void tarjan(int x, int in_edg) {
    dfn[x] = low[x] = ++tot;
    for (int i = 0; i < h[x].size(); i++) {
        int j = h[x][i], y = e[j].v;
        if (!dfn[y]) {
            tarjan(y, j);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                bri[++cnt] = {x, y};
        } else if (j != (in_edg ^ 1))
            low[x] = min(low[x], dfn[y]);
    }
}

inline void Zlin() {
    cin >> n >> m;
    ans = n * (n - 1) / 2;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}