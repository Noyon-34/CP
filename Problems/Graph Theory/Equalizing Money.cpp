// https://vjudge.net/problem/lightoj-1263
// Solved in 22.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
using ll = long long;

vector<int> money;
vector<int> graph[N];
bool vis[N];
int total_money, total_per;

void dfs(int u) {
	vis[u] = true;
	total_money += money[u - 1];
	total_per++;
	for(auto v: graph[u]) {
		if(!vis[v])
			dfs(v);
	}
}

void solve(int cs) {
	int n, m; cin >> n >> m;
	money.clear();
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
		graph[i].clear();
	}

	int sum = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		money.push_back(x);
		sum += x;
	}

	while(m--) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

    cout << "Case " << cs << ": ";
    if(sum % n != 0) {
    	cout << "No\n";
    	return;
    }

    set<int> s;
    for(int u = 1; u <= n; u++) {
    	if(!vis[u]) {
    		total_money = total_per = 0;
    		dfs(u);
    		if(total_money % total_per == 0) {
    			s.insert(total_money % total_per);
    		}
    		else {
    			cout << "No\n";
    			return;
    		}
    	}
    }

    if(s.size() == 1) {
    	cout << "Yes\n";
    	return;
    }
    cout << "No\n";  
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