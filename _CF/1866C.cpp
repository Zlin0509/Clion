#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

string x;
ll n, pos;

void solve()
{
    cin >> x;
    cin >> pos;
    vector<char> str;
    n = x.length();
    x += ' ';
    for (int i = 0; i <= x.length(); i++)
    {
        while (pos > n && !str.empty() && str.back() > x[i])
        {
            pos -= n;
            --n;
            str.pop_back();
        }
        str.push_back(x[i]);
    }
    // cout << pos << '\n';
    cout << str[pos - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}