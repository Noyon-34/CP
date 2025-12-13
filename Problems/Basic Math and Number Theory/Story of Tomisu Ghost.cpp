#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 10000019;
using ll = long long;

bitset<N> v;
vector<int> primes;
void sieve() {
    v[1] = false;
    for(int i = 2; i < N; i++) {
        v[i] = true;
    }
    for(int i = 2; i * i < N; i++) {
        if(v[i]) {
            for(int j = i * i; j < N; j += i) {
                v[j] = false;
            }
        }
    }
    for(int i = 2; i < N; i++) {
    	if(v[i])
    		primes.push_back(i);
    }
}

int legend(int n, int p) {
	int ans = 0;
	while(n) {
		ans += n / p;
		n /= p;
	}
	return ans;
}

int power(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1)
			ans =  1LL * ans * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ans;
}
void solve(int cs) {
    int n, t;
    cin >> n >> t;

	int b = 1;
	bool flag = true;
    for(auto it: primes) {
    	if(it > n)
    		break;
    	int f = legend(n, it);
    	int e = f / t;
    	if(e > 0)
    		flag = false;
    	b = 1LL * b * power(it, e) % mod;
    }
    if(flag)
    	b = -1;
    cout << "Case " << cs << ": " << b << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}