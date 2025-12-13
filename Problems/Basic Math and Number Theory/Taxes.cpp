#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

bool is_prime(int n) {
    if(n == 1)
        return false;
    for(int i = 2; 1LL * i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;

    if(is_prime(n))
        cout << "1\n";
    else if(n % 2 == 0)
        cout << "2\n";
    else {
        if(is_prime(n - 2))
            cout << "2\n";
        else
            cout << "3\n";
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