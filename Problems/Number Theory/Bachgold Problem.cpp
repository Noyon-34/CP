#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    int n;
    cin >> n;

    if(n & 1) {
        cout << n / 2 << '\n';
        for(int i = 1; i < n / 2; i++)
            cout << "2 ";
        cout << "3 ";
    } else {
        cout << n / 2 << '\n';
        for (int i = 1; i <= n / 2; i++)
            cout << "2 ";
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