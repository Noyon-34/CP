#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                v.push_back(i);
                n /= i;
            }
        }
    }

    if(n > 1)
        v.push_back(n);

    for(auto it: v) {
        cout << it << " ";
    }

    //Time complexity: O(log(n))
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}