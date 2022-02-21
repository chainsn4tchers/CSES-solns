#include <bits/stdc++.h>
using namespace std;
 
#define vin(v) for (auto& x : v) cin >> x
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);
#define sz(x) (int)x.size()
#define log(x) cout << x << '\n'
#define logs(x) cout << x
 
typedef unsigned long long ull;
typedef long long 				  ll;
typedef double 							dd;
 
const int MOD = 1000000007;
// const int MOD = 998244353;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	ll n;
	cin >> n;
	vector<ll> a(n, 0);
	vin(a);
 
	ll c = 0;
	for (ll i = 1; i < n; ++i) {
		if (a[i] >= a[i - 1]) continue;
		c += a[i - 1] - a[i];
		a[i] = a[i - 1];
	}
 
	log(c);
	return 0;
}
