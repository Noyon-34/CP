#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

int trailing_zero(int n) {
    int cn = 0;
    while(n) {
        cn += n / 5;
        n /= 5;
    }
    return cn;
}
void solve(int cs) {
    int n;
    cin >> n;

    int l = 1, r = 5 * n, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        int zero = trailing_zero(mid);

        if(zero == n) {
            ans = mid;
            r = mid - 1;
        }
        else if(ans < n) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << "Case " << cs << ": ";
    if(ans == -1) {
        cout << "impossible\n";
    }
    else
        cout << ans << '\n';
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