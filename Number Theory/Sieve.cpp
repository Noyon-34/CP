#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
using ll = long long;

bitset<N> a;

void solve(auto st)
{
    int n = 9;
    // cin >> n;

    vector<int> v;
    a[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!a[i])
        {
            v.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                a[j] = true;
            }
        }
    }

    for (auto it : v)
        cout << it << " ";

    cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto st = clock();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve(st);
    }
    return 0;
}