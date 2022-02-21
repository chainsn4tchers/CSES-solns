#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
#define dMOD 1e9 + 7
#define dd double
#define LOG(x) cout << x << '\n'
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
    vector<int> price(n, 0);
    vector<int> pages(n, 0);
 
    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];
 
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
	
	for (int i = 0; i < n + 1; ++i)
		for (int j = 0; j < x + 1; ++j)
		{
			if (j == 0) dp[i][j] = 0;
			if (i == 0) dp[i][j] = 0;
		}
 
	for (int i = 1; i < n + 1; ++i)
		for (int j = 1; j < x + 1; ++j)
			if (price[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(pages[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
	LOG(dp[n][x]);		
	return 0;
}
