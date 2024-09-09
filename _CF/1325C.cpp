#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, c1, c2;
struct ss
{
    int id, k;
    friend bool operator<(const ss &a, const ss &b) { return a.k > b.k; }
} v[500010]{};
int l[500010]{}, r[500010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    c1 = 0, c2 = n - 2;
    for (int i = 1; i < n; i++)
    {
        cin >> l[i] >> r[i];
        v[i].id = i;
        ++v[l[i]].k;
        ++v[r[i]].k;
    }
    sort(v + 1, v + 1 + n);
    for (int i = 1; i < n; i++)
    {
        if (l[i] == v[1].id || r[i] == v[1].id)
            cout << c1++ << '\n';
        else
            cout << c2-- << '\n';
    }
}