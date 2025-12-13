#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

// You have to find how many number have odd diviosr count in a given number
void solve() {
    int n;
    cin >> n;

    for(int i = 1; i * i <= n; i++)
        cout << i * i << " ";
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