#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

set<ll> Have;

void dd()
{
    for (ll i = 2; i <= 1e6; i++)
    {
        ll sum = i * i, put = 1 + i;
        for (int j = 3; j <= 63; j++)
        {
            put += sum;
            if (put < 1e18)
                Have.insert(put);
            if (sum > (long long)(1e18) / i)
                break;
            sum *= i;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    if (Have.find(n) != Have.end())
    {
        cout << "YES" << '\n';
        return;
    }
    ll l = 1e6 + 1, r = 1e9, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        ll check = mid * mid + mid + 1;
        if (check == n)
        {
            cout << "YES" << '\n';
            return;
        }
        if (check > n)
            r = mid;
        else
            l = mid + 1;
    }
    cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    dd();
    while (T--)
    {
        solve();
    }
}