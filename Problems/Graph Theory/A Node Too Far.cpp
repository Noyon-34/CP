// https://vjudge.net/problem/uva-336
// Solved in 30.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];

void solve() {
	int cs = 0;
    while(1) {
    	int n; cin >> n;
    	if(!n)
    		break;

    	for(int i = 0; i < N; i++) {
    		vis[i] = false;
    		graph[i].clear();
    	}

    	set<int> s;
    	vector<pair<int, int>> vp;
    	for(int i = 1; i <= n; i++) {
    		int u, v; cin >> u >> v;
    		s.insert(u);
    		s.insert(v);
    		vp.push_back({u, v});
    	}

    	map<int, int> mp;
    	int id = 0;
    	for(auto it: s) {
    		mp[it] = ++id;
    	}

    	for(int i = 0; i < vp.size(); i++) {
    		vp[i].first = mp[vp[i].first];
    		vp[i].second = mp[vp[i].second];
    	}

    	for(int i = 0; i < vp.size(); i++) {
    		int u = vp[i].first, v = vp[i].second;
    		graph[u].push_back(v);
    		graph[v].push_back(u);
    	}
    	while(1) {
    		for(int i = 0; i < N; i++) {
    			vis[i] = false;
    		}
    		int node, ttl; cin >> node >> ttl;
    		if(node == 0 && ttl == 0)
    			break;
    		cout << "Case " << ++cs << ": ";
    		int new_node = mp[node];
    		queue<int> q;
    		int dis[N];
    		for(int i = 0; i < N; i++) 
    			dis[i] = -1;
    		q.push(new_node); vis[new_node] = true; dis[new_node] = 0;
    		
    		while(!q.empty()) {
    		    int u = q.front();
    		    q.pop();
    		
    		    for(auto v: graph[u]) {
    		    	if(!vis[v]) {
    		    		q.push(v);
    		    		dis[v] = dis[u] + 1;
    		    		vis[v] = true;
    		    	}
    		    }
    		}

    		int ans = 0;
    		for(int i = 1; i <= s.size(); i++) {
    			if(dis[i] > ttl || dis[i] == -1)
    				ans++;
    		}
    		cout << ans  << " nodes not reachable from node " << node << " with TTL = " << ttl << ".\n";
    	}
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