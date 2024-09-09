#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vi l1(k), r1(k);
    for (int i = 0; i < k; i++)
        cin >> l1[i];
    for (int i = 0, r; i < k; i++)
        cin >> r1[i];
    int q;
    cin >> q;
    vi arr(n + 1);
    for (int i = 1, x; i <= q; i++)
        cin >> x, ++arr[x];
    for (int i = 1; i <= n; i++)
        arr[i] += arr[i - 1];
    for (int i = 0; i < k; i++)
    {
        int l = l1[i], r = r1[i], cnt;
        while (l < r)
        {
            cnt = arr[l] - arr[l1[i] - 1] + arr[r1[i]] - arr[r - 1];
            if (cnt % 2)
                swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << s[i];
    cout << '\n';
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