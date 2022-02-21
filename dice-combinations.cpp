#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define LOG(x) cout << x << '\n'
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i && j <= 6; ++j)
			(dp[i] += dp[i - j]) %= MOD;
 
	LOG(dp[n]);
}
