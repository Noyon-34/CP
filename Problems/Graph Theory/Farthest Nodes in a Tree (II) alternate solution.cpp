// https://vjudge.net/problem/lightoj-1257
// Solved in 03.02.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
using ll = long long;

vector<pair<int, int>> graph[N];
int n;

int farthest_node(int s, vector<ll> &dis) {
	dis.resize(n + 1);
	vector<int> vis(n + 1, false);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	dis[s] = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto [v, w]: graph[u]){
			if(!vis[v]) {
				dis[v] = dis[u] + w;
				vis[v] = true;
				q.push(v);
			}
		}
	}

	int farthest = max_element(dis.begin() + 1, dis.end()) - dis.begin();
	return farthest;
}

void solve(int cs) {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
    	int u, v, w; cin >> u >> v >> w;
    	u++, v++;
    	graph[u].push_back({v, w});
    	graph[v].push_back({u, w});
    }

    vector<ll> ds, de;
    int s = farthest_node(1, ds);
    int e = farthest_node(s, ds);
    farthest_node(e, de);

    cout  << "Case " << cs << ": \n";
    for(int i = 1; i <= n; i++) {
    	cout << max(ds[i], de[i]) << '\n';
    }

    for(int i = 1; i <= n; i++) {
    	graph[i].clear();
    }
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