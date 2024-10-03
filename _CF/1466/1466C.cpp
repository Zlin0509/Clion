#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

char s[1000010]{};

void solve()
{
    int cnt = 0, ans = 0;
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] != '1' && s[i + 1] != '1')
            ++ans, s[i + 1] = '1';
        if (s[i] == s[i + 2] && s[i] != '1' && s[i + 2] != '1')
            ++ans, s[i + 2] = '1';
    }
    if (s[len - 1] == s[len - 2] && s[len - 1] != '1' && s[len - 2] != '1')
        ++ans;
    cout << ans << '\n';
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