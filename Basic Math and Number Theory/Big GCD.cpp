#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int a; string b;
    cin >> a >> b;

    int x;

    if(a == 0) {
    	cout << b << '\n';
    }
    else {
    	int new_b = 0;
    	for(int i = 0; i < b.size(); i++) {
    		new_b = (new_b * 10 + b[i] - '0') % a;
    	}
    	cout << __gcd(a, new_b) << '\n';
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