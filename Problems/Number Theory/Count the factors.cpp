#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    while(1) {
        int n, x;
        cin >> n;

        x = n;
        if(!n)
            break;
        
        vector<int> v;
        for(int i = 2; i * i < n; i++) {
            if(n % i == 0) {
                while(n % i == 0)
                    n /= i;
                v.push_back(i);
            }
        }

        if(n > 1)
            v.push_back(n);

        cout << x << " : " << v.size() << '\n';
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