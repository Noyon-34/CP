// https://vjudge.net/problem/spoj-multii
// Solved in 26.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
	int n, m, cs = 0;
    while(cin >> n >> m) {
    	cout << "Case " << ++cs << ": ";
    	vector<bool> bad(10, false);
    	while(m--) {
    		int d; cin >> d;
    		bad[d] = true;
    	}

    	vector<int> vis(n, false);
    	vector<int> digit(n), par(n);
    	queue<int> q;

    	for(int d = 1; d <= 9; d++) {
    		int x = d % n;
    		if(!bad[d] and !vis[x]) {
    			vis[x] = true;
    			q.push(x);
    			digit[x] = d;
    			par[x] = -1;
    		}
    	}

    	while(!q.empty()) {
    		int x = q.front();
    		q.pop();

    		for(int d = 0; d <= 9; d++) {
    			int next_x = x * 10 + d;
    			next_x %= n;
    			if(!bad[d] and !vis[next_x]) {
    				vis[next_x] = true;
    				q.push(next_x);
    				digit[next_x] = d;
    				par[next_x] = x;
    			}
    		}
    	}

    	if(vis[0]) {
    		vector<int> path;
    		int cur = 0;
    		while(cur != -1) {
    			path.push_back(digit[cur]);
    			cur = par[cur];
    		}
    		reverse(path.begin(), path.end());
    		for(auto it: path)
    			cout << it;
    		cout << '\n';
    	}
    	else
    		cout << -1 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}