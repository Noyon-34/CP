#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        ll p, l;
        cin >> p >> l;

        if ((p + 1) / 2 <= l) {
            cout << "Case " << i << ": " << "impossible\n";
            return;
        }

        vector<int> v;
        ll n = p - l;

        for(int i = 1; (ll)i * i <= n; i++) {
            if(n % i == 0) {
                if(i > l)
                    v.push_back(i);
                if(n / i > l && i != n / i)
                    v.push_back(n / i);
            }

        }

        // if(v.empty()) {
        //     cout << "Case " << i << ": " << "impossible\n";
        //     return;
        // }
        sort(v.begin(), v.end());
        cout << "Case " << i << ": ";
        for(auto it: v)
            cout << it <<" ";
        new
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}