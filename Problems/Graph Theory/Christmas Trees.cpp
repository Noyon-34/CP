// https://codeforces.com/problemset/problem/1283/D
// Solved in 08.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    queue<int> q;
    map<int, int> dis;
    while(n--) {
    	int v; cin >> v;
    	q.push(v);
    	dis[v] = 0;
    }

    ll ans = 0;
    vector<int> v;

    while(!q.empty() && m) {
    	int u = q.front();
    	q.pop();
    	if(dis.find(u - 1) == dis.end() && m) {
    		dis[u - 1] = dis[u] + 1;
    		q.push(u - 1);
    		ans += dis[u - 1];
    		v.push_back(u - 1);
    		m--;
    	}

    	if(dis.find(u + 1) == dis.end() && m) {
    		dis[u + 1] = dis[u] + 1;
    		q.push(u + 1);
    		ans += dis[u + 1];
    		v.push_back(u + 1);
    		m--;
    	}
    }

    cout << ans << '\n';
    for(auto it: v) {
    	cout << it << ' ';
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