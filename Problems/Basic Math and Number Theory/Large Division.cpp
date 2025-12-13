#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve(int cs) {
    string a; int b;
    cin >> a;
    cin >> b;

    cout << "Case " << cs << ": ";
    int mod = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '-')
            continue;
        mod = (mod * 10 + a[i] - '0') % b;
    }

    if(mod)
        cout << "not divisible\n";
    else
        cout << "divisible\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}