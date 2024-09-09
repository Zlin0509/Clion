#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

struct ss
{
    int num;
    int place;
    int output;
} a[200010]{};

bool cmp1(const ss &a, const ss &b)
{
    if (a.num != b.num)
        return a.num < b.num;
    return a.place < b.place;
}

bool cmp2(const ss &a, const ss &b)
{
    return a.place < b.place;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vi b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].num, a[i].place = i;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n, cmp1);
    sort(b.begin(), b.end());
    int sum = 0;
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (sum < x)
        {
            a[i].output = x - sum - 1;
        }
        else
        {
            a[i].output = r--;
        }
        if (a[i].num > b[a[i].output])
            ++sum;
        if (sum > x)
        {
            cout << "NO" << '\n';
            return;
        }
    }
    if (sum != x)
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    sort(a, a + n, cmp2);
    for (int i = 0; i < n; i++)
        cout << b[a[i].output] << " ";
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