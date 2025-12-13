#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

int gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    if(a < b) swap(a, b);
    return gcd(a % b, b);
}
void solve() {
    cout << gcd(100, 20);
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