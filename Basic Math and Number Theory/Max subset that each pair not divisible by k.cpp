#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> modulo_vec;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        modulo_vec.push_back(x % k);
    }

    vector<int> freq(k, 0);
    for(int i = 0; i < n; i++) {
        freq[modulo_vec[i]]++;
    }

    int ans = min(freq[0], 1);

    if(k & 1 == 0)
        freq[k / 2] = min(freq[k / 2], 1);
    
    for(int i = 1; i <= k / 2; i++) {
        ans += max(freq[i], freq[k - i]);
    }

    cout << ans << '\n';

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