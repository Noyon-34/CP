#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<int> phisieve(int n) {
    vector<int> phi(n + 1);
    for(int i = 1; i <= n; i++)
        phi[i] = i;
    
    for(int i = 2; i <= n; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    return phi;
}
void solve(vector<int> v) {
    int n;
    cin >> n;

    cout << v[n] << '\n';
    // for(auto it: v)
    //     cout << it << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = phisieve(N);
    int t = 1;
    cin >> t;
    while(t--) {
        solve(v);
    }
    return 0;
}