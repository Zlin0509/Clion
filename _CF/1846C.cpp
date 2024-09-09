#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

struct ss
{
    int point = 0;
    ll time = 0;
};

bool cmp(const ss &a, const ss &b)
{
    if (a.point != b.point)
        return a.point > b.point;
    return a.time < b.time;
}

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<ss> ans(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
        a[i].resize(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
        ll sum = 0;
        for (int j = 0; j < m; j++)
        {
            if (sum + a[i][j] <= h)
            {
                sum += a[i][j];
                ans[i].time += sum;
                ++ans[i].point;
            }
            else
                break;
        }
    }
    ss check = ans[0];
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (ans[i].point < check.point)
        {
            cout << i + 1 << '\n';
            return;
        }
        if (ans[i].point == check.point && check.time <= ans[i].time)
        {
            cout << i + 1 << '\n';
            return;
        }
    }
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