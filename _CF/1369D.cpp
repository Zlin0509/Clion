#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

const ll Mod = 1e9 + 7;
ll d[2000010]{}, u[2000010]{};
int q, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    d[3] = 4;
    u[3] = 1;

    for (int i = 4; i <= 2000001; i++)
    {
        d[i] = (d[i - 1] + d[i - 2] * 2) % Mod;
        if (!u[i - 1] && !u[i - 2])
        {
            d[i] = (d[i] + 4) % Mod;
            u[i] = 1;
        }
    }
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << d[x] << '\n';
    }
}