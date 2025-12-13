#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;

    if(x * log(y) > y * log(x))
    	cout << "<";
    else if(x * log(y) < y * log(x))
    	cout << ">";
    else
    	cout << "=";
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