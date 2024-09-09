#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using vi = vector<int>;

const int n = 500000;

int q;
int a, x, y;
int c[500010]{}, k[3010][3010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--)
    {
        cin >> a >> x >> y;
        if (a == 1)
        {
            c[x] += y;
            for (int i = 1; i <= sqrt(n); i++)
                k[i][x % i] += y;
        }
        else
        {
            int ans;
            if (x <= sqrt(n))
            {
                ans = k[x][y];
            }
            else
            {
                ans = 0;
                for (int i = y; i <= n; i += x)
                    ans += c[i];
            }
            cout << ans << '\n';
        }
    }
}