/*-------------------------------------------------------------
  (ﾉ´ヮ`)ﾉ*: ･ﾟ https://cses.fi/problemset/task/1193/
-------------------------------------------------------------*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl               '\n'
#define vin(v)             for (auto& x : v) cin >> x
#define arin(a, n)         for (int i = 0; i < n; ++i) cin >> a[i];
#define pb(x)              push_back(x);
#define mp(x, y)           make_pair(x, y);
#define all(x)             (x).begin(), (x).end()
#define rall(x)            (x).rbegin(), (x).rend()
#define sz(x)              (int)x.size()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define get(a)             int a; cin >> a;
#define get2(a, b)         int a, b; cin >> a >> b;
#define get3(a, b, c)      int a, b, c; cin >> a >> b >> c;
#define log(x)             cout << x << '\n'
#define logs(x)            cout << x << ' '
#define yy                 log("YES")
#define nn                 log("NO")

/* dbg setup by @Livw08: https://codeforces.com/blog/entry/68809 */
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/* --------------------setup end/begin main--------------------- */

typedef unsigned long long ull;
typedef long double         ld;
typedef long long           ll;
typedef double              dd;

const int MOD = 1000000007;
// const int MOD = 998244353;

// #define TESTCASE
char g[1001][1001];
bool vis[1001][1001];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void path(int er, int ec, vector<vector<pair<int, int>>>& par)
{
	string res;
	pair<int, int> parent;
	while (true) {
		parent = par[er][ec];
		if (parent.first == -1) break;
		if (parent.first - er == -1) res.push_back('D');
		else if (parent.first - er == 1) res.push_back('U');
		else if (parent.second - ec == 1) res.push_back('L');
		else if (parent.second - ec == -1) res.push_back('R');
		er = parent.first;
		ec = parent.second;
	}
	reverse(all(res));
	log(res);
}

void bfs(int sr, int sc, int R, int C)
{
	vector<vector<pair<int, int>>> parent(R, vector<pair<int, int>>(C, {-1, -1}));
	vis[sr][sc] = 1;
	queue<int> qr;
	queue<int> qc;
	qr.push(sr);
	qc.push(sc);
	bool found = 0;
	int moves = 0;
	int nodesLeft = 1;
	int nodesNext = 0;
	int er, ec;

	while (!qr.empty()) {
		int r = qr.front(); qr.pop();
		int c = qc.front(); qc.pop();
		if (g[r][c] == 'B') {
			found = true;
			er = r;
			ec = c;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || cc < 0 || rr >= R || cc >= C) continue;
			if (vis[rr][cc] || g[rr][cc] == '#') continue;

			++nodesNext;
			vis[rr][cc] = 1;
			parent[rr][cc].first = r;
			parent[rr][cc].second = c;
			qr.push(rr);
			qc.push(cc);
		}
		--nodesLeft;
		if (!nodesLeft) {
			++moves;
			nodesLeft = nodesNext;
			nodesNext = 0;
		}
	}

	if (found) {
		yy;
		log(moves);
		path(er, ec, parent);
	}
	else {
		nn;
	}
}

void tabsize_3(int tc = 1)
{
	debug(tc);

	memset(vis, 0, sizeof vis);
	int sr = 0, sc = 0;
	get2(R, C);

	rep(i, 0, R) {
		rep(j, 0, C) {
			cin >> g[i][j];
			if (g[i][j] == 'A') {
				sr = i;
				sc = j;
			}
		}
	}

	bfs(sr, sc, R, C);
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	auto start = std::chrono::high_resolution_clock::now();
	#ifdef TESTCASE
		int t; cin >> t;
		for (int i = 1; i <= t; ++i) tabsize_3(i);
	#else
		tabsize_3();
	#endif
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed_dbl = end - start;
	cerr << "Execution time (ms): " << elapsed_dbl.count() << "ms" << endl;
	cerr << fixed << showpoint << setprecision(9) << "Execution time (s): " << elapsed_dbl.count() / 1000.0 << "s" << endl;
	return 0;
}