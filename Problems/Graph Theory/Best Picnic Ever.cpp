// https://vjudge.net/problem/lightoj-1111
// Solved in 08.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];

void dfs(int u, vector<int>& reachable) {
	vis[u] = true;
	reachable.push_back(u);
	for(auto v: graph[u]) {
		if(!vis[v]) {
			dfs(v, reachable);
		}
	}
}

void solve(int cs) {
    int k, n, m; cin >> k >> n >> m;
    vector<int> people(k);
    for(int i = 0; i < k; i++) {
    	cin >> people[i];
    }

    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    }

    map<int, int> mp;
    for(auto u: people) {
    	vector<int> reachable;
    	fill(vis, vis + N, false);
    	dfs(u, reachable);
    	for(auto it: reachable)
    		mp[it]++;
    }

    int ans = 0;
    for(auto it: mp) {
    	if(it.second == k)
    		ans++;
    }
    cout << "Case " << cs << ": " << ans << '\n';

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