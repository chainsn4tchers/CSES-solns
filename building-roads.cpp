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
typedef map<int, vector<int>> edgeMap;
 
void dfs(int currnode, vector<bool>& vis, int& lastVisited, edgeMap& adj)
{
	vis[currnode] = true;
	lastVisited = currnode;
 
	for (auto& adjnode : adj[currnode]) {
		if (!vis[adjnode])
			dfs(adjnode, vis, lastVisited, adj);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, m, a, b;
	cin >> n >> m;
	edgeMap adj;
 
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	vector<bool> vis(n, false);
	vector<vector<int>> res;
	int lastVisited = -1;
 
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		if (lastVisited != -1)
			res.push_back(vector<int> {lastVisited, i});
		dfs(i, vis, lastVisited, adj);
	}
 
	log(sz(res));
	for (int i = 0; i < sz(res); ++i)
		cout << res[i][0] << ' ' << res[i][1] << '\n';
 
	return 0;
}
