#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF INT_MAX
#define mINF INT_MIN
#define vin(v) for (auto& x : v) cin >> x
#define dd double
#define LOG(x) cout << x << '\n'
 
const int MOD = 1000000007;
// const int MOD =  998244353;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
    int n, x; cin >> n >> x;
    vector<int> a(n, 0);
    vin(a);
 
    int dp[x + 1];
    for (int i = 0; i < x + 1; ++i) dp[i] = 0;
    dp[0] = 1;
	
	for (int j = 1; j < x + 1; ++j)
		for (int i = 0; i < n; ++i)
			if (a[i] <= j)
				(dp[j] += dp[j - a[i]]) %= MOD;
 
	LOG(dp[x]);
	return 0;
}
