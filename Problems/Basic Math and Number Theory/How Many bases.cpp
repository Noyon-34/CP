#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
const int mod = 100000007;
using ll = long long;

int getting(vector<int> e, int t) {
    int ans = 1;
    for(int i = 0; i < e.size(); i++) {
        ans = 1LL * ans * (e[i] / t + 1) % mod;
    }
    return ans;
}
int get_the_ans(vector<int> e, int t) {
    return (getting(e, t) - getting(e, t + 1) + mod) % mod;
}
void solve() {
    int n, m, t, cs = 0;
    while(cin >> n >> m >> t and n > 0) {
        vector<int> e;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                int cnt = 0;
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                }
                e.push_back(cnt * m);
            }
        }
        if(n > 1)
            e.push_back(m);

        cout << "Case " << ++cs << ": " << get_the_ans(e, t) << '\n';
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