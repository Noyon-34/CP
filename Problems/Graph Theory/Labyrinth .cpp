// https://cses.fi/problemset/task/1193
// Solved in 19.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
	int n, m;
    cin >> n >> m;
    vector<string> grid;

    for(int i = 0; i < n; i++) {
    	string s; cin >> s;
    	grid.push_back(s);
    }

    int x, y, l, k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                x = i, y = j;
            }
            else if(grid[i][j] == 'B') {
                l = i, k = j;
            }
        }
    }

    pair<int, int> src = {x, y};

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int R = n, C = m, ans = 0;

    queue<pair<int, int>> q;
    vector<vector<int>> dis;
    vector<vector<char>> s;

    dis.assign(R, vector<int> (C, -1));
    s.assign(R, vector<char> (C, '#'));

    q.push(src);
    dis[x][y] = 0;

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if(grid[r][c] == 'B') {
            break;
        }
        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < R && nc >= 0 && nc < C && (grid[nr][nc] == '.' || grid[nr][nc] == 'B') && dis[nr][nc] == -1) {
                dis[nr][nc] = dis[r][c] + 1;
                if(dx[i] == -1)
                    s[nr][nc] = 'U';
                else if(dx[i] == 1)
                    s[nr][nc] = 'D';
                else if(dy[i] == 1)
                    s[nr][nc] = 'R';
                else
                    s[nr][nc] = 'L';
                q.push({nr, nc});
            }
        }
    }

    if(dis[l][k] == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << dis[l][k] << '\n';

    string path =  "";
    while(!(l == x && k == y)) {
        char ch = s[l][k];
        path += ch;

        if(ch == 'U')
            l++;
        else if(ch == 'D')
            l--;
        else if(ch == 'L')
            k++;
        else
            k--;
    }

    reverse(path.begin(), path.end());
    cout << path;
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