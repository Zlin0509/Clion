#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    string x;
    cin >> x;
    char End = x[n - 1];
    deque<int> place;
    place.push_front(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (x[i] >= End)
        {
            End = x[i];
            place.push_front(i);
        }
    }
    int l, r, ans = place.size() - 1;
    int check = 0;
    while (check <= ans && x[place[check]] == x[place[0]])
        ++check;
    ans = ans - check + 1;
    while (place.size() >= 2)
    {
        l = place.front();
        r = place.back();
        place.pop_front();
        place.pop_back();
        swap(x[l], x[r]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i] > x[i + 1])
        {
            cout << "-1" << '\n';
            return;
        }
    }
    cout << ans << '\n';
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