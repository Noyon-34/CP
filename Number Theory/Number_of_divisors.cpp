#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                mp[i]++;
                n /= i;
            }
        }
    }

    if(n > 1) 
        mp[n]++;
    int count = 1;
    for(auto it: mp)
        count *= (it.second + 1);

    cout << count;
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