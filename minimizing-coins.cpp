#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define LOG(x) cout << x << '\n'
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, x;
	cin >> n >> x;
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) cin >> a[i];
 
	int dp[x + 1];
	for (int i = 0; i < x + 1; ++i) dp[i] = INT_MAX;
	dp[0] = 0;
 
	for (int j = 1; j < x + 1; ++j)
	{
		for (int i = 0; i < n; ++i)
			if (a[i] <= j)
				dp[j] = std::min(dp[j - a[i]], dp[j]);
 
		if (dp[j] != INT_MAX)
			dp[j] += 1;
	}
	if (dp[x] == INT_MAX) LOG(-1);
	else LOG(dp[x]);
	return 0;
}
