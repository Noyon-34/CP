#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

void solve() {
    int spf[N];

    for(int i = 2; i < N; i++)
        spf[i] = i;
    
    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i)
            spf[j] = min(spf[j], i);
    }

    //You have q queries find the prime factorization of n
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        vector<int> v;
        while(n > 1) {
            v.push_back(spf[n]);
            n /= spf[n];
        }

        for(auto it: v)
            cout << it << ' ';
        
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