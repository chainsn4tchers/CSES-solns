#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
#define dd double
#define LOG(x) cout << x << '\n'
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	ll n, x;
	cin >> n >> x;
	vector<ll> c(n, 0);
 
	for (ll i = 0; i < n; ++i)
		cin >> c[i];
 
	int dp[n + 1][x + 1];
	for (int i = 0; i < n + 1; ++i)
		for (int j = 0; j < x + 1; ++j)
		{
			if (j == 0) dp[i][j] = 1;
			if (i == 0) dp[i][j] = 0;
		}
	dp[0][0] = 1;
 
	for (int i = 1; i < n + 1; ++i)
		for (int j = 1; j < x + 1; ++j)
		{
			if (c[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				(dp[i][j] = dp[i][j - c[i - 1]] + dp[i - 1][j]) %= MOD;
		}
	LOG(dp[n][x]);
}
