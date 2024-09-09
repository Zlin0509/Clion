#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

void solve()
{
    int m;
    vi a;
    cin >> m;
    for (int i = 1, x; i <= m; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (auto it : a)
        cout << it << ' ';
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