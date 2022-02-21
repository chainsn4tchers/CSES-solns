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
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n; cin >> n;
	if (n == 2 || n == 3) {
		log("NO SOLUTION");
		return 0;
	}
	for (int i = 2; i <= n; i += 2)
		cout << i << ' ';
	for (int i = 1; i <= n; i += 2)
		cout << i << ' ';
	return 0;
}
