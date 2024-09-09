#include "bits/stdc++.h"
using namespace std;
int n, c;
int a[200010]{};
vector<int> e[2];
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> a[i];
        e[c].push_back(i);
    }
    int l = 0, r = 0, u, v, w;
    for (int i = 1; i < n; i++)
    {
        u = e[0][l], v = e[1][r];
        w = min(a[u], a[v]);
        a[u] -= w;
        a[v] -= w;
        cout << u << ' ' << v << ' ' << w << '\n';
        if (!a[u] && l < e[0].size() - 1)
            ++l;
        else
            ++r;
    }
}
int main()
{
    Zlin();
}