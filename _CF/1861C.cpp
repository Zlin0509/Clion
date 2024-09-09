#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

string x;

void solve()
{
    cin >> x;
    int len = x.length();
    int num = 0, z = 0, q = 0;
    for (int i = 0; i < len; i++)
    {
        if (x[i] == '+')
        {
            ++num;
        }
        if (x[i] == '-' || x[i] == '/')
        {
            --num;
            if (num < z)
                z = 0;
            if (num < q)
                q = num;
        }
        if (x[i] == '1')
        {
            if (z)
            {
                cout << "NO" << '\n';
                return;
            }
            q = num;
        }
        if (x[i] == '0')
        {
            if (q == num || num < 2)
            {
                cout << "NO" << '\n';
                return;
            }
            if (!z)
                z = num;
        }
        // cout << num << " " << q << " " << z << '\n';
    }
    cout << "YES" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}