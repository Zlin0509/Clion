#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

const ll Mod = 998244353;

int n, tot;
ll head[400010]{}, z[200010]{};
struct Edge
{
    int to, next;
    int val1, val2;
} e[400010]{};

void add(int u, int v, pair<int, int> val)
{
    ++tot;
    e[tot].val1 = val.first;
    e[tot].val2 = val.second;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

pair<ll, ll> dfs(int u, int f)
{
    pair<ll, ll> sum = {0, 1};
    vector<pair<ll, ll>> ss;
    ll zz = z[u];
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != f)
            zz = zz * e[i].val1 / gcd(zz, e[i].val1) % Mod;
    for (int i = head[u]; i; i = e[i].next)
    {
        if (e[i].to != f)
        {
            z[e[i].to] = e[i].val2 * zz / e[i].val1 % Mod;
            ss.push_back(dfs(e[i].to, u));
        }
    }
    sum.second = zz / z[u];
    z[u] = zz;

    zz = 1;
    for (auto it : ss)
        zz = zz * it.second / gcd(zz, it.second) % Mod;
    z[u] *= zz;
    for (auto it : ss)
        sum.first = (sum.first + it.first * zz / it.second) % Mod;
    sum.first = (sum.first + z[u]) % Mod;
    sum.second = sum.second * zz % Mod;

    return sum;
}

void clear()
{
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(z, 0, sizeof(z));
    memset(e, 0, sizeof(e));
}

void solve()
{
    clear();
    cin >> n;
    for (int i = 1, a, b, c, d; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        add(a, b, {c, d}), add(b, a, {d, c});
    }
    z[1] = 1;
    cout << dfs(1, 1).first << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        solve();
}