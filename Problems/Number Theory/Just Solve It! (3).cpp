#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<int> v(N, 0), ans(N, 0);
void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
    }
    
    for(int i = 1; i <= N - 7; i++) {
        for(int j = i; j <= N - 7; j += i) {
            ans[i] += v[j];
        }
    }

    for(int i = 1; i <= 1e6; i++)
        cout << ans[i] << " ";
    new

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