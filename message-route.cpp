#include <bits/stdc++.h>
using namespace std;
 
#define vin(v) for (auto& x : v) cin >> x
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);
#define sz(x) (int)x.size()
#define log(x) cout << x << '\n'
 
typedef unsigned long long ull;
typedef long long           ll;
typedef double              dd;
 
const int MOD = 1000000007;
// const int MOD = 998244353;
typedef map<int, vector<int>> edgeMap;
 
void reconstructPath(vector<int>& parent, int n)
{
	vector<int> path{n};
 
	for (int child = parent[n]; child != -1; child = parent[child])
		path.push_back(child);
 
	log(sz(path));
	for (int i = sz(path) - 1; i >= 0; --i)
		cout << path[i] << ' ';
}
 
pair<bool, vector<int>> bfs(int start, int n, vector<bool>& vis, edgeMap& adjList)
{
	vis[start] = true;
	queue<int> q;
	q.push(start);
	vector<int> parent(n + 1, -1);
	parent[1] = -1;
	pair<bool, vector<int>> p{false, {}};
 
	while (!q.empty()) {
		int currNode = q.front(); q.pop();
 
		if (currNode == n) {
			p.first = true;
			p.second = parent;
			break;
		}
 
		for (auto& adjNode : adjList[currNode])
			if (!vis[adjNode]) {
				q.push(adjNode);
				vis[adjNode] = true;
				parent[adjNode] = currNode;
			}
	}
	return p;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, m, i, j;
	cin >> n >> m;
	edgeMap adjList;
	vector<bool> vis(n + 1, false);
 
	for (int k = 0; k < m; ++k) {
		cin >> i >> j;
		adjList[i].push_back(j);
		adjList[j].push_back(i);
	}
 
	pair<bool, vector<int>> p = bfs(1, n, vis, adjList);
	if (p.first)
		reconstructPath(p.second, n);
	else
		log("IMPOSSIBLE");
 
	return 0;
}
