// https://vjudge.net/problem/lightoj-1174
// Solved in 06.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 107;
using ll = long long;

vector<int> graph[N];
bool vis[N];

auto bfs(int u, int n) {
	vector<int> dis(n + 1);
	queue<int> q;
	q.push(u); vis[u] = true, dis[u] = 0;
	
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
	return dis;
}
void solve(int cs) {
    int n, m; cin >> n >> m;
    while(m--) {
    	int u, v; cin >> u >> v;
    	u++, v++;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    int start, end; cin >> start >> end;
    start++, end++;

    auto short1 = bfs(start, n);
   	for(int i = 1; i <= n; i++) {
   		vis[i] = false;
   	}
    auto short2 = bfs(end, n);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
    	ans = max(ans, short1[i] + short2[i]);
    }

    cout << "Case " << cs << ": " << ans << '\n';

    for(int i = 1; i <= n; i++) {
    	vis[i] = false;
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