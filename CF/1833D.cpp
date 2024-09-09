#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int q;
    cin >> q;
    set<int> l, r;
    map<int, int> num_l, num_r;
    int l1, r1;
    char ch;
    while (q--)
    {
        cin >> ch >> l1 >> r1;
        if (ch == '+')
        {
            l.insert(l1);
            r.insert(r1);
            ++num_l[l1];
            ++num_r[r1];
        }
        else
        {
            --num_l[l1];
            --num_r[r1];
            if (num_l[l1] == 0)
                l.erase(l1);
            if (num_r[r1] == 0)
                r.erase(r1);
        }
        if (!l.empty())
        {
            if (*l.rbegin() > *r.begin())
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}