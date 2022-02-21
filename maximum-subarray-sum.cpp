/*--------------------------------------
  https://cses.fi/problemset/task/1643
----------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define vin(v) for (auto& x : v) cin >> x
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);
#define sz(x) (int)x.size()
#define log(x) cout << x << '\n'
 
typedef unsigned long long ull;
typedef long double         ld;
typedef long long           ll;
typedef double              dd;
 
const int MOD = 1000000007;
// const int MOD = 998244353;
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	ll n; cin >> n;
	vector<ll> v(n);
	vin(v);
 
	ll MAX = v[0];
	ll curr = v[0];
	for (ll i = 1; i < n; ++i)
	{
		curr = max(curr + v[i], v[i]);
		MAX = max(curr, MAX);
	}
	log(MAX);
}
