#include<bits/stdc++.h>
using namespace std;

using ll = long long;
// const int N = 1e9 + 7;
const long long MAX = 1e15;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
    	cin >> v[i];
    }

    sort(v.begin(), v.end());

    unsigned long long ans = 1e18;
    for(int c = 1; c < 10000000; c++) {
    	unsigned long long operation = v[0] - 1;
    	bool check = false;
    	vector<ll> power_of_c(n);
    	power_of_c[0] = 1;
    	for(int i = 1; i < n; i++) {
    		power_of_c[i] = power_of_c[i - 1] * c;
    		operation += abs(v[i] - power_of_c[i]);

    		if(abs(v[i]-power_of_c[i]) > 100000000000) {
    			check = true;
    			break;
    		}
    	}

    	if(power_of_c[n - 1] > MAX or check) {
    		break;
    	}
    	ans = min(ans, operation);
    }

    cout << ans << '\n';
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