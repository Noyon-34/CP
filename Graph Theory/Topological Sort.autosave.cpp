#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
int indeg[N];
bool vis[N];

void solve() {
    int n, m; cin >> n >> m;
    while(m--) {
    	int u, v; cin >> u >> v;
    	indeg[v]++;
    	graph[u].push_back(v);
    }

    vector<int> z;
    for(int i = 1; i <= n; i++) {
    	if(!indeg[i]) {
    		z.push_back(i);
    		vis[i] = true;
    	}
    }

    vector<int> ans;
    while(ans.size() < n) {
    	if(z.empty()) {
    		cout << "IMPOSSIBLE\n"
    	}
    	int cur = z.back();
    	z.pop_back();
    	ans.push_back(cur);
    	for(auto v: graph[cur]) {
    		indeg[v]--;
    		if(!indeg[v] and !vis[v]) {
    			z.push_back(v);
    			vis[v] = true;
    		}
    	}
    }

    for(int i = 0; i < n; i++) {
    	cout << ans[i] << ' ';
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