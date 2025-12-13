#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

string canConstruct (int n) {
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int x = v[i];
        while(x) {
            int d = x % 10;
            x /= 10;
            sum += d;
        }
    }

    if(sum % 3)
        return "No";
    else
        return "Yes";
}
void solve() {
    int n;
    cin >> n;
    cout << canConstruct(n) << '\n';
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