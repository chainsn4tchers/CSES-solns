#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define dd double
#define inf INT_MAX
#define mnf INT_MIN
#define vin(v) for (auto& x : v) cin >> x
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);
#define sz(x) (int)x.size()
#define log(x) cout << x << '\n'
#define logs(x) cout << x
 
const int MOD = 1000000007;
// const int MOD = 998244353;
 
void bfs(const vector<vector<char>>& g, int r, int c, vector<vector<int>>& vis)
{
	int R = sz(g);
	int C = sz(g[0]);
	vis[r][c] = 1;
	queue<int> qr, qc;
	qr.push(r);
	qc.push(c);
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};
 
	while (!qr.empty()) {
		r = qr.front(); qr.pop();
		c = qc.front(); qc.pop();
 
		for (int i = 0; i < 4; ++i) {
			int rr = r + dr[i];
			int cc = c + dc[i];
 
			if (rr < 0 || cc < 0) continue;
			if (rr >= R || cc >= C) continue;
			if (g[rr][cc] == '#' || vis[rr][cc]) continue;
 
			vis[rr][cc] = 1;
			qr.push(rr);
			qc.push(cc);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int R, C;
	cin >> R >> C;
	vector<vector<char>> g(R, vector<char>(C, ' '));
	vector<vector<int>> vis(R, vector<int>(C, 0));
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> g[i][j];
 
	int count = 0;
 
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (g[i][j] == '#' || vis[i][j]) continue;
			++count;
			bfs(g, i, j, vis);
		}
 
	log(count);
	return 0;
}
