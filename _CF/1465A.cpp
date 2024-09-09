#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
string x;

void solve()
{
    cin >> n >> x;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x[i] == ')')
            ++cnt;
        else
            break;
    }
    if (cnt > n / 2)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
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