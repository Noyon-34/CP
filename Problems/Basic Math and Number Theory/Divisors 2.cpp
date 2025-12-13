#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
using ll = long long;

vector<int> divisors(N + 1, 0);
void divs() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            divisors[j]++;
        }
    }
}
void solve() {
    bitset<N> v;
    v.set();
    vector<int> ans;
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            if(divisors[j] % divisors[i] != 0)
                v[j] = false;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(divisors[i] > 3 && v[i])
            ans.push_back(i);
    }
    for(int i = 107; i < ans.size(); i += 108)
        cout << ans[i] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    divs();
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}