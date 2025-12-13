#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve(int cs) {
    char dot;
    int a, b, c, d;
    cin >> a >> dot >> b >> dot >> c >> dot >> d;

    string bina;
    cin >> bina;

    cout << "Case " << cs << ": ";

    string s = bina.substr(0, 8);
    int k = stoi(s, 0, 2);

    if(k != a) {
        cout << "No\n";
        return;
    }

    s = bina.substr(9, 8);
    k = stoi(s, 0, 2);

    if(k != b) {
        cout << "No\n";
        return;
    }

    s = bina.substr(18, 8);
    k = stoi(s, 0, 2);

    if(k != c) {
        cout << "No\n";
        return;
    }

    s = bina.substr(27, 8);
    k = stoi(s, 0, 2);

    if(k != d) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
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