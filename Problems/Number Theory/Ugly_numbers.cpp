#include<bits/stdc++.h>
using namespace std;

const int N = 1e9;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    vector<int> v;
    ll p1 = 1;

    while(p1 <= N) {
        ll p2 = 1;
        while(p1 * p2 <= N) {
            ll p3 = 1;
            while(p1 * p2 * p3 <= N) {
                v.push_back(p1* p2 * p3);
                p3 *= 5;
            }
            p2 *= 3;
        }
        p1 *= 2;
    }

    sort(v.begin(), v.end());
    cout << "The 1500'th ugly number is " << v[1499] << ".\n";
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