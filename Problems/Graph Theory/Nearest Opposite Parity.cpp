// https://codeforces.com/problemset/problem/1272/E
// Solved in 14.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7, mx = 1e9;
using ll = long long;

vector<int> graph[N];
int a[N], n, ans[N];

void bfs(vector<int> a, vector<int> b) {
	queue<int> q;
	vector<int> dis(n + 1, mx);

	for(auto it: a) {
		q.push(it);
		dis[it] = 0;
	}
	
	while(!q.empty()) {
	    int u = q.front();
	    q.pop();
	
	    for(auto v: graph[u]) {
	    	if(dis[u] + 1 < dis[v]) {
	    		dis[v] = dis[u] + 1;
	    		q.push(v);
	    	}
	    }
	}

	for(auto it: b) {
		ans[it] = dis[it];
	}
}
void solve() {
    cin >> n;
	vector<int> even, odd;

    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if(a[i] % 2)
    		odd.push_back(i);
    	else
    		even.push_back(i);
    }

    for(int i = 1; i <= n; i++) {
    	int j = i - a[i];
    	if(j >= 1)
    		graph[j].push_back(i);
    	j = i + a[i];
    	if(j <= n)
    		graph[j].push_back(i);
    }

   	bfs(even, odd);
   	bfs(odd, even);

   	for(int i = 1; i <= n; i++) {
		if(ans[i] == mx)
			cout << -1 << " ";
		else
   			cout << ans[i] << " ";
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