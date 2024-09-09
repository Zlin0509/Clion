#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;
const int N = 2e5 + 10;
const ll INF = 1e12;
int n, m, p, l, r, mid;
ll ans;
struct ss1
{
    int val, cost;
} a[N], a1[N];

struct ss2
{
    int val, cost;
} b[N], b1[N];

struct ss3
{
    int val1, val2, cost;
} c[N];

struct Tree
{
    int l, r;
    ll val, Max, tag = 0;
} T[N << 2];

bool cmp1(ss1 &x, ss1 &y)
{
    return x.val < y.val || (x.val == y.val && x.cost < y.cost);
}
bool cmp2(ss2 &x, ss2 &y)
{
    return x.val < y.val || (x.val == y.val && x.cost < y.cost);
}
bool cmp3(ss3 &x, ss3 &y)
{
    return x.val2 < y.val2;
}

inline void read()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> a1[i].val >> a1[i].cost;
    for (int i = 1; i <= m; i++)
        cin >> b1[i].val >> b1[i].cost;
    for (int i = 1; i <= p; i++)
        cin >> c[i].val1 >> c[i].val2 >> c[i].cost;
    sort(a1 + 1, a1 + 1 + n, cmp1);
    sort(b1 + 1, b1 + 1 + m, cmp2);
    sort(c + 1, c + 1 + p, cmp3);
    // 手动离散化，结构体不会，，，，
    int n1 = 0, m1 = 0;
    for (int i = 1; i <= n; i++)
        if (a1[i].val != a[n1].val)
            a[++n1] = a1[i];
    for (int i = 1; i <= m; i++)
        if (b1[i].val != b[m1].val)
            b[++m1] = b1[i];
    n = n1, m = m1;
}

inline void build(int l, int r, int i)
{
    T[i].l = l, T[i].r = r;
    if (l == r)
    {
        T[i].val = -a[l].cost;
        T[i].Max = -a[l].cost;
        return;
    }
    int mid = l + r >> 1;
    if (mid >= l)
        build(l, mid, i << 1);
    if (mid + 1 <= r)
        build(mid + 1, r, i << 1 | 1);
    T[i].val = T[i << 1].val + T[i << 1 | 1].val;
    T[i].Max = max(T[i << 1].Max, T[i << 1 | 1].Max);
}

inline void push_down(int i)
{
    T[i].Max += T[i].tag;
    if (T[i].l != T[i].r)
    {
        T[i << 1].tag += T[i].tag;
        T[i << 1 | 1].tag += T[i].tag;
    }
    T[i].tag = 0;
}

inline void change(int l, int r, int i, int k)
{
    if (T[i].l > r || T[i].r < l)
        return;
    push_down(i);
    if (T[i].r <= r && T[i].l >= l)
    {
        T[i].tag += k;
        return;
    }
    if (T[i].l <= r)
        change(l, r, i << 1, k);
    if (T[i].r >= l)
        change(l, r, i << 1 | 1, k);
    T[i].Max = max(T[i << 1].Max + T[i << 1].tag, T[i << 1 | 1].Max + T[i << 1 | 1].tag);
}

inline void Main()
{
    int it1 = 1, it2 = 1;
    ans = -a[1].cost - b[1].cost;
    while (it1 <= m)
    {
        while (it2 <= p && c[it2].val2 < b[it1].val)
        {
            l = 1, r = n;
            while (l < r)
            {
                mid = l + r >> 1;
                a[mid].val <= c[it2].val1 ? l = mid + 1 : r = mid;
            }
            if (a[l].val > c[it2].val1)
                change(l, n, 1, c[it2].cost);
            ans = max(ans, T[1].Max + T[1].tag - b[it1].cost);
            ++it2;
        }
        ++it1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    build(1, n, 1);
    Main();
    cout << ans;
}