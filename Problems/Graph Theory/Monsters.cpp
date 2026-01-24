// https://cses.fi/problemset/task/1194
// Solved in 24.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7, inf = 1e9;
using ll = long long;

int n, m; 
vector<string> grid;
pair<int, int> par[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool can_go[N][N];

vector<vector<int>> bfs(vector<pair<int, int>> start_cells) {
    queue<pair<int, int>> q;
    vector<vector<int>> dis;

    dis.assign(n, vector<int> (m, inf));

    for(auto cell: start_cells) {
        q.push(cell);
        dis[cell.first][cell.second] = 0;
    }

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && dis[r][c] + 1 < dis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dis;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	string s; cin >> s;
    	grid.push_back(s);
    }

    pair<int, int> my_start;
    vector<pair<int, int>> monsters;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                my_start = make_pair(i, j);
            }
            else if(grid[i][j] == 'M') {
                monsters.push_back(make_pair(i, j));
            }
        }
    }

    vector<pair<int, int>> start;
    start.push_back(my_start);
    auto dis_frm_me = bfs(start);
    start = monsters;
    auto dis_frm_mon = bfs(start);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            can_go[i][j] = (dis_frm_me[i][j] < dis_frm_mon[i][j]) and (grid[i][j] != '#');
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dis;

    dis.assign(n, vector<int> (m, inf));

    q.push(my_start);
    dis[my_start.first][my_start.second] = 0;

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && can_go[nr][nc] && dis[r][c] + 1 < dis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + 1;
                par[nr][nc] = make_pair(r, c);
                q.push({nr, nc});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 or i == n - 1 or j == 0 or j == m - 1) {
                if(dis[i][j] != inf) {
                    cout << "YES\n";
                    cout << dis[i][j] << '\n';

                    vector<pair<int, int>> path;
                    auto cur = make_pair(i, j);
                    while(cur != my_start) {
                        path.push_back(cur);
                        cur = par[cur.first][cur.second];
                    }
                    path.push_back(my_start);
                    reverse(path.begin(), path.end());
                    for(int k = 0; k < path.size() - 1; k++) {
                        int dx = path[k].first - path[k + 1].first;
                        int dy = path[k].second - path[k + 1].second;

                        if(dx == 1) 
                            cout << 'U';
                        else if(dx == -1)
                            cout << 'D';
                        else if(dy == 1)
                            cout << 'L';
                        else
                            cout << 'R';
                    }
                    return;
                }
            }
        }
    }

    cout << "NO\n";
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