#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
vector<int> prime;
vector<int> pre(N);
vector<int> val(N);

void sieve() {
    v.set();
    v[1] = false;

    for(int i = 2; 1LL * i * i < N; i++) {
        if(v[i]) {
            for(ll j = 1LL * i * i; j < N; j += i) {
                v[j] = false;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(v[i])
            prime.push_back(i);
    }
}

bool digits(int n) {
    while (n) {
        if (n % 10 == 0)
            return 1;
        n /= 10;
    }
    return 0;
}

int all_prime(int n) {
    if(!v[n])
        return 0;
    if(digits(n))
        return 0;
    string s = to_string(n);
    int len = s.length();

    for(int i = 0; i < len; i++) {
        string t = s.substr(i);
        int a = stoi(t);

        if(!v[a])
            return 0;
    }

    return 1;
}


void solve() {
    int n;
    cin >> n;

    cout << pre[n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();

    for(int i = 1; i < N; i++) {
        val[i] = all_prime(i);
    }

    for(int i = 1; i < N; i++) {
        pre[i] = pre[i-1] + val[i];
    }
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}