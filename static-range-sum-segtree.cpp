/*-----------------------------------------------------------------------
⣿⣿⣿⣿⠛⠛⠉⠄⠁⠄⠄⠉⠛⢿⣧
⣿⣿⡟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣧
⣿⣿⡇⠄⠄⠄⠐⠄⠄⠄⠄⠄⠄⠄⠠⣿
⣿⣿⡇⠄⢀⡀⠠⠃⡐⡀⠠⣶⠄⠄⢀⣿
⣿⣿⣶⠄⠰⣤⣕⣿⣾⡇⠄⢛⠃⠄⢈⣿
⣿⣿⣿⡇⢀⣻⠟⣻⣿⡇⠄⠧⠄⢀⣾⣿
⣿⣿⣿⣟⢸⣻⣭⡙⢄⢀⠄⠄⠄⠈⢹⣿
⣿⣿⣿⣭⣿⣿⣿⣧⢸⠄⠄⠄⠄⠄⠈⢸
⣿⣿⣿⣼⣿⣿⣿⣽⠘⡄⠄⠄⠄⠄⢀⠸
⡿⣿⣳⣿⣿⣿⣿⣿⠄⠓⠦⠤⠤⠤⠼⢸  
⡹⣧⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⢇⣓⣾
⡞⣸⣿⣿⢏⣼⣶⣶⣶⣶⣤⣶⡤⠐⣿⣿
⣯⣽⣛⠅⣾⣿⣿⣿⣿⣿⡽⣿⣧⡸⢿⣿
⣿⣿⣿⡷⠹⠛⠉⠁⠄⠄⠄⠄⠄⠄⠐⠛⠻⣧
⣿⣿⣿⠃⠄⠄⠄⠄⠄⣠⣤⣤⣤⡄⢤⣤⣤⣤⡘⠻
⣿⣿⡟⠄⠄⣀⣤⣶⣿⣿⣿⣿⣿⣿⣆⢻⣿⣿⣿⡎⠝
⣿⡏⠄⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡎⣿⣿⣿⣿⠐
⣿⡏⣲⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢇⣿⣿⣿⡟
⣿⡠⠜⣿⣿⣿⣿⣟⡛⠿⠿⠿⠿⠟⠃⠾⠿⢟⡋⢶
-----------------------------------------------------------------------*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl               '\n'
#define vin(v)             for (auto& x : v) cin >> x
#define arin(a, n)         for (int i = 0; i < n; ++i) cin >> a[i]
#define pb(x)              push_back(x)
#define pii                pair<int, int>
#define all(x)             (x).begin(), (x).end()
#define rall(x)            (x).rbegin(), (x).rend()
#define sz(x)              (int)x.size()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define get(a)             int a; cin >> a
#define get2(a, b)         int a, b; cin >> a >> b
#define get3(a, b, c)      int a, b, c; cin >> a >> b >> c
#define get4(a, b, c, d)   int a, b, c, d; cin >> a >> b >> c >> d
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
struct segtree {
	int size;
	vector<pair<int, int>, ull> tree;

	int init(int lo, int hi, int idx, vector<ull>& a)
	{
		if (lo == hi) {
			return tree[idx] = a[lo];
		}
		int mid = lo + ((hi - lo) / 2);
		return tree[idx] = init(lo, mid, (2 * idx) + 1) + init(mid + 1, hi, (2 * idx) + 2);
	}

	void build(vector<ull>& a)
	{
		size = 0;
		int i = -1;
		while (size < n) {
			++i;
			size = (1 << i);
		}
		tree.assign(size, 0);
		init(0, sz(a) - 1, 0, a);
	}

	ull rangeSum(int l, int r)
	{

	}
};

void tabsize_3(int tc = 1)
{
	debug(tc);

	get2(n, q);
	vector<ull> a(n);
	vin(a);

	segtree tree;
	tree.build(a);
	while (q--) {
		get2(l, r);
	}
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