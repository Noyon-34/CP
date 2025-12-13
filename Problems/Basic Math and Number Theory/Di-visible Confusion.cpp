#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 2; j < i + 3; j++) {
            if(v[i] % j != 0){
                ok = false;
                break;
            }        
        }
        if(ok) {
            cout << "NO\n";
            return;
        }
    }    
    cout <<"YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}