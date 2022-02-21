/*--------------------------------------
  https://cses.fi/problemset/task/1693
--------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define vin(v) for (auto& x : v) cin >> x
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);
#define sz(x) (int)x.size()
#define log(x) cout << x << '\n'
 
template<typename T>
void print(vector<T>& v) { cout << "--DBG--\n"; for (auto& x : v) cout << x << ' '; cout << "--DBG--\n"; }
 
typedef unsigned long long ull;
typedef long double         ld;
typedef long long           ll;
typedef double              dd;
 
const int MOD = 1000000007;
// const int MOD = 998244353;
 
// #define TESTCASE
void solve()
{
}
 
typedef map<int, vector<int>> edgeMap;
bool isEulerian(int n, const vector<int>& in, const vector<int>& out)
{
	int start = 0, end = 0, c = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (abs(in[i] - out[i]) > 2) return false;
		if (out[i] - in[i] == 1)
		{
			start = i;
			++c;
		}
		else if (in[i] - out[i] == 1)
		{
			end = i;
			++c;
		}
	}
	if (c == 2) return true;
	return false;
}
 
void dfs(int currNode, int end, bool& found, vector<int>& out, stack<int>& path, edgeMap& list)
{
	if (currNode == end) found = true;
	if (!out[currNode])
	{
		path.push(currNode);
		return;
	}
	while (out[currNode])
	{
		int t = list[currNode][--out[currNode]];
		dfs(t, end, found, out, path, list);
	}
	path.push(currNode);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#ifdef TESTCASE
		int t; cin >> t; while (t--) solve();
	#endif
 
	int n, m; cin >> n >> m;
	edgeMap list; // digraph
	vector<int> out(n + 1, 0);
	vector<int> in(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		list[a].push_back(b);
		++out[a];
		++in[b];
	}
 
	auto ok = isEulerian(n, in, out);
	if (!ok)
		log("IMPOSSIBLE");
	else
	{
		bool found = false;
		stack<int> path;
		dfs(1, n, found, out, path, list);
		vector<int> res;
		if (found && sz(path) == m + 1)
		{
			while (!path.empty())
			{
				cout << path.top() << ' ';
				path.pop();
			}
		}
		else
			log("IMPOSSIBLE");
	}
	return 0;
}
